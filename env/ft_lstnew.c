/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:16:37 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:57:03 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lstnew(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (new_node == NULL)
		return (NULL);
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
