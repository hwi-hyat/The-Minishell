NAME	= minishell

SRCS	=	./main.c \
			./builtin/ft_cd.c \
			./builtin/ft_echo.c \
			./builtin/ft_env.c \
			./builtin/ft_exit.c \
			./builtin/ft_export.c \
			./builtin/ft_pwd.c \
			./builtin/ft_unset.c \
			./env/free_env.c \
			./env/ft_getenv.c \
			./env/ft_initlist.c \
			./env/ft_is_in_env.c \
			./env/ft_lstadd.c \
			./env/ft_lstdel.c \
			./env/ft_lstnew.c \
			./env/ft_lstviewall.c \
			./env/ft_update_env.c \
			./env/get_env_list.c \
			./env/get_exitcode.c \
			./env/init_env_and_signal.c \
			./env/init_env.c \
			./env/utils/ft_atoi.c \
			./env/utils/ft_isalnum.c \
			./env/utils/ft_isdigit.c \
			./env/utils/ft_itoa.c \
			./env/utils/ft_strcmp.c \
			./env/utils/ft_strdup.c \
			./env/utils/ft_strjoin.c \
			./env/utils/ft_strlen.c \
			./env/utils/ft_substr.c \
			./exec/for_exe_part.c \
			./exec/ft_exec.c \
			./exec/ft_exec_two.c \
			./exec/ft_heredoc.c \
			./exec/redirection.c \
			./exec/unlink_tmp_file.c \
			./parsing/assemble_tokens.c \
			./parsing/check_syntax.c \
			./parsing/collect_argv.c \
			./parsing/eliminate_space.c \
			./parsing/env_from_str.c \
			./parsing/env_from_tok.c \
			./parsing/parse_main.c \
			./parsing/parse_tokenize.c \
			./parsing/pipeline.c \
			./parsing/quotation.c \
			./parsing/redirection.c \
			./parsing/space.c \
			./parsing/error/handle_syntax_err_tok.c \
			./parsing/error/parse_err_free_seq.c \
			./parsing/control_cmd/t_cmd_add_argv.c \
			./parsing/control_cmd/t_cmd_create.c \
			./parsing/control_cmd/t_cmd_free.c \
			./parsing/control_cmd/t_cmd_search.c \
			./parsing/control_token/t_parse_token_create.c \
			./parsing/control_token/t_parse_token_free.c \
			./parsing/util/ft_atoi.c \
			./parsing/util/ft_get_last_char.c \
			./parsing/util/ft_itoa.c \
			./parsing/util/ft_split_custom.c \
			./parsing/util/ft_split.c \
			./parsing/util/ft_strchr.c \
			./parsing/util/ft_strcmp.c \
			./parsing/util/ft_strdup_safe.c \
			./parsing/util/ft_strdup.c \
			./parsing/util/ft_strjoin.c \
			./parsing/util/ft_strlen.c \
			./parsing/util/ft_strnstr_custom.c \
			./parsing/util/ft_strsep_custom_io.c \
			./parsing/util/ft_strsep_custom.c \
			./parsing/util/ft_strtrim.c \
			./parsing/util/ft_substr.c 

OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra
READLINE_INC	= $(HOME)/.brew/opt/readline/include
#READLINE_INC	= /opt/homebrew/opt/readline/include
READLINE_LIB	= $(HOME)/.brew/opt/readline/lib
#READLINE_LIB	= /opt/homebrew/opt/readline/lib

%.o:			%.c
				$(CC) $(CFLAGS) -I$(READLINE_INC) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ -I$(READLINE_INC) -L$(READLINE_LIB) -lreadline -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: 			
				make fclean
				make all

.PHONY: 		all, clean, fclean, re