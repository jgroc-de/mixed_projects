# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/24 13:10:25 by jgroc-de          #+#    #+#              #
#    Updated: 2019/03/24 16:40:26 by jgroc-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Wall -Werror -Wextra -O3 -I ../libft -I .
##juste pour reminder, inutile.
#CFLAGS= -Wall -Werror -Wextra -O3 -ggdb -fsanitize=address -fsanitize=leak -fno-omit-frame-pointer -I ../libft -I .

#Attention!!! Il faut modifier aussi la regle $(NAME) plus bas
##pour les macs de 42
#MFLAGS= -lmlx -framework OpenGL -framework AppKit -lm
##pour linux
MFLAGS= -L../minilibx -lmlx_Linux -L/usr/X11/lib -lXext -lX11

LIBFT= -L../libft -lft
THREAD= -pthread
NAME= ../fractol
.phony: all clean fclean re

SRC_MAIN=\
ft_color.c\
ft_exit.c\
ft_game_loop.c\
ft_init_color.c\
ft_init_param.c\
ft_multi_thread.c\
ft_new_mlx.c\
ft_usage.c\
main.c\

SRC_EVENTS=\
ft_auto.c\
ft_key.c\
ft_mouse.c\
ft_mouse_move.c\
ft_zoom.c\

SRC_PRINT=\
ft_add_zero.c\
ft_debug.c\
ft_print.c\
ft_print_color.c\
ft_print_paramc.c\

SRC_FRACTALS=\
ft_phoenix.c\
ft_burningcruise.c\
ft_julia.c\
ft_mandelbrot.c\
ft_newton.c\
ft_rm1.c\
ft_rm2.c\
ft_rm3.c\

SRC= 	$(addprefix fractals/,$(SRC_FRACTALS))\
		$(addprefix print/,$(SRC_PRINT))\
		$(addprefix events/,$(SRC_EVENTS))\
		$(SRC_MAIN)

OBJ= $(subst .c,.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) project.h
	@echo "Compilation de "$(NAME)
##pour linux
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIBFT) $(THREAD) $(MFLAGS)
##pour les macs de 42
#	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIBFT) $(MFLAGS)

$(OBJ): project.h

clean:
	@rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
