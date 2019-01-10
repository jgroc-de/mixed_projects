/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:06:30 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 14:40:51 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

void	ft_lstprint_room(t_list *list)
{
	t_room	*room;

	room = (t_room *)list->content;
	ft_putnbr(room->number);
	ft_putstr(" ");
	ft_putstr(room->name);
	ft_putstr(" ");
	ft_putnbr(room->x);
	ft_putstr(" ");
	ft_putnbr(room->y);
	ft_putendl("");
}

void	ft_print_matrice(char *str, int len)
{
	int	i;

	i = 0;
	ft_putendl("--- matrice ---");
	while (str[i])
	{
		if (i && !(i % len))
			ft_putchar('\n');
		ft_putchar(str[i]);
		++i;
	}
	ft_putchar('\n');
	ft_putendl("------");
}

void	ft_print_info(t_config *config)
{
	ft_putstr("fourmi:");
	ft_putendl(ft_itoa(config->ants));
	ft_putendl("rooms:");
	ft_lstiter(config->rooms, &ft_lstprint_room);
	ft_putendl("start:");
	ft_lstprint_room(config->start);
	ft_putendl("end:");
	ft_lstprint_room(config->end);
	ft_putendl("links:");
	ft_print_matrice(config->matrice, config->len);
}

void	ft_print_path(t_list *list)
{
	int	i;
	int	*array;

	if (list && list->content)
	{
		ft_putstr("answer: ");
		ft_putnbr((int)list->content_size);
		ft_putendl("");
		array = (int*)list->content;
		i = 0;
		while (array[i] != -1)
		{
			ft_putendl(ft_itoa(array[i++]));
		}
		ft_putendl("next");
	}
}
