/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:06:27 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/20 23:54:50 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linkedlist.h"

int	ft_is_in_env(t_list	*list, char *key)
{
	t_env	*curr;

	curr = list->head->next;
	while (curr != list->tail)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (1);
		curr = curr->next;
	}
	return (0);
}
