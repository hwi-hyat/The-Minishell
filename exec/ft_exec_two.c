/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:07:11 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 16:00:00 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_pipe(t_cmd *cmd)
{
	if (cmd->type == TYPE_PIPE
		|| (cmd->next != 0 && cmd->next->type == TYPE_PIPE))
	{
		if (cmd->type != TYPE_PIPE)
			dup2(cmd->fds[1], 1);
		else if (cmd->next == 0)
			dup2(cmd->prev->fds[0], 0);
		else
		{
			dup2(cmd->prev->fds[0], 0);
			dup2(cmd->fds[1], 1);
		}
	}
}

void	close_fd(t_cmd *cmd, int *stin, int *stout)
{
	if (cmd->prev != 0)
		close(cmd->prev->fds[0]);
	close(cmd->fds[1]);
	if (cmd->next == 0)
		close(cmd->fds[0]);
	if (cmd->fd_in != 0)
		close(cmd->fd_in);
	if (cmd->fd_out != 1)
		close(cmd->fd_out);
	dup2(*stin, 0);
	dup2(*stout, 1);
	close(*stin);
	close(*stout);
}

void	ft_set_pipe(t_cmd *cmd)
{
	set_pipe(cmd);
	if (cmd->fd_in != 0)
		dup2(cmd->fd_in, 0);
	if (cmd->fd_out != 1)
		dup2(cmd->fd_out, 1);
}

void	exec_cmd(t_cmd *cmd, char **env)
{
	int	pid;
	int	ret;
	int	status;

	g_state.is_fork = 1;
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		if (ft_redirection(cmd) == 1)
			exit(1);
		ft_set_pipe(cmd);
		ret = exec_builtin(cmd);
		printf("ret %d\n", ret);
		if (ret == -1)
			ret = execve(cmd->argv[0], cmd->argv, env); 
		exit(ret);
	}
	else
	{
		close(cmd->fds[1]);
		waitpid(pid, &status, 0);
		printf("????\n");
		g_state.exit_code = WEXITSTATUS(status);
		printf("global exitcode updated to %d\n", g_state.exit_code);
	}
}

void	set_type(t_cmd_list *lists)
{
	t_cmd	*cmd;

	cmd = lists->cmd_list;
	cmd->type = TYPE_NORMAL;
	cmd = cmd->next;
	while (cmd != NULL)
	{
		cmd->type = TYPE_PIPE;
		cmd = cmd->next;
	}
}
