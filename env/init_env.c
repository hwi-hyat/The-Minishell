/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:37:24 by park              #+#    #+#             */
/*   Updated: 2022/07/21 21:02:38 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../include/linkedlist.h"

int	init_env(char **env, t_env **head, t_list *list)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

	*head = ft_lstnew("", "");
	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
		{
			if (env[i][j] == '=')
			{
				key = ft_substr(env[i], 0, j);
				value = ft_substr(env[i], j + 1, ft_strlen(env[i]) - j);
				ft_lstadd(list, key, value);
			}
			j++;
		}
		i++;
	}
	ft_update_env(list, "OLDPWD", "");
	return (1);
}
