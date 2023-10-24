NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = operation.c push_swap.c utils.c utils2.c utils3.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re