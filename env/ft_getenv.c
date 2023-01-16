/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 23:50:00 by jeounpar          #+#    #+#             */
/*   Updated: 2023/01/17 00:32:15 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
