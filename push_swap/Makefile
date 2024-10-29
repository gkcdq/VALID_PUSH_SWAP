SRCS        = srcs/commands/push.c \
              srcs/commands/rev_rotate.c \
              srcs/commands/rotate.c \
              srcs/commands/sort_stacks.c \
              srcs/commands/sort_three.c \
              srcs/commands/swap.c \
              srcs/push_swap/handle_errors.c \
              srcs/push_swap/a_to_b.c \
              srcs/push_swap/b_to_a.c \
              srcs/push_swap/push_swap.c \
              srcs/push_swap/split.c \
              srcs/push_swap/stack_init.c \
              srcs/push_swap/stack_utils.c

OBJS        = $(SRCS:.c=.o)
NAME        = push_swap
CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror
LDFLAGS     = -Llibft -lft
INCLUDES    = -Ilibft -Iinc

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re