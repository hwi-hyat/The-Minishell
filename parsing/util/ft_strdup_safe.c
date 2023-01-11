/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:53:44 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/22 02:27:15 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/command_parse.h"

char	*ft_p_strdup_safe(const char *src)
{
	int		size;
	int		localindex;
	char	*result;

	size = 0;
	if (src == NULL)
		src = "";
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
