/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:08:41 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:08:42 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	ft_p_get_last_char(char *str)
{
	int		index;
	char	ret;

	index = -1;
	ret = '\0';
	if (str == NULL)
		return ('\0');
	while (str[++index] != '\0')
		ret = str[index];
	return (ret);
}
