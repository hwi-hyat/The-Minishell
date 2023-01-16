/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_token_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:08:19 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:08:20 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_t_parse_token_list(t_parse_token *token_list)
{
	t_parse_token	*next;

	next = token_list;
	while (next != NULL)
	{
		if (next->string != NULL)
			free (next->string);
		if (next->original_str != NULL)
			free (next->original_str);
		token_list = next;
		next = next->next;
		free (token_list);
	}
}

void	free_single_t_parse_token(t_parse_token *token_list)
{
	if (token_list == NULL)
		return ;
	if (token_list->string != NULL)
		free (token_list->string);
	if (token_list->original_str != NULL)
		free (token_list->original_str);
	free(token_list);
}

void	cleanse_single_t_parse_token(t_parse_token *token)
{
	char	*str;

	if (token == NULL)
		return ;
	str = ft_p_strdup("");
	if (str == NULL)
		return ;
	if (token->string != NULL)
		free (token->string);
	if (token->original_str != NULL)
		free (token->original_str);
	token->string = str;
	token->token_type = TYPE_TOKEN_CHUNK;
}
