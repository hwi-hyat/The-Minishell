/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:08:48 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:09:06 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	alloc_space(int nbr, char **result, char **iter)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		i++;
		if (nbr < -9)
		{
			nbr /= 10;
			i++;
		}
		nbr = nbr * -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	*result = (char *)malloc(sizeof(char) * (i + 1));
	*iter = *result;
	if (*result == NULL)
		return (1);
	(*result)[i] = '\0';
	return (0);
}

static void	iter(int nb, char **result)
{
	char	c;

	if (nb < 0)
	{
		*((*result)++) = '-';
		c = 48 + (nb % 10) * -1;
		if ((nb / 10) * -1 > 0)
			iter((nb / 10) * -1, result);
		*((*result)++) = c;
	}
	else
	{
		if (nb >= 10)
			iter(nb / 10, result);
		*((*result)++) = 48 + nb % 10;
	}
}

char	*ft_p_itoa(int n)
{
	char	*result;
	char	*iter_result;

	if (alloc_space(n, &result, &iter_result))
		return (NULL);
	iter(n, &iter_result);
	return (result);
}
