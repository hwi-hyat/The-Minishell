/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:07:24 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:07:24 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
