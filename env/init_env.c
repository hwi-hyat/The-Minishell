/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:05:55 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:05:55 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
