/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstviewall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 01:08:29 by park              #+#    #+#             */
/*   Updated: 2022/07/20 23:54:02 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linkedlist.h"
#include <stdio.h>

void	ft_viewall(t_list *list)
{
	t_env	*curr;

	curr = list->head->next;
	while (curr != list->tail)
	{
		printf("%s=%s\n", curr->key, curr->value);
		curr = curr->next;
	}
}
