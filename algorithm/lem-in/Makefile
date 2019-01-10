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

.phony: clean fclean re

all:
	make -C libft
	make -C lemings

clean:
	make -C libft clean
	make -C lemings clean

fclean:
	make -C libft fclean
	make -C lemings fclean

re: fclean all
