/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 02:48:43 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:45:44 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_parse_token	*parse_assemble_tokens_to_t_cmd_list_sub(
		t_parse_token *tok_lst, t_cmd **cmd, t_cmd_list *ret, int *counter)
{
	if (tok_lst->token_type == TYPE_TOKEN_PIPELINE)
	{
		(*cmd) = add_empty_t_cmd_to_list(ret);
		if ((*cmd) == NULL)
			return (free_t_cmd_list(ret));
		(*counter) = -1;
	}
	if (tok_lst->token_type == TYPE_TOKEN_ARGV
		&& (++(*counter) == 0 || tok_lst->is_null != TYPE_ARGV_NULL))
		parse_t_cmd_add_argv((*cmd), tok_lst->string, (*counter));
	if (tok_lst->token_type >= TYPE_TOKEN_IO_R
		&& tok_lst->token_type <= TYPE_TOKEN_IO_LL)
	{
		if (tok_lst->token_type == TYPE_TOKEN_IO_LL
			&& tok_lst->next->original_str != NULL)
			add_cmd_redirection((*cmd), tok_lst->token_type,
				tok_lst->next->original_str);
		else
			add_cmd_redirection((*cmd), tok_lst->token_type,
				tok_lst->next->string);
		tok_lst = tok_lst->next;
	}
	tok_lst = tok_lst->next;
	return (tok_lst);
}

t_cmd_list	*parse_assemble_tokens_to_t_cmd_list(t_parse_token *tok_lst)
{
	t_cmd_list	*ret;
	t_cmd		*cmd;
	int			counter;

	ret = create_empty_t_cmd_list();
	if (ret == NULL)
		return (NULL);
	cmd = add_empty_t_cmd_to_list(ret);
	if (cmd == NULL)
		return (free_t_cmd_list(ret));
	counter = -1;
	while (tok_lst != NULL)
		tok_lst = parse_assemble_tokens_to_t_cmd_list_sub(
				tok_lst, &cmd, ret, &counter);
	return (ret);
}
