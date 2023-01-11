/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_exe_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 12:25:05 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/23 12:04:36 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"
#include "../include/ft_builtin.h"
#include <sys/stat.h>

static int	interprete_helper(char **sep, int index, t_cmd *cmd)
{
	char		*str;
	char		*str_tmp;
	struct stat	sb;

	while (sep[++index])
	{
		str_tmp = ft_p_strjoin("/", cmd->exec_file_name);
		str = ft_p_strjoin(sep[index], str_tmp);
		if (stat(str, &sb) != -1)
		{
			free(cmd->argv[0]);
			cmd->argv[0] = str;
			parse_safe_free_multi_str(str_tmp, NULL, NULL, NULL);
			parse_safe_free_two_d_char(sep, -1);
			return (0);
		}
		parse_safe_free_multi_str(str_tmp, str, NULL, NULL);
	}
	parse_safe_free_two_d_char(sep, -1);
	return (-1);
}

int	interprete_exe_name(t_cmd *cmd)
{
	int			index;
	char		*str;
	char		**sep;
	struct stat	sb;

	if ((cmd->exec_file_name[0] == '.' && cmd->exec_file_name[1] == '/')
		|| cmd->exec_file_name[0] == '/')
	{
		index = stat(cmd->exec_file_name, &sb);
		if (index == -1)
			return (1);
		else if ((sb.st_mode & S_IFMT) == S_IFDIR)
			return (3);
		else
			return (0);
	}
	str = ft_p_strdup_safe(ft_getenv("PATH"));
	index = -1;
	sep = ft_p_split(str, ':');
	parse_safe_free_multi_str(str, NULL, NULL, NULL);
	if (str == NULL || sep == NULL)
		return (-1);
	return (interprete_helper(sep, index, cmd));
}

int	exec_builtin(t_cmd *cmd)
{
	if (ft_p_strcmp(cmd->exec_file_name, "echo") == 0)
		return (ft_echo(cmd->argv));
	else if (ft_p_strcmp(cmd->exec_file_name, "pwd") == 0)
		return (ft_pwd());
	else if (ft_p_strcmp(cmd->exec_file_name, "env") == 0)
		return (ft_env(&(g_state.list)));
	else if (ft_p_strcmp(cmd->exec_file_name, "exit") == 0)
		return (ft_exit(cmd->argv));
	else if (ft_p_strcmp(cmd->exec_file_name, "cd") == 0)
		return (ft_cd(cmd->argv, &(g_state.list)));
	else if (ft_p_strcmp(cmd->exec_file_name, "export") == 0)
		return (ft_export(cmd->argv, &(g_state.list)));
	else if (ft_p_strcmp(cmd->exec_file_name, "unset") == 0)
		return (ft_unset(cmd->argv, &(g_state.list)));
	return (-1);
}

int	check_exec_name_is_builtin(t_cmd *cmd)
{
	if (ft_p_strcmp(cmd->exec_file_name, "echo") == 0)
		return (0);
	else if (ft_p_strcmp(cmd->exec_file_name, "pwd") == 0)
		return (0);
	else if (ft_p_strcmp(cmd->exec_file_name, "env") == 0)
		return (0);
	else if (ft_p_strcmp(cmd->exec_file_name, "exit") == 0)
		return (5);
	else if (ft_p_strcmp(cmd->exec_file_name, "cd") == 0)
		return (1);
	else if (ft_p_strcmp(cmd->exec_file_name, "export") == 0)
		return (1);
	else if (ft_p_strcmp(cmd->exec_file_name, "unset") == 0)
		return (1);
	return (-1);
}
