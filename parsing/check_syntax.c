/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:00:27 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 15:46:47 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parse_check_syntax_err_set_err(t_parse_token *tok_lst,
		t_parse_token *err, t_parse_token *prev)
{
	char	*str;

	str = tok_lst->string;
	if ((err->token_type == TYPE_TOKEN_PIPELINE)
		&& ((err->next != NULL && err->next->token_type == TYPE_TOKEN_PIPELINE)
			|| prev == NULL))
	{
		tok_lst->token_type = TYPE_SYNTAX_ERR;
		tok_lst->string = err->string;
		err->string = str;
		return (0);
	}
	tok_lst->token_type = TYPE_SYNTAX_ERR;
	if (err->next == NULL)
	{
		str = ft_p_strdup("newline");
		if (str == NULL)
			return (0);
		free(tok_lst->string);
		tok_lst->string = str;
		return (0);
	}
	tok_lst->string = err->next->string;
	err->next->string = str;
	return (0);
}

int	parse_check_syntax_err_set_ambig(t_parse_token *tok_lst,
		t_parse_token *err)
{
	char	*str;

	tok_lst->token_type = TYPE_AMBIGUOUS_ERR;
	str = ft_p_strdup(err->next->original_str);
	if (str == NULL)
		return (0);
	free(tok_lst->string);
	tok_lst->string = str;
	return (0);
}

int	check_syntax(t_parse_token *tok_lst)
{
	t_parse_token	*tok;
	t_parse_token	*prev;

	prev = NULL;
	tok = tok_lst;
	while (tok != NULL)
	{
		if (tok->token_type == TYPE_TOKEN_PIPELINE && (prev == NULL
				|| tok->next == NULL || prev->token_type != TYPE_TOKEN_ARGV
				|| tok->next->token_type == TYPE_TOKEN_PIPELINE))
			return (parse_check_syntax_err_set_err(tok_lst, tok, prev));
		if (tok->token_type >= TYPE_TOKEN_IO_R
			&& tok->token_type <= TYPE_TOKEN_IO_LL
			&& (tok->next == NULL || tok->next->token_type != TYPE_TOKEN_ARGV))
			return (parse_check_syntax_err_set_err(tok_lst, tok, prev));
		if (tok->token_type >= TYPE_TOKEN_IO_R
			&& tok->token_type <= TYPE_TOKEN_IO_L
			&& (tok->next != NULL && tok->next->is_null == TYPE_ARGV_NULL))
			return (parse_check_syntax_err_set_ambig(tok_lst, tok));
		prev = tok;
		tok = tok->next;
	}
	return (1);
}
