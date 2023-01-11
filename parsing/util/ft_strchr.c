/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:59:32 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/17 12:10:17 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_p_strchr(const char *s, int c)
{
	char	casted_c;

	casted_c = (char) c;
	while (*s != casted_c && *s != '\0')
		s++;
	if (*s == casted_c)
		return ((char *)s);
	return (0);
}
