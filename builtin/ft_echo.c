/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:03:28 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:03:29 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

static void	echo_flag_check(char **argv, int *idx, int *new_line)
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
		*new_line = 1;
	}	
}

int	ft_echo(char **argv)
{
	int		new_line;
	int		idx;

	new_line = 0;
	idx = 1;
	echo_flag_check(argv, &idx, &new_line);
	echo_helper(argv, idx);
	if (new_line == 0)
		printf("\n");
	return (0);
}
