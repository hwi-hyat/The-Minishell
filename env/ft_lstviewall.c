/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstviewall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:05:33 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:05:33 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
