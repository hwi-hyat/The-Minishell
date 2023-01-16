/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:11:14 by siykim            #+#    #+#             */
/*   Updated: 2023/01/11 17:17:13 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/command_parse.h"

char	*ft_p_strdup(const char *src)
{
	int		size;
	int		index;
	char	*result;

	size = 0;
	while (src[size])
		size++;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	index = -1;
	while (++index < size)
		result[index] = src[index];
	result[index] = '\0';
	return (result);
}
