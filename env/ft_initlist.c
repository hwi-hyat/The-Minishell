/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 00:49:43 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:57:03 by siykim           ###   ########.fr       */
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
