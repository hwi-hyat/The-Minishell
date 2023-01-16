/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:10:08 by siykim            #+#    #+#             */
/*   Updated: 2023/01/17 00:52:34 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <term.h>
# include <sys/stat.h>

# define SUCCESS 1
# define FAIL 0
# define TYPE_ERR_CODE_ALLOC 1
# define TYPE_FAIL 1
# define TYPE_SUCCESS 0
# define TYPE_INITIAL_STATUS 0
# define TYPE_ARGV_NULL 1
# define TYPE_RED_LEFT 0
# define TYPE_SYNTAX_ERR 999
# define TYPE_AMBIGUOUS_ERR 9999
# define TYPE_TOKEN_CHUNK 11
# define TYPE_TOKEN_ARGV 22
# define TYPE_TOKEN_SPACE 33
# define TYPE_TOKEN_PIPELINE 44
# define TYPE_TOKEN_EXEC 55
# define TYPE_TOKEN_IO_R 101
# define TYPE_TOKEN_IO_RR 102
# define TYPE_TOKEN_IO_L 103
# define TYPE_TOKEN_IO_LL 104

# define STDIN 0
# define STDOUT 1

# define ERROR 0
# define SUCCESS 1
# define TYPE_PIPE 88
# define TYPE_NORMAL 0

# define BEFORE_LL 105

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

typedef struct s_cmd_redirection
{
	char						*file;
	int							red_type;
	struct s_cmd_redirection	*next;
}	t_cmd_redirection;

typedef struct s_cmd
{
	char						*exec_file_name;
	char						**argv;
	int							fds[2];
	int							fd_in;
	int							fd_out;
	int							type;
	struct s_cmd_redirection	*redirection_list;
	struct s_cmd				*next;
	struct s_cmd				*prev;
}	t_cmd;

typedef struct s_cmd_list
{
	struct s_cmd				*cmd_list;
	struct s_cmd				*cmd_list_tail;
	int							status;
}	t_cmd_list;

typedef struct s_parse_token
{
	int						token_type;
	int						is_null;
	char					*original_str;
	char					*string;
	struct s_parse_token	*next;
}	t_parse_token;

typedef struct s_state
{
	t_list	list;
	t_env	*head;
	t_env	*tmp;
	pid_t	pid;
	int		exit_code;
	int		is_fork;
}	t_state;

t_state	g_state;

t_cmd_list			*parse(char *raw_cmd_string);
t_cmd_list			*create_empty_t_cmd_list(void);
t_cmd				*add_empty_t_cmd_to_list(t_cmd_list *cmd_list);
t_cmd_redirection	*add_cmd_redirection(t_cmd *cmd, int red_type, char *file);
void				free_first_t_cmd_node(t_cmd_list *cmd_list);
void				*free_t_cmd_list(t_cmd_list *cmd_list);
void				cleanse_single_t_parse_token(t_parse_token *token);
t_cmd				*get_last_node(t_cmd *cmd_list);
t_cmd				*get_empty_t_cmd(void);
char				**ft_p_split_custom(char const *s, char c);
char				**ft_p_strsep_custom(char const *s, char c);
char				**ft_p_strsep_custom_io(char const *s, char c, char d);
int					ft_p_strstr_custom(const char *h, const char *n, int *end);
char				*ft_p_strdup_safe(const char *src);
char				ft_p_get_last_char(char *str);
char				**ft_p_split(char const *s, char c);
char				*ft_p_strdup(const char *src);
char				*ft_p_strtrim(char const *s1, char const *set);
char				*ft_p_strchr(const char *s, int c);
char				*ft_p_substr(char const *s, unsigned int start, size_t len);
char				*ft_p_strjoin(char const *s1, char const *s2);
int					ft_p_strcmp(const char *s1, const char *s2);
size_t				ft_p_strlen(const char *s);
char				*ft_p_itoa(int n);
t_parse_token		*add_token(t_parse_token **token_list,
						size_t index, int type, char *content);
t_parse_token		*create_empty_t_parse_token(void);
void				free_t_parse_token_list(t_parse_token *token_list);
void				free_single_t_parse_token(t_parse_token *token_list);
t_parse_token		*parse_tokenize(char *cmd_string);
void				*parse_safe_free_two_d_char(char **ptr, int max);
void				*parse_safe_free_multi_str(void *ptr1,
						void *ptr2, void *ptr3, void *ptr4);
char				*env_from_str(char *str);
void				env_from_tok(t_parse_token *tok_lst);
void				quotation(t_parse_token *tok_list);
char				**seperate_quote(char *str);
void				space(t_parse_token *tok_lst);
void				parse_tokenize_space_single_tok(t_parse_token *tok);
void				eliminate_space(t_parse_token **tok_lst);
void				pipeline(t_parse_token *tok_lst);
void				redirection(t_parse_token *tok_lst);
void				eliminate_empty_loaf(t_parse_token *tok_lst);
void				collect_argv(t_parse_token *tok_lst);
int					check_syntax(t_parse_token *tok_lst);
t_cmd_list			*handle_syntax_err_tok(t_parse_token *tok_lst);
void				*parse_t_cmd_add_argv(t_cmd *cmd, char *str, int index);
t_cmd_list			*parse_assemble_tokens_to_t_cmd_list(
						t_parse_token *tok_lst);
char				*ft_getenv(char *key);
int					interprete_exe_name(t_cmd *cmd);
int					check_exec_name_is_builtin(t_cmd *cmd);
int					exec_builtin(t_cmd *cmd);
int					get_exitcode(void);
int					ft_heredoc(t_cmd_list *lists, int i);
void				unlink_tmp_file(t_cmd_list *lists);
int					find_env(char **env, char *key);
int					ft_echo(char **argv);
int					ft_pwd(void);
int					ft_env(t_list *list);
int					ft_cd(char **argv, t_list *list);
int					ft_unset(char **argv, t_list *list);
int					ft_export(char **argv, t_list *list);
int					ft_exit(char **argv);
int					ft_exec(t_cmd_list *lists);
void				init_env_and_signal(char **env);
int					init_env(char **env, t_env **head, t_list *list);
int					ft_lstdelone(t_list *list, char *key);
int					ft_is_in_env(t_list	*list, char *key);
t_env				*ft_lstnew(char *key, char *value);
void				ft_lstadd(t_list *list, char *key, char *value);
void				ft_initlist(t_list *list);
void				ft_viewall(t_list *list);
void				ft_update_env(t_list *list, char *key, char *value);
int					ft_strcmp(char *s1, char *s2);
int					ft_isalnum(int c);
int					ft_atoi(const char *nptr);
int					ft_isdigit(int c);
size_t				ft_strlen(char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *src);
char				*ft_substr(char const *s, size_t start, size_t len);
char				*ft_itoa(int n);
int					ft_redirection(t_cmd *cmd);
void				close_fd(t_cmd *cmd, int *stin, int *stout);
void				exec_cmd(t_cmd *cmd, char **env);
void				set_type(t_cmd_list *lists);
void				free_env_list(char **env_list);
char				**get_env_list(t_list *list);
void				signal_handler(int signo);

#endif