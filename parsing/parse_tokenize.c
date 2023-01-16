/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:56:54 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:45:49 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	eliminate_empty_loaf(t_parse_token *tok_lst)
{
	t_parse_token	*tok;
	t_parse_token	*prev;

	if (tok_lst == NULL)
		return ;
	prev = tok_lst;
	tok = tok_lst->next;
	while (tok != NULL)
	{
		if (tok->token_type == TYPE_TOKEN_CHUNK && tok->string[0] == '\0')
		{
			prev->next = tok->next;
			free_single_t_parse_token(tok);
			tok = prev;
		}
		prev = tok;
		tok = tok->next;
	}
}

void	eliminate_empty_first_loaf(t_parse_token **tok_lst)
{
	t_parse_token	*tok;

	if ((*tok_lst)->string[0] == '\0'
		&& (*tok_lst)->token_type == TYPE_TOKEN_CHUNK)
	{
		if ((*tok_lst)->next == NULL)
		{
			(*tok_lst)->token_type = TYPE_TOKEN_ARGV;
			return ;
		}
		tok = (*tok_lst)->next;
		free_single_t_parse_token(*tok_lst);
		*tok_lst = tok;
	}
}

void	rest_argv(t_parse_token *tok_lst)
{
	while (tok_lst != NULL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_CHUNK)
			tok_lst->token_type = TYPE_TOKEN_ARGV;
		tok_lst = tok_lst->next;
	}
}

t_parse_token	*parse_tokenize(char *str)
{
	t_parse_token	*ret;

	ret = create_empty_t_parse_token();
	if (ret == NULL)
		return (NULL);
	ret->token_type = TYPE_TOKEN_CHUNK;
	ret->string = str;
	quotation(ret);
	env_from_tok(ret);
	space(ret);
	pipeline(ret);
	redirection(ret);
	eliminate_empty_loaf(ret);
	eliminate_empty_first_loaf(&ret);
	rest_argv(ret);
	collect_argv(ret);
	eliminate_space(&ret);
	check_syntax(ret);
	return (ret);
}
