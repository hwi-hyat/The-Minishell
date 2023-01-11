/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize_annihilate_space.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:30:50 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/17 12:04:41 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"

void	parse_tokenize_annihilate_space_token_sub(t_parse_token *tok_lst);

void	parse_tokenize_annihilate_space_token(t_parse_token **tok_lst)
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
