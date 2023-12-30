NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFILES = push_swap.c rule_2.c rule_a.c rule_b.c sort.c utils.c func.c

OBJS = $(CFILES:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all