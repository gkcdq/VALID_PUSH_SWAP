SRCS        = 
OBJS        = $(SRCS:.c=.o)
NAME        = push_swap
CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror
LDFLAGS     = -Llibft -lft
INCLUDES    = -Ilibft 

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

