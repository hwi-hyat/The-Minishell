/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:10:58 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:10:59 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
