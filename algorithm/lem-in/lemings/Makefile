# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 11:23:09 by jgroc-de          #+#    #+#              #
#    Updated: 2018/03/19 18:56:57 by jgroc-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -Wall -Werror -Wextra -g -I ../libft
#CFLAGS= -I ../libft
LIBFLAGS= -L../libft -lft
NAME= ../lem-in
LIB = ../libft/libft.a
.phony: all clean fclean re
SRC= $(wildcard *.c)
OBJ= $(subst .c,.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) liblemin.h
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIBFLAGS)

$(LIB):
	make -C ../libft
clean:
	@rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
