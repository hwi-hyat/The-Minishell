/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:50:00 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/21 01:03:02 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"

char	*ft_getenv(char *key)
{
	t_env	*curr;
	t_list	*list;

	list = &(g_state.list);
	curr = list->head->next;
	while (curr != list->tail)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (curr->value);
		curr = curr->next;
	}
	return (NULL);
}
