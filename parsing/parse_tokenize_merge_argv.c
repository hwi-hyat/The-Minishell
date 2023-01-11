/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize_merge_argv.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:30:13 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/17 12:04:41 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"

void	parse_tokenize_merge_argv_handle_env_null(t_parse_token *tok_lst);

void	parse_tokenize_merge_argv(t_parse_token *tok_lst)
{
	t_parse_token	*tok;
	char			*str;

	while (tok_lst != NULL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_ARGV && tok_lst->next
			&& tok_lst->next->token_type == TYPE_TOKEN_ARGV)
		{
			tok = tok_lst->next;
			parse_tokenize_merge_argv_handle_env_null(tok_lst);
			str = ft_p_strjoin(tok_lst->string, tok->string);
			if (str == NULL)
				return ;
			tok_lst->next = tok_lst->next->next;
			free(tok_lst->string);
			tok_lst->string = str;
			free_single_t_parse_token(tok);
		}
		else
			tok_lst = tok_lst->next;
	}
}

void	parse_tokenize_merge_argv_handle_env_null(t_parse_token *tok_lst)
{
	char	*str;

	if (tok_lst->next->is_null != TYPE_ARGV_NULL)
		tok_lst->is_null = TYPE_INITIAL_STATUS;
	str = NULL;
	if (tok_lst->original_str != NULL && tok_lst->next->original_str != NULL)
		str = ft_p_strjoin(tok_lst->original_str, tok_lst->next->original_str);
	else if (tok_lst->original_str != NULL
		&& tok_lst->next->original_str == NULL)
		str = ft_p_strjoin(tok_lst->original_str, tok_lst->next->string);
	else if (tok_lst->original_str == NULL
		&& tok_lst->next->original_str != NULL)
		str = ft_p_strjoin(tok_lst->string, tok_lst->next->original_str);
	if (str == NULL)
		return ;
	free(tok_lst->original_str);
	tok_lst->original_str = str;
}
