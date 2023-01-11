/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_free_seq.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:49:28 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/16 15:55:22 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/command_parse.h"

void	*parse_safe_free_two_d_char(char **ptr, int max)
{
	int	index;

	index = -1;
	if (ptr == NULL)
		return (NULL);
	while (ptr[++index] != NULL && (max < 0 || index <= max))
		free(ptr[index]);
	free(ptr);
	return (NULL);
}

void	*parse_safe_free_multi_str(
		void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
	if (ptr1 != NULL)
		free(ptr1);
	if (ptr2 != NULL)
		free(ptr2);
	if (ptr3 != NULL)
		free(ptr3);
	if (ptr4 != NULL)
		free(ptr4);
	return (NULL);
}
