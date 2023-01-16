/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:03:53 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:03:54 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	print_non_argv_export(t_list *list)
{
	t_env	*curr;

	curr = list->head->next;
	while (curr != list->tail)
	{
		printf("declare -x %s=%s\n", curr->key, curr->value);
		curr = curr->next;
	}
	return (0);
}

static int	print_error(int error, char *str)
{
	error++;
	printf("bash: export: `%s': not a valid identifier\n", str);
	return (1);
}

static int	is_valid_key(char *str)
{
	int		i;

	i = 0;
	if (ft_isdigit(str[i]) == 1)
		return (0);
	else if (str[i] == '=')
		return (-3);
	while (str[i] && str[i] != '=')
	{
		if (ft_isalnum(str[i]) == 0)
			return (-1);
		i++;
	}
	if (str[i] != '=')
		return (2);
	return (1);
}

static void	free_key_value(char **envs)
{
	free(envs[0]);
	free(envs[1]);
	free(envs);
}

int	ft_export(char **argv, t_list *list)
{
	int		error;
	int		idx;
	char	**envs;

	if (argv[1] == NULL)
		return (print_non_argv_export(list));
	error = is_valid_key(argv[1]);
	if (error <= 0)
		return (print_error(error, argv[1]));
	if (error == 1)
	{
		idx = 1;
		while (argv[idx] != NULL)
		{
			envs = ft_p_split(argv[1], '=');
			if (ft_is_in_env(&(g_state.list), envs[0]) == 1)
				ft_update_env(&(g_state.list), envs[0], envs[1]);
			else
				ft_lstadd(&(g_state.list),
					ft_strdup(envs[0]), ft_strdup(envs[1]));
			free_key_value(envs);
			idx++;
		}
	}
	return (0);
}
