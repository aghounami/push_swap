NAME = push_swap
NAME2 = checker
CFLAGS = -Wall -Wextra -Werror
CC = cc
LIBC = ar rcs

bonus =	./utils_bonus/get_next_line.c ./utils_bonus/get_next_line_utils.c \
		check.c sort.c push.c lib_utils.c spliiit.c list.c \
		medien.c main_bonus.c checker_bonus.c utils.c rule_swap.c

src =	list.c main.c check.c sort.c push.c algo.c utils.c \
		target.c medien.c lib_utils.c spliiit.c rule_swap.c 
obj = $(src:.c=.o)
obj2 = $(bonus:.c=.o)

all: $(NAME)

bonus : $(NAME2)

$(NAME): $(obj)
	@$(CC) $(CFLAGS) $(obj) -o $(NAME)
	@echo "all good ✅"

$(NAME2): $(obj2)
	@$(CC) $(CFLAGS) $(obj2) -o $(NAME2)
	@echo "bonus ✅"

%.o: %.c pushswap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(obj) $(obj2)
	@echo "all clean 🧹"

fclean: clean
	@rm -f $(NAME) $(NAME2)

re: fclean all
