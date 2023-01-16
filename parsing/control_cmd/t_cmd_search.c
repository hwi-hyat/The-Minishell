/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:08:06 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:08:06 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*get_last_node(t_cmd *cmd_list)
{
	t_cmd	*ret;

	if (cmd_list == NULL)
		return (NULL);
	ret = cmd_list;
	while (ret->next != NULL)
		ret = ret->next;
	return (ret);
}
