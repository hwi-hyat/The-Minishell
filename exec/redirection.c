/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:07:22 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/21 21:03:55 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int	ft_redirection(t_cmd *cmd)
{
	t_cmd_redirection	*red;

	cmd->fd_in = 0;
	cmd->fd_out = 1;
	red = cmd->redirection_list;
	while (red != NULL)
	{
		if (red->red_type == TYPE_TOKEN_IO_R)
			cmd->fd_out = open(red->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (red->red_type == TYPE_TOKEN_IO_RR)
			cmd->fd_out = open(red->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else if (red->red_type == TYPE_TOKEN_IO_L || red->red_type == BEFORE_LL)
			cmd->fd_in = open(red->file, O_RDONLY);
		if (cmd->fd_out == -1 || cmd->fd_in == -1)
		{
			printf("bash: %s: %s\n", red->file, strerror(errno));
			g_state.exit_code = 1;
			return (1);
		}
		red = red->next;
	}
	return (0);
}
