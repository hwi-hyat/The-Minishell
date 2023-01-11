/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:36:31 by park              #+#    #+#             */
/*   Updated: 2022/07/20 23:53:33 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linkedlist.h"

void	ft_lstadd(t_list *lists, char *key, char *value)
{
	t_env	*new;

	new = ft_lstnew(key, value);
	new->prev = lists->tail->prev;
	new->next = lists->tail;
	lists->tail->prev->next = new;
	lists->tail->prev = new;
}
