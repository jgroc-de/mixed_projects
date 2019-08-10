# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 11:23:09 by jgroc-de          #+#    #+#              #
#    Updated: 2018/12/24 13:02:13 by jgroc-de         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
#CFLAGS= -Wall -Werror -Wextra -I .
CFLAGS= -Wall -Werror -Wextra -O3 -I .
AR= ar
ARFLAGS= rcs
NAME= libft.a
.phony: all clean fclean re

SRC_STR=\
ft_array_search.c\
ft_atoi.c\
ft_count.c\
ft_countchr.c\
ft_countnchr.c\
ft_itoa_base.c\
ft_itoa.c\
ft_strcat.c\
ft_strchr.c\
ft_strclr.c\
ft_strcmp.c\
ft_strcpy.c\
ft_strdel.c\
ft_strdup.c\
ft_strequ.c\
ft_striter.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlen.c\
ft_strmap.c\
ft_strmapi.c\
ft_strncat.c\
ft_strncmp.c\
ft_strncpy.c\
ft_strndup.c\
ft_strnequ.c\
ft_strnew.c\
ft_strnew_ch.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strsplit.c\
ft_strstr.c\
ft_strsub.c\
ft_strtabiter.c\
ft_strtrim.c\
ft_tolower.c\
ft_toupper.c\
ft_wcharlen.c\
ft_wstrlen.c\

SRC_BTREE=\
ft_btrcount.c\
ft_btrinsert.c\
ft_btriterin.c\
ft_btriterpre.c\
ft_btritersu.c\
ft_btrnew.c\
ft_btrsearch.c

SRC_IO=\
ft_putchar.c\
ft_putchar_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putnwchar.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_putwchar.c\
ft_putwstr.c\
get_next_line.c\

SRC_IS=\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isinteger.c\
ft_islower.c\
ft_isprime.c\
ft_isprint.c\
ft_isupper.c

SRC_LST=\
ft_del.c\
ft_lst2add.c\
ft_lst2cpy.c\
ft_lst2del.c\
ft_lst2delone.c\
ft_lst2end.c\
ft_lst2insert.c\
ft_lst2iter.c\
ft_lst2lcpy.c\
ft_lst2len.c\
ft_lst2map.c\
ft_lst2new.c\
ft_lst2pop.c\
ft_lst2print.c\
ft_lst2sort.c\
ft_lst2swap.c\
ft_lstadd.c\
ft_lstcpy.c\
ft_lstdel.c\
ft_lstdelone.c\
ft_lstend.c\
ft_lstinsert.c\
ft_lstiter.c\
ft_lstlcpy.c\
ft_lstlen.c\
ft_lstmap.c\
ft_lstnew.c\
ft_lstpop.c\
ft_lstprint.c\
ft_lstsort.c\
ft_lstswap.c

SRC_MEM=\
ft_bzero.c\
ft_memalloc.c\
ft_memccpy.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memdel.c\
ft_memmove.c\
ft_memset.c

SRC_MATH=\
ft_abs.c\
ft_cadd.c\
ft_ccos.c\
ft_cdiv.c\
ft_coord.c\
ft_cmult.c\
ft_cnorme.c\
ft_conj.c\
ft_cpow.c\
ft_cremove.c\
ft_factorial.c\
ft_max.c\
ft_min.c\
ft_nextprime.c\
ft_norme.c\
ft_pow.c\
ft_sqrt.c\
ft_swap.c\

SRC_PRINTF=\
ft_conv_bin.c\
ft_conv_c.c\
ft_conv_d.c\
ft_conv_else.c\
ft_conv_index.c\
ft_conv_lc.c\
ft_conv_ls.c\
ft_conv_oux.c\
ft_conv_p.c\
ft_conv_percent.c\
ft_conv_s.c\
ft_d_size_1.c\
ft_d_size_2.c\
ft_hash.c\
ft_inc_was.c\
ft_init.c\
ft_option.c\
ft_oux_size_1.c\
ft_oux_size_2.c\
ft_plus.c\
ft_precision.c\
ft_printf.c\
ft_width.c\
ft_zero.c

#SRC_MISC=	ft_rand.c

SRC= 	$(addprefix string/,$(SRC_STR))\
		$(addprefix printf/,$(SRC_PRINTF))\
		$(addprefix mem/,$(SRC_MEM))\
		$(addprefix btree/,$(SRC_BTREE))\
		$(addprefix io/, $(SRC_IO))\
		$(addprefix istest/,$(SRC_IS))\
		$(addprefix math/,$(SRC_MATH))\
		$(addprefix lst/,$(SRC_LST))\
#		$(addprefix misc/,$(SRC_MISC))

OBJ=$(subst .c,.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) libft.h printf/libprintf.h io/get_next_line.h
	@echo "building "$(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

clean:
	@echo "deleting "$(OBJ)
	@rm $(OBJ)

fclean: clean
	@echo "deleting "$(NAME)
	rm $(NAME)

re: fclean all
