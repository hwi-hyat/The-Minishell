/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:57:52 by park              #+#    #+#             */
/*   Updated: 2022/07/21 01:49:25 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_builtin.h"
#include <stdio.h>
#include <unistd.h>

int	ft_pwd(void)
{
	char	buff[9999];

	if (getcwd(buff, 9999) != NULL)
		printf("%s\n", buff);
	return (0);
}
