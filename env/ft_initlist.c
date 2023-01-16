/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:23 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:04:23 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_initlist(t_list *list)
{
	list->head = ft_lstnew("", "");
	list->tail = ft_lstnew("", "");
	list->head->next = list->tail;
	list->tail->prev = list->head;
}
