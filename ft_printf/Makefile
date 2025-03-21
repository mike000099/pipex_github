CC= cc
CFLAGS = -Wall -Wextra -Werror
NAME= libftprintf.a
RM= rm -f
SRC= \
ft_putchar_pf.c\
ft_putstr_pf.c\
ft_putptr_pf.c\
ft_putnbr_pf.c\
ft_puthex_pf.c\
ft_putuint_pf.c\
ft_printf.c

OBJ= $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
