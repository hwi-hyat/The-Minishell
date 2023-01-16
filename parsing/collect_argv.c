/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:56:46 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:55:39 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	collect_argv(t_parse_token *tok_lst)
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
