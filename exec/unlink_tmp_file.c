/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_tmp_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:08:30 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/21 01:54:20 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"

void	unlink_tmp_file(t_cmd_list *lists)
{
	t_cmd				*cmd;
	t_cmd_redirection	*red;

	cmd = lists->cmd_list;
	while (cmd != NULL)
	{
		red = cmd->redirection_list;
		while (red != NULL)
		{
			if (red->red_type == BEFORE_LL)
				unlink(red->file);
			red = red->next;
		}		
		cmd = cmd->next;
	}
}
