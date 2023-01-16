/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_tmp_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:07:29 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:07:29 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
