NAME = push_swap
NAME2 = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CC = cc
LIBC = ar rcs

src = main.c list.c check.c sort.c push.c algo.c utils.c
obj = $(src:.c=.o)

all: comp_start $(NAME)

comp_start:
	@cd libft && make bonus && make
	@echo "libft is ready ✅"

$(NAME): $(obj)
	@$(CC) $(CFLAGS) $(obj) $(NAME2) -o $(NAME)
	@echo "all good ✅"

%.o: %.c pushswap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(obj)
	@cd libft && make clean
	@echo "all clean 🧹"

fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean

re: fclean all
	@cd libft && make re
