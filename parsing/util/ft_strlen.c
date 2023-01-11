/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:24:36 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/18 02:08:20 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/command_parse.h"

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
