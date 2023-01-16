/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:24:31 by chanhale          #+#    #+#             */
/*   Updated: 2023/01/17 00:32:15 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_p_strcmp(const char *s1, const char *s2)
{
	size_t	length_s1;
	size_t	iter;

	length_s1 = 0;
	iter = 0;
	while (s1[length_s1] != '\0')
		length_s1++;
	while (iter < length_s1)
	{
		if (s1[iter] != s2[iter])
			break ;
		iter++;
	}
	return (((unsigned char *)s1)[iter] - ((unsigned char *)s2)[iter]);
}
