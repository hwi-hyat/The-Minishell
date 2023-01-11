/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:37:43 by park              #+#    #+#             */
/*   Updated: 2022/07/23 11:36:06 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include <stdio.h>

static void	echo_helper(char **argv, int idx)
{
	while (argv[idx] != NULL)
	{
		printf("%s", argv[idx]);
		if (argv[idx + 1] != NULL)
			printf(" ");
		idx++;
	}
}

static void	echo_flag_check(char **argv, int *idx, int *newline)
{
	int	t;

	if (argv[1] && argv[*idx][0] == '-' && argv[*idx][1] == 'n')
	{
		while (argv[*idx][0] == '-' && argv[*idx][1] == 'n')
		{
			t = 1;
			while (argv[1][t] != '\0')
			{
				if (argv[1][t] != 'n')
					return ;
				t++;
			}
			(*idx)++;
		}
		*newline = 1;
	}	
}

int	ft_echo(char **argv)
{
	int		newline;
	int		idx;

	newline = 0;
	idx = 1;
	echo_flag_check(argv, &idx, &newline);
	echo_helper(argv, idx);
	if (newline == 0)
		printf("\n");
	return (0);
}
