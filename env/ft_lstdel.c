/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:37 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:04:37 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lstdelone(t_list *list, char *key)
{
	t_env	*curr;

	curr = list->head->next;
	while (curr != list->tail)
	{
		if (ft_strcmp(curr->key, key) == 0)
		{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			free(curr->key);
			free(curr->value);
			free(curr);
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}
