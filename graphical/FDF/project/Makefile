# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/24 13:10:25 by jgroc-de          #+#    #+#              #
#    Updated: 2018/12/24 13:12:40 by jgroc-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Wall -Werror -Wextra -O3 -I ../libft -I .
#MFLAGS= -lmlx -framework OpenGL -framework AppKit -lm
MFLAGS= -L../minilibx -lmlx_Linux -L/usr/X11/lib -lXext -lX11
LIBFT= -L../libft -lft
MATH= -lm
THREAD= -pthread
NAME= ../FDF
.phony: all clean fclean re

SRC=\
ft_fdf.c\
ft_fdfvdot.c\
ft_freegrid.c\
ft_getmap.c\
ft_high.c\
ft_key.c\
ft_keyrot.c\
ft_mkgrid.c\
ft_multmat.c\
ft_printmap.c\
ft_reset.c\
ft_rotmat.c\
ft_slatemat.c\
ft_usage_error.c\
ft_v2p.c\
main.c\

OBJ= $(subst .c,.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) libfdf.h
	@echo "Compilation de "$(NAME)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIBFT) $(MATH) $(THREAD) $(MFLAGS)

$(OBJ): libfdf.h

clean:
	@rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
