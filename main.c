/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:15:50 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 01:15:23 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	full_of_space(char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx] != '\0')
		if (str[idx] != ' ')
			return (0);
	return (1);
}

void	print_intro(void)
{
	int		intro_fd;
	int		readsize;
	char	buffer[43];

	intro_fd = open("intro.txt", O_RDONLY);
	if (intro_fd < 0)
	{
		printf("fail to open intro.txt\n");
		return ;
	}
	while (1)
	{
		readsize = read(intro_fd, buffer, 42);
		buffer[readsize] = '\0';
		if (readsize < 1)
		{
			printf("\n");
			break ;
		}
		printf("%s", buffer);
	}
	close(intro_fd);
}

void	prompt_helper(t_cmd_list *cmd_lst, char *str, int *ret)
{
	int	i;

	cmd_lst = parse(ft_p_strdup(str));
	i = 0;
	if (!full_of_space(str) && ft_heredoc(cmd_lst, i) != 4242)
	{
		if (cmd_lst->status == TYPE_SYNTAX_ERR)
		{
			printf ("bash: syntax error near unexpected token `%s'\n",
				cmd_lst->cmd_list->exec_file_name);
			g_state.exit_code = 258;
		}
		else if (cmd_lst->status == TYPE_AMBIGUOUS_ERR)
		{
			printf("bash: %s: ambiguous redirect\n",
				cmd_lst->cmd_list->exec_file_name);
			g_state.exit_code = 1;
		}
		else
			*ret = ft_exec(cmd_lst);
	}
	unlink_tmp_file(cmd_lst);
	free_t_cmd_list(cmd_lst);
	add_history(str);
}

void	prompt(t_cmd_list *cmd_lst, char *str)
{
	int	ret;

	while (1)
	{
		str = readline("bash$ ");
		if (str)
		{
			if (str[0] != 0)
				prompt_helper(cmd_lst, str, &ret);
		}
		else
		{
			printf("\033[1A");
			printf("\033[5C");
			printf(" exit\n");
			break ;
		}
		free(str);
		str = NULL;
		if (ret == 34)
			return ;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_cmd_list	*cmd_lst;
	char		*str;

	(void)argc;
	(void)argv;
	print_intro();
	init_env_and_signal(env);
	cmd_lst = NULL;
	str = NULL;
	prompt(cmd_lst, str);
	return (0);
}
