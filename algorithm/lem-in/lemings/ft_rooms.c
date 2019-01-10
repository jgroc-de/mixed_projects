/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:06:36 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 13:12:12 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

static t_room	aux_get_room(char *line)
{
	t_room	room;
	char	**split;

	room.number = -1;
	room.name = NULL;
	if (!(split = ft_strsplit(line, ' ')))
		ft_usage_error(0);
	if (ft_count(split) == 3)
	{
		if ((room.name = ft_strdup(split[0])))
		{
			room.x = ft_atoi(split[1]);
			room.y = ft_atoi(split[2]);
			room.number = 0;
		}
		else
			ft_usage_error(0);
	}
	ft_strtabiter(split, &ft_strdel, 1);
	return (room);
}

static int		aux_set(t_room *room, int *comment, t_config *config)
{
	t_list	*node;

	if (!(node = ft_lstnew(room, sizeof(t_room))))
	{
		ft_strdel(&(room->name));
		return (ft_usage_error(0));
	}
	if (*comment)
	{
		if (*comment == 1)
			config->start = node;
		else if (*comment == 2)
			config->end = node;
		*comment = 0;
	}
	if (config->rooms)
		((t_room *)(node->content))->number = ft_get_number(config->rooms) + 1;
	ft_lstadd(&(config->rooms), node);
	return (1);
}

int				ft_rooms(t_config *config, char **str)
{
	int		i;
	t_room	room;
	int		comment;

	comment = 0;
	while ((i = get_next_line(0, str)) > 0 && !ft_strchr(*str, '-'))
	{
		ft_putendl(*str);
		room.name = NULL;
		if (**str == '#')
		{
			if ((comment = ft_comments(config, *str)) == ERROR)
				return (ERROR);
		}
		else if (**str == 'L')
			return (ft_usage_error(4));
		else
		{
			room = aux_get_room(*str);
			if (!room.name || aux_set(&room, &comment, config) == ERROR)
				return (ERROR);
		}
		ft_strdel(str);
	}
	return (i);
}
