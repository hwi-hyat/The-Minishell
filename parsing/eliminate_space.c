/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize_annihilate_space.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:09:24 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:38:08 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_tokenize_annihilate_space_token_sub(t_parse_token *tok_lst)
{
	t_parse_token	*tok;
	t_parse_token	*prev;

	if (tok_lst == NULL)
		return ;
	prev = tok_lst;
	tok = tok_lst->next;
	while (tok != NULL)
	{
		if (tok->token_type == TYPE_TOKEN_SPACE)
		{
			prev->next = tok->next;
			free_single_t_parse_token(tok);
			tok = prev;
		}
		prev = tok;
		tok = tok->next;
	}
}

void	eliminate_space(t_parse_token **tok_lst)
{
	t_parse_token	*tok;
	char			*str;

	if (tok_lst == NULL || *tok_lst == NULL)
		return ;
	tok = (*tok_lst);
	while (tok->next != NULL && tok->token_type == TYPE_TOKEN_SPACE)
	{
		(*tok_lst) = tok->next;
		free_single_t_parse_token(tok);
		tok = (*tok_lst);
	}
	if (tok->token_type == TYPE_TOKEN_SPACE)
	{
		str = ft_p_strdup("");
		if (str == NULL)
			return ;
		free(tok->string);
		tok->string = str;
		tok->token_type = TYPE_TOKEN_ARGV;
		return ;
	}
	parse_tokenize_annihilate_space_token_sub(tok);
}
