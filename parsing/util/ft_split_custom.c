/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_custom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:10:29 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/22 01:14:08 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/command_parse.h"

static size_t	get_arr_size(char const *s, char c);
static char		*make_elements(char const **s, char c);
static void		emergency_exit(char **p, char **iter_p);

char	**ft_p_split_custom(char const *s, char c)
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

static size_t	get_arr_size(char const *s, char c)
{
	size_t	result;

	result = 1;
	if (*s != c)
		result++;
	while (*s)
	{
		if (*s == c)
			result++;
		s++;
	}
	return (result);
}

static char	*make_elements(char const **s, char c)
{
	size_t		size;
	char		*result;
	char const	*iter_s;
	char		*iter_result;

	size = 1;
	iter_s = *s;
	if (**s == c)
	{
		(*s)++;
		size++;
	}
	while (**s != '\0' && **s != c && size++)
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
