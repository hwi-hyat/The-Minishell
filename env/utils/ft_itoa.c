/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:06:29 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:06:29 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
		cnt++;
	while (1)
	{
		cnt++;
		if (n / 10 == 0)
			break ;
		n /= 10;
	}
	return (cnt);
}

static void	str_base_to(int n, char *base, char *str, int size)
{
	int	i;
	int	neg;
	int	tmp;

	i = 0;
	neg = 1;
	if (n < 0)
	{
		neg = 0;
		str[i] = '-';
		i = 1;
	}
	while (i < size)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp *= -1;
		str[size - i - neg] = base[tmp];
		n = n / 10;
		i++;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = get_len(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str_base_to(n, "0123456789", str, size);
	return (str);
}
