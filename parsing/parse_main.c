/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:17:27 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:32:15 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd_list	*parse(char *str)
{
	t_cmd_list		*ret;
	t_parse_token	*tokens;

	tokens = parse_tokenize(str);
	if (tokens == NULL)
		return (NULL);
	if (tokens->token_type == TYPE_SYNTAX_ERR
		|| tokens->token_type == TYPE_AMBIGUOUS_ERR)
		return (handle_syntax_err_tok(tokens));
	ret = parse_assemble_tokens_to_t_cmd_list(tokens);
	free_t_parse_token_list(tokens);
	return (ret);
}
