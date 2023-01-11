/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 03:15:59 by park              #+#    #+#             */
/*   Updated: 2022/07/23 11:48:12 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include <stdio.h>

static int	valid_key(char *key)
{
	int	i;

	i = 0;
	while (key[i] != '\0')
	{
		if ((key[i] >= '0' && key[i] <= '9') || (key[i] >= 'a'
				&& key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z'))
			;
		else
			return (-1);
		i++;
	}
	return (0);
}

int	ft_unset(char **argv, t_list *list)
{
	int	i;

	if (argv[1] == NULL)
		return (0);
	i = 1;
	while (argv[i] != NULL)
	{
		if (valid_key(argv[i]) == -1)
		{
			printf("bash: unset: `%s': not a valid identifier\n", argv[i]);
			return (1);
		}
		else
			ft_lstdelone(list, argv[i]);
		i++;
	}
	return (0);
}
