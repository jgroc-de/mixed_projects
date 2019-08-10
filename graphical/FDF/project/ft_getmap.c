/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:07:36 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:55:48 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static t_list	*aux_read(char *file, t_list *list)
{
	int		fd;
	t_list	*node;
	char	*l;
	int		error;

	fd = open(file, O_RDONLY);
	while ((error = get_next_line(fd, &l) == 1))
	{
		if (!(node = ft_lstnew(NULL, 0)))
			return (NULL);
		if (!(node->content = ft_strsplit(l, ' ')))
			return (NULL);
		free(l);
		ft_lstadd(&list, node);
	}
	if (error == -1)
		return (NULL);
	return (list);
}

static int		*aux_fillmap(char **s, t_fdf *f, int **map)
{
	int		i;
	int		len;
	int		*tab;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	if (!(tab = (int *)ft_memalloc(sizeof(int) * (len + 1))))
		return (NULL);
	if (f->len.x >= 0 && len != f->len.x)
		ft_usage_error(1);
	else if (len != f->len.x)
		f->len.x = len;
	while (s[i])
	{
		tab[i] = ft_atoi(s[i]);
		ft_memdel((void*)(s + i));
		i++;
	}
	*map = tab;
	return (tab);
}

void			aux_freecontent(char **s, int len)
{
	int i;

	i = 0;
	while (i < len && s[i])
	{
		ft_memdel((void*)&s[i++]);
	}
}

int				**ft_getmap(char *file, t_fdf *f)
{
	t_list	*list;
	t_list	*tmp;
	int		**map;

	list = NULL;
	if (!(list = aux_read(file, list)))
		return (NULL);
	if (!(list))
		return (NULL);
	f->len.y = ft_lstlen(list);
	if (!(map = (int **)ft_memalloc(sizeof(*map) * (f->len.y + 1))))
		return (NULL);
	map = map + (int)f->len.y;
	while (list)
	{
		map--;
		if (!(aux_fillmap(list->content, f, map)))
			return (NULL);
		aux_freecontent(list->content, f->len.x);
		ft_memdel(&(list->content));
		tmp = list;
		list = list->next;
		ft_lstdelone(&tmp, &ft_del);
	}
	return (map);
}
