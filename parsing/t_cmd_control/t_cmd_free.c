/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:47:46 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/15 16:20:33 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/command_parse.h"

void	free_t_cmd_redirection(t_cmd *cmd);

void	free_first_t_cmd_node(t_cmd_list *cmd_list)
{
	t_cmd	*node;
	int		index;

	if (cmd_list == NULL || cmd_list->cmd_list == NULL)
		return ;
	node = cmd_list->cmd_list;
	cmd_list->cmd_list = cmd_list->cmd_list->next;
	if (cmd_list->cmd_list != NULL)
		cmd_list->cmd_list->prev = NULL;
	if (cmd_list->cmd_list == NULL)
		cmd_list->cmd_list_tail = NULL;
	free_t_cmd_redirection(node);
	if (node->exec_file_name != NULL)
		free (node->exec_file_name);
	index = -1;
	while (node->argv != NULL && (node->argv)[++index])
		free((node->argv)[index]);
	if (node->argv != NULL)
		free (node->argv);
	free (node);
}

void	free_t_cmd_redirection(t_cmd *cmd)
{
	t_cmd_redirection	*cmd_red_prev;

	while (cmd->redirection_list != NULL)
	{
		if (cmd->redirection_list->file != NULL)
			free(cmd->redirection_list->file);
		cmd_red_prev = cmd->redirection_list;
		free (cmd_red_prev);
		cmd->redirection_list = cmd->redirection_list->next;
	}
}

void	*free_t_cmd_list(t_cmd_list *cmd_list)
{
	if (cmd_list == NULL)
		return (NULL);
	while (cmd_list->cmd_list != NULL)
		free_first_t_cmd_node(cmd_list);
	free (cmd_list);
	return (NULL);
}
