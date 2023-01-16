/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:10:08 by siykim            #+#    #+#             */
/*   Updated: 2023/01/11 16:32:32 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <term.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "linkedlist.h"
# include "ft_builtin.h"
# include "ft_utils.h"
# include "command_parse.h"

/*utils*/
int		ft_strcmp(char *s1, char *s2);
int		ft_isalnum(int c);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_itoa(int n);

int		ft_exec(t_cmd_list *lists);
void	init_env_and_signal(char **env);
int		full_of_space(char *str);


#endif