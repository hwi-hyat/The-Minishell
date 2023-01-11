/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:54:00 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/15 00:30:40 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/command_parse.h"

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
