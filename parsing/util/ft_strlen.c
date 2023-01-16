/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:11:12 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:11:12 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

size_t	ft_p_strlen(const char *s)
{
	size_t	iter;

	iter = 0;
	if (s == NULL)
		return (0);
	while (s[iter])
		iter++;
	return (iter);
}
