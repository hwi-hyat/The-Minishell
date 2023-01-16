/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep_custom_io.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:11:37 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:11:38 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static size_t	get_arr_size(char const *s, char c, char d)
{
	size_t	result;
	int		flag;

	result = 1;
	if (*s != c && *s != d)
		result++;
	flag = 0;
	while (*s)
	{
		if (*s == c || *s == d)
		{
			result++;
			flag = 1;
		}
		else if (flag)
		{
			result++;
			flag = 0;
		}
		s++;
	}
	return (result);
}

static char	*make_elements(char const **s, char c, char d)
{
	size_t		size;
	char		*result;
	char const	*iter_s;
	char		*iter_result;

	size = 1;
	iter_s = *s;
	if (**s == c || **s == d)
	{
		(*s)++;
		size++;
	}
	else
		while (**s != '\0' && **s != c && **s != d && size++)
			(*s)++;
	result = (char *)malloc(sizeof(char) * size);
	if (result == NULL)
		return (NULL);
	iter_result = result;
	size--;
	while (size-- && *iter_s != '\0')
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

char	**ft_p_strsep_custom_io(char const *s, char c, char d)
{
	char	**result;
	char	**iter_result;
	char	*element;
	size_t	arr_size;

	if (s == NULL)
		return (NULL);
	arr_size = get_arr_size(s, c, d);
	result = (char **)malloc(sizeof(char *) * arr_size);
	if (result == NULL)
		return (NULL);
	iter_result = result;
	while (--arr_size)
	{
		element = make_elements(&s, c, d);
		if (element == NULL)
			emergency_exit(result, iter_result);
		if (element == NULL)
			return (NULL);
		*(iter_result++) = element;
	}
	*iter_result = NULL;
	return (result);
}
