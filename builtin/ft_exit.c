/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:47:27 by park              #+#    #+#             */
/*   Updated: 2022/07/21 00:21:30 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include <stdio.h>

static int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static int	exit_helper(int i, char **argv)
{
	int	rst;

	if (i > 2)
	{
		printf("bash: exit: too many arguments\n");
		return (255);
	}
	else
	{
		if (check_num(argv[1]) == SUCCESS)
		{
			rst = ft_atoi(argv[1]);
			printf("exit\n");
			return (rst);
		}
		printf("exit\n");
		printf("bash: exit: %s: numeric argument required\n", argv[1]);
		return (255);
	}
}

int	ft_exit(char **argv)
{
	int	i;

	i = 0;
	if (argv[1] == NULL)
	{
		printf("exit\n");
		return (34);
	}
	while (argv[i] != NULL)
		i++;
	return (exit_helper(i, argv));
}
