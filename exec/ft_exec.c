/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 02:31:29 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/23 12:08:36 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int		ft_redirection(t_cmd *cmd);
void	close_fd(t_cmd *cmd, int *stin, int *stout);
void	exec_cmd(t_cmd *cmd, char **env);
void	set_type(t_cmd_list *lists);
void	free_env_list(char **env_list);
char	**get_env_list(t_list *list);

static int	check_null(t_cmd *cmd)
{
	if (cmd->argv[0] == NULL)
	{
		cmd = cmd->next;
		return (1);
	}
	if (cmd->argv[0][0] == '\0')
	{
		cmd = cmd->next;
		return (1);
	}
	return (0);
}

static int	ft_exec_helper2(int arr[4], t_cmd *cmd)
{
	if (ft_redirection(cmd) == 1)
		return (1);
	if (arr[1] == -1 && arr[0] == -1)
	{
		if (ft_getenv("PATH") == NULL)
			printf("bash: %s: No such file or directory\n", cmd->argv[0]);
		else
			printf("bash: %s: command not found\n", cmd->argv[0]);
	}
	else if (arr[1] == -1 && arr[0] == 1)
		printf("bash: %s: No such file or directory\n", cmd->argv[0]);
	g_state.exit_code = 127;
	return (0);
}

static int	ft_exec_helper(int arr[4], t_cmd *cmd, char **env)
{
	if (arr[1] == 1)
	{
		ft_redirection(cmd);
		exec_builtin(cmd);
	}
	else if (arr[0] == 3)
		printf("bash: %s: is a directory\n", cmd->argv[0]);
	else if (arr[1] == 0 || arr[0] == 0 || arr[1]  == 5)
	{
		exec_cmd(cmd, env);
		close_fd(cmd, &arr[2], &arr[3]);
		if (arr[1] == 5 && cmd->prev == NULL && cmd->next == NULL)
			return (34);
		g_state.is_fork = 0;
	}
	else
	{
		if (ft_exec_helper2(arr, cmd) == 1)
			return (1);
	}
	return (0);
}

static int	ft_exec_helper3(t_cmd **cmd, char **env)
{
	pipe((*cmd)->fds);
	if (check_null(*cmd) == 1)
	{
		printf("bash: : command not found\n");
		ft_redirection(*cmd);
		*cmd = (*cmd)->next;
		free_env_list(env);
		return (1);
	}
	return (0);
}

int	ft_exec(t_cmd_list *lists)
{
	t_cmd	*cmd;
	char	**env;
	int		arr[4];

	set_type(lists);
	cmd = lists->cmd_list;
	while (cmd != NULL)
	{
		env = get_env_list(&(g_state.list));
		arr[3] = dup(STDOUT);
		arr[2] = dup(STDIN);
		if (ft_exec_helper3(&cmd, env) == 1)
			continue ;
		arr[1] = check_exec_name_is_builtin(cmd);
		arr[0] = interprete_exe_name(cmd);
		if (ft_exec_helper(arr, cmd, env) == 34)
		{
			free_env_list(env);
			return (34);
		}
		free_env_list(env);
		cmd = cmd->next;
	}
	return (0);
}
