/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_free_seq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:51:37 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:32:15 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
