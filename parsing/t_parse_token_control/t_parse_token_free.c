/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_parse_token_free.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:12:59 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/17 12:04:41 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/command_parse.h"

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
