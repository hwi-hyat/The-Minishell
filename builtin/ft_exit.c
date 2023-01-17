/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:03:43 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 15:29:01 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
