/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokenize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:49:36 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/16 15:52:10 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"

void	parse_tokenize_annihilate_initial_empty_chunk(t_parse_token **tok_lst);
void	parse_tokenize_change_chunk_to_argv(t_parse_token *tok_lst);

t_parse_token	*parse_tokenize(char *cmd_string)
{
	t_parse_token	*ret;

	ret = create_empty_t_parse_token();
	if (ret == NULL)
		return (NULL);
	ret->token_type = TYPE_TOKEN_CHUNK;
	ret->string = cmd_string;
	parse_tokenize_handle_quotaion(ret);
	parse_env_from_token_list(ret);
	parse_tokenize_space(ret);
	parse_tokenize_pipeline(ret);
	parse_tokenize_io_red(ret);
	parse_tokenize_annihilate_empty_chunk(ret);
	parse_tokenize_annihilate_initial_empty_chunk(&ret);
	parse_tokenize_change_chunk_to_argv(ret);
	parse_tokenize_merge_argv(ret);
	parse_tokenize_annihilate_space_token(&ret);
	parse_check_syntax_err(ret);
	return (ret);
}

void	parse_tokenize_annihilate_empty_chunk(t_parse_token *tok_lst)
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

void	parse_tokenize_annihilate_initial_empty_chunk(t_parse_token **tok_lst)
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

void	parse_tokenize_change_chunk_to_argv(t_parse_token *tok_lst)
{
	while (tok_lst != NULL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_CHUNK)
			tok_lst->token_type = TYPE_TOKEN_ARGV;
		tok_lst = tok_lst->next;
	}
}
