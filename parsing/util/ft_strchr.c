/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:10:45 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:10:45 by siykim           ###   ########.fr       */
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
