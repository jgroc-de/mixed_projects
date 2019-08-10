# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 11:41:26 by jgroc-de          #+#    #+#              #
#    Updated: 2018/03/19 15:51:18 by jgroc-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.phony: all clean fclean re

all:
	make -C libft
	make -C minilibx
	make -C project

clean:
	make -C libft clean
	make -C minilibx clean
	make -C project clean

fclean:
	make -C libft fclean
	make -C project fclean

re: fclean all
