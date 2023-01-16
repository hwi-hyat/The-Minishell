/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:07:57 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:07:57 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../minishell.h"

t_cmd	*get_empty_t_cmd(void)
{
	t_cmd	*ret;
	char	**argv;

	ret = (t_cmd *)malloc(sizeof(t_cmd));
	if (ret == NULL)
		return (NULL);
	argv = (char **)malloc(sizeof(char *));
	if (argv == NULL)
	{
		free(ret);
		return (NULL);
	}
	argv[0] = NULL;
	ret->exec_file_name = NULL;
	ret->argv = argv;
	ret->prev = NULL;
	ret->next = NULL;
	ret->redirection_list = NULL;
	ret->fds[0] = -1;
	ret->fds[1] = -1;
	return (ret);
}

t_cmd	*add_empty_t_cmd_to_list(t_cmd_list *cmd)
{
	t_cmd	*new_node;
	t_cmd	*prev_node;

	if (cmd == NULL)
		return (NULL);
	new_node = get_empty_t_cmd();
	if (new_node == NULL)
		return (NULL);
	if (cmd->cmd_list == NULL)
	{
		cmd->cmd_list = new_node;
		new_node->prev = NULL;
		return (new_node);
	}
	prev_node = cmd->cmd_list;
	while (prev_node -> next != NULL)
		prev_node = prev_node->next;
	prev_node->next = new_node;
	new_node->prev = prev_node;
	cmd->cmd_list_tail = new_node;
	return (new_node);
}

t_cmd_list	*create_empty_t_cmd_list(void)
{
	t_cmd_list	*ret;

	ret = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	if (ret == NULL)
		return (NULL);
	ret->cmd_list = NULL;
	ret->cmd_list_tail = NULL;
	ret->status = TYPE_INITIAL_STATUS;
	return (ret);
}

t_cmd_redirection	*add_cmd_redirection(t_cmd *cmd, int red_type, char *file)
{
	t_cmd_redirection	*ret;
	t_cmd_redirection	*prev;
	char				*str;

	ret = (t_cmd_redirection *)malloc(sizeof(t_cmd_redirection));
	str = ft_p_strdup(file);
	if (ret == NULL || str == NULL)
		return (parse_safe_free_multi_str(ret, str, NULL, NULL));
	ret->red_type = red_type;
	ret->file = str;
	ret->next = NULL;
	if (cmd->redirection_list == NULL)
		cmd->redirection_list = ret;
	else
	{
		prev = cmd->redirection_list;
		while (prev->next != NULL)
			prev = prev->next;
		prev->next = ret;
	}
	return (ret);
}
