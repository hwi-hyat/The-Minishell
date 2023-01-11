/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:34:45 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/21 20:48:04 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linkedlist.h"

void	free_env(t_list	*list)
{
	t_env	*curr;
	t_env	*tmp;

	curr = list->head->next;
	while (curr != list->tail)
	{
		tmp = curr->next;
		free(curr->key);
		free(curr->value);
		free(curr);
		curr = tmp;
	}
}
