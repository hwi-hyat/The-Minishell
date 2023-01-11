/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:38:43 by park              #+#    #+#             */
/*   Updated: 2022/07/21 00:06:52 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include "../include/linkedlist.h"
#include <unistd.h>
#include <stdio.h>

static int	cd_helper(t_list *list, char *value, char **argv)
{
	char	buff[9999];
	int		rst;

	rst = chdir(value);
	if (rst == -1)
	{
		printf("bash: cd: %s: No such file or directory\n", argv[1]);
		return (127);
	}
	else
	{
		getcwd(buff, 9999);
		ft_update_env(list, "OLDPWD", ft_getenv("PWD"));
		ft_update_env(list, "PWD", buff);
	}
	return (0);
}

int	ft_cd(char **argv, t_list *list)
{
	char	*value;

	if (argv[1] == NULL || ft_strcmp(argv[1], "~") == 0)
	{
		value = ft_getenv("HOME");
		if (value == NULL)
		{
			printf("bash: cd: HOME not set\n");
			return (1);
		}
	}
	else if (ft_strcmp(argv[1], "-") == 0)
	{
		value = ft_getenv("OLDPWD");
		if (value == NULL)
		{
			printf("bash: cd: OLDPWD not set\n");
			return (1);
		}
	}
	else
		value = argv[1];
	return (cd_helper(list, value, argv));
}
