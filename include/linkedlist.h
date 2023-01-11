/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:14:48 by park              #+#    #+#             */
/*   Updated: 2022/07/21 11:41:51 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include "ft_utils.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_list
{
	t_env	*head;
	t_env	*tail;
}	t_list;

int		init_env(char **env, t_env **head, t_list *list);
int		ft_lstdelone(t_list *list, char *key);
int		ft_is_in_env(t_list	*list, char *key);
t_env	*ft_lstnew(char *key, char *value);
void	ft_lstadd(t_list *list, char *key, char *value);
void	ft_initlist(t_list *list);
void	ft_viewall(t_list *list);
void	ft_update_env(t_list *list, char *key, char *value);

#endif