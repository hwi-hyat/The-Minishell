/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 00:49:43 by park              #+#    #+#             */
/*   Updated: 2022/07/20 23:51:35 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linkedlist.h"

void	ft_initlist(t_list *list)
{
	list->head = ft_lstnew("", "");
	list->tail = ft_lstnew("", "");
	list->head->next = list->tail;
	list->tail->prev = list->head;
}
