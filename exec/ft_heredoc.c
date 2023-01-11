/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:55:17 by jeounpar          #+#    #+#             */
/*   Updated: 2022/07/21 21:03:30 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/command_parse.h"
#include "../include/ft_utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

void	signal_handler(int signo);

void	heredoc_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		kill(g_state.pid, SIGTERM);
	}
}

void	heredoc_prompt(char *str, int fd, char *eof)
{
	while (1)
	{
		str = readline("> ");
		if (str != NULL)
		{
			if (ft_strcmp(eof, str) == 0)
			{
				free(str);
				break ;
			}
			write(fd, str, ft_strlen(str));
			write(fd, "\n", 1);
		}
		else
		{
			printf("\033[1A");
			printf("\033[2C");
			exit(1);
		}
		free(str);
	}
	exit(0);
}

void	go_heredoc(t_cmd_redirection *red, char *eof)
{
	int		fd;
	char	*str;
	int		status;

	fd = open(red->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	g_state.pid = fork();
	signal(SIGINT, heredoc_handler);
	str = NULL;
	if (g_state.pid == 0)
		heredoc_prompt(str, fd, eof);
	else if (g_state.pid > 0)
	{
		waitpid(g_state.pid, &status, 0);
		if (WIFEXITED(status) == 0)
			g_state.exit_code = 4242;
		else
			g_state.exit_code = WEXITSTATUS(status);
	}
	signal(SIGINT, signal_handler);
	close(fd);
}

void	rand_file_name(t_cmd_redirection *red, int i)
{
	char	*new_file_name;
	char	*int_to_str;

	int_to_str = ft_itoa(i);
	free(red->file);
	new_file_name = ft_strjoin("./exec/jeounparchanhale", int_to_str);
	red->file = new_file_name;
	free(int_to_str);
}

int	ft_heredoc(t_cmd_list *lists, int i)
{
	t_cmd				*cmd;
	t_cmd_redirection	*red;
	char				*eof;

	cmd = lists->cmd_list;
	while (cmd != NULL)
	{
		red = cmd->redirection_list;
		while (red != NULL)
		{
			if (red->red_type == TYPE_TOKEN_IO_LL)
			{
				eof = ft_strdup(red->file);
				rand_file_name(red, i++);
				red->red_type = BEFORE_LL;
				go_heredoc(red, eof);
				free(eof);
				if (g_state.exit_code == 4242)
					return (4242);
			}
			red = red->next;
		}		
		cmd = cmd->next;
	}
	return (0);
}
