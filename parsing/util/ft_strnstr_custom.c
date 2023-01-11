/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_custom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:36:02 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/18 02:08:20 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/command_parse.h"

int	ft_p_strstr_custom(const char *h, const char *n, int	*end)
{
	int	i_h;
	int	i_n;
	int	len;

	i_h = -1;
	if (*n == '\0' || end == NULL)
		return (-1);
	len = ft_p_strlen(h);
	while (++i_h < len)
	{
		i_n = -1;
		while (++i_n + i_h <= len)
		{
			*end = i_n + i_h;
			if (n[i_n] == '\0')
				return (i_h);
			if (h[i_h + i_n] == '\0' || h[i_h + i_n] != n[i_n])
				break ;
		}
		if (i_h + i_n == len || h[i_h + i_n] == '\0')
			break ;
	}
	return (-1);
}
