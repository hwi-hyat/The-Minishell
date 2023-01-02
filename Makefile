NAME	= shell

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lreadline

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re