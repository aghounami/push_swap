NAME = push_swap
NAME2 = ./libfft/libft.a
CFLAGS = -Wall -Wextra
CC = cc
LIBC = ar rcs

src = main.c list.c check.c sort.c push.c algo.c utils.c target.c medien.c
obj = $(src:.c=.o)

all: comp_start $(NAME)

comp_start:
	@cd libfft && make bonus && make
	@echo "libft is ready ✅"

$(NAME): $(obj)
	@$(CC) $(CFLAGS) $(obj) $(NAME2) -o $(NAME)
	@echo "all good ✅"

%.o: %.c pushswap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(obj)
	@cd libfft && make clean
	@echo "all clean 🧹"

fclean: clean
	@rm -f $(NAME)
	@cd libfft && make fclean

re: fclean all
	@cd libfft && make re
