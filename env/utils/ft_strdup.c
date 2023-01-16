/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 02:55:05 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:57:03 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		size;
	int		localindex;
	char	*result;

	size = 0;
	while (src[size])
		size++;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	localindex = -1;
	while (++localindex < size)
		result[localindex] = src[localindex];
	result[localindex] = '\0';
	return (result);
}
