# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yseddouk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 20:24:16 by yseddouk          #+#    #+#              #
#    Updated: 2025/03/21 01:55:53 by yseddouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = \
commands.c \
file_utils.c \
utils.c \
processes.c\
pipex.c
OBJ = $(SRC:.c=.o)
PRINTF_DIR = ./ft_printf
LIBFT_DIR = ./libft
INCLUDES = -I$(PRINTF_DIR) -I$(LIBFT_DIR)
LDFLAGS = -L$(PRINTF_DIR) -L$(LIBFT_DIR)
LDLIBS = -lftprintf -lft 
NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

