/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd_add_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:07:46 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:07:46 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*parse_t_cmd_add_argv(t_cmd *cmd, char *str, int index)
{
	char	**new_argv;
	char	*new_str;
	int		counter;

	counter = -1;
	if (index == 0)
	{
		new_str = ft_p_strdup(str);
		if (new_str == NULL)
			return (NULL);
		cmd->exec_file_name = new_str;
	}
	new_str = ft_p_strdup(str);
	while (cmd->argv[++counter] != NULL)
		;
	new_argv = (char **)malloc(sizeof(char *) * (counter + 2));
	if (new_argv == NULL || new_str == NULL)
		return (parse_safe_free_multi_str(new_argv, new_str, NULL, NULL));
	new_argv[counter] = new_str;
	new_argv[counter + 1] = NULL;
	while ((--counter) >= 0)
		new_argv[counter] = cmd->argv[counter];
	free(cmd->argv);
	cmd->argv = new_argv;
	return (NULL);
}
