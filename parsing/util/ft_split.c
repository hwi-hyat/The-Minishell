/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:09:19 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:10:03 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static size_t	get_arr_size(char const *s, char c)
{
	size_t	result;
	int		flag;

	result = 1;
	flag = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (flag)
			{
				result++;
				flag = 0;
			}
		}
		else
			flag = 1;
		s++;
	}
	if (flag)
		result++;
	return (result);
}

static char	*make_elements(char const **s, char c)
{
	size_t		size;
	char		*result;
	char const	*iter_s;
	char		*iter_result;

	size = 1;
	while (**s == c)
		(*s)++;
	iter_s = *s;
	while (**s != c && **s != '\0' && size++)
		(*s)++;
	result = (char *)malloc(sizeof(char) * size);
	if (result == NULL)
		return (NULL);
	iter_result = result;
	while (*iter_s != c && *iter_s != '\0')
		*(iter_result++) = *(iter_s++);
	*iter_result = '\0';
	return (result);
}

static void	emergency_exit(char **p, char **iter_p)
{
	if (*iter_p != NULL)
		free(*iter_p);
	if (*p == *iter_p)
	{
		free (p);
		return ;
	}
	while ((*p) != --(*iter_p))
		if (*iter_p != NULL)
			free(*iter_p);
	if (*iter_p != NULL)
		free(*iter_p);
	free (p);
}

char	**ft_p_split(char const *s, char c)
{
	char	**result;
	char	**iter_result;
	char	*element;
	size_t	arr_size;

	if (s == NULL)
		return (NULL);
	arr_size = get_arr_size(s, c);
	result = (char **)malloc(sizeof(char *) * arr_size);
	if (result == NULL)
		return (NULL);
	iter_result = result;
	while (--arr_size)
	{
		element = make_elements(&s, c);
		if (element == NULL)
			emergency_exit(result, iter_result);
		if (element == NULL)
			return (NULL);
		*(iter_result++) = element;
	}
	*iter_result = NULL;
	return (result);
}
