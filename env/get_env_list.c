/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:33:43 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/22 01:13:07 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linkedlist.h"
#include <stdio.h>

static int	env_count(t_list *list)
{
	t_env	*curr;
	int		cnt;

	cnt = 0;
	curr = list->head->next;
	while (curr != list->tail)
	{
		cnt++;
		curr = curr->next;
	}
	return (cnt);
}

static char	*return_str(char *key, char *value)
{
	char	*tmp;
	char	*rst;

	tmp = ft_strjoin(key, "=");
	rst = ft_strjoin(tmp, value);
	free(tmp);
	return (rst);
}

void	free_env_list(char **env_list)
{
	int	i;

	i = 0;
	while (env_list[i] != NULL)
	{
		free(env_list[i]);
		i++;
	}
	free(env_list[i]);
	free(env_list);
	env_list = NULL;
}

char	**get_env_list(t_list *list)
{
	char	**rst;
	int		i;
	t_env	*curr;

	rst = (char **)malloc((env_count(list) + 1) * sizeof(char *));
	if (rst == NULL)
		return (NULL);
	i = 0;
	curr = list->head->next;
	while (curr != list->tail)
	{
		rst[i] = return_str(curr->key, curr->value);
		i++;
		curr = curr->next;
	}
	rst[i] = NULL;
	return (rst);
}
