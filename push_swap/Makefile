SRCS        = mvt/push.c mvt/rev_rotate.c mvt/rotate.c mvt/sort_stacks.c mvt/sort_3.c mvt/swap.c mvt/sort_stacks_utils.c\
              parsing.c a_to_b.c b_to_a.c main.c utils3.c stack_init.c stack_tools.c utils2.c parsing_tools.c
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