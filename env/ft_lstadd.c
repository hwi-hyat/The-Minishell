/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:04:32 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:04:32 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd(t_list *lists, char *key, char *value)
{
	t_env	*new;

	new = ft_lstnew(key, value);
	new->prev = lists->tail->prev;
	new->next = lists->tail;
	lists->tail->prev->next = new;
	lists->tail->prev = new;
}
