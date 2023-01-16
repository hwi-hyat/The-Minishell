/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_and_signal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:05:51 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:05:51 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		if (g_state.is_fork == 0)
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
			g_state.exit_code = 1;
		}
		else
		{
			g_state.exit_code = 130;
			printf("\n");
		}
	}
}

void	init_env_and_signal(char **env)
{
	struct termios	term;

	ft_initlist(&(g_state.list));
	init_env(env, &(g_state.head), &(g_state.list));
	g_state.exit_code = 0;
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
