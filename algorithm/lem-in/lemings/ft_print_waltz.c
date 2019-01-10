/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_waltz.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:06:32 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 13:06:57 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

static void	aux_print(t_list *list, t_list *node)
{
	ft_putchar('L');
	ft_putnbr(list->content_size);
	ft_putchar('-');
	ft_putstr(ft_get_name(node));
	if (list->next->content_size)
		ft_putchar(' ');
	else
		ft_putchar('\n');
}

int			ft_print_waltz(t_list *rooms, t_list *list)
{
	t_list	*node;
	int		*array;
	int		i;

	i = 0;
	while (list && list->content_size)
	{
		array = (int*)list->content;
		if (*array != -1)
		{
			i++;
			node = ft_find_node_bynbr(*array, rooms);
			aux_print(list, node);
			list->content += sizeof(int);
		}
		list = list->next;
	}
	return (i);
}
