/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:41:10 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:41:16 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_tokenize_io_red_merge_l(t_parse_token *tok_lst)
{
	t_parse_token	*tok;
	char			*str;

	while (tok_lst != NULL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_IO_L && tok_lst->next
			&& tok_lst->next->token_type == TYPE_TOKEN_IO_L)
		{
			str = ft_p_strdup("<<");
			if (str == NULL)
				return ;
			tok = tok_lst->next;
			tok_lst->next = tok_lst->next->next;
			free(tok_lst->string);
			tok_lst->string = str;
			tok_lst->token_type = TYPE_TOKEN_IO_LL;
			free_single_t_parse_token(tok);
		}
		tok_lst = tok_lst->next;
	}
}

void	parse_tokenize_io_red_merge_r(t_parse_token *tok_lst)
{
	t_parse_token	*tok;
	char			*str;

	while (tok_lst != NULL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_IO_R && tok_lst->next
			&& tok_lst->next->token_type == TYPE_TOKEN_IO_R)
		{
			str = ft_p_strdup(">>");
			if (str == NULL)
				return ;
			tok = tok_lst->next;
			tok_lst->next = tok_lst->next->next;
			free(tok_lst->string);
			tok_lst->string = str;
			tok_lst->token_type = TYPE_TOKEN_IO_RR;
			free_single_t_parse_token(tok);
		}
		tok_lst = tok_lst->next;
	}
}

void	parse_tokenize_io_red_sub(t_parse_token *tok)
{
	char			**sep;
	int				type;
	int				index;
	t_parse_token	*ret;

	sep = ft_p_strsep_custom_io(tok->string, '>', '<');
	index = -1;
	if (sep == NULL || sep[0] == NULL)
		return ;
	type = tok->token_type;
	cleanse_single_t_parse_token(tok);
	ret = tok;
	while (sep[++index] != NULL && tok != NULL && ret != NULL)
	{
		if (sep[index][0] == '>')
			ret = add_token(&tok, 1, TYPE_TOKEN_IO_R, sep[index]);
		else if (sep[index][0] == '<')
			ret = add_token(&tok, 1, TYPE_TOKEN_IO_L, sep[index]);
		else
			ret = add_token(&tok, 1, type, sep[index]);
		tok = tok->next;
	}
	parse_safe_free_two_d_char(sep, -1);
}

void	redirection(t_parse_token *tok_lst)
{
	t_parse_token	*next_tok;
	t_parse_token	*preserve;

	preserve = tok_lst;
	while (tok_lst != NULL)
	{
		next_tok = tok_lst->next;
		if (tok_lst->token_type == TYPE_TOKEN_CHUNK)
		{
			parse_tokenize_io_red_sub(tok_lst);
		}
		tok_lst = next_tok;
	}
	eliminate_empty_loaf(preserve);
	parse_tokenize_io_red_merge_r(preserve);
	parse_tokenize_io_red_merge_l(preserve);
}
