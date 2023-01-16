/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:12:06 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:12:33 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	sub_is_in(char c, char const *set)
{
	size_t	index;

	index = 0;
	if (c == '\0')
		return (1);
	while (set[index])
		if (set[index++] == c)
			return (1);
	return (0);
}

static int	sub_func(char const *s1, char const *set, char **result, int *g_s)
{
	int			size;

	size = 0;
	while (s1[size++])
		;
	while (size && sub_is_in(s1[size - 1], set))
		size--;
	while (*s1 && sub_is_in(*(s1++), set))
		size--;
	if (size < 0)
		size = 0;
	*result = (char *)malloc((size + 1) * sizeof(char));
	if (*result == NULL)
	{
		return (1);
	}
	(*result)[size] = '\0';
	*g_s = size + 1;
	return (0);
}

char	*ft_p_strtrim(char const *s1, char const *set)
{
	int			size;
	char		*result;
	char		*iter_result;

	result = NULL;
	if (s1 == NULL || set == NULL || sub_func(s1, set, &result, &size))
		return (NULL);
	iter_result = result;
	while (*s1 && sub_is_in(*(s1), set))
		s1++;
	while (--size)
		*(iter_result++) = *(s1++);
	return (result);
}
