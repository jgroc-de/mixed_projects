/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:17:45 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/08 14:26:04 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*aux_join_free(char **line, t_gnl *g)
{
	if (*line)
	{
		(*g).tmp = *line;
		if (!(*line = ft_strjoin(*line, (*g).str)))
			return (NULL);
		ft_strdel(&((*g).tmp));
	}
	else
		*line = ft_strdup((*g).str);
	return (*line);
}

static int		aux_ret(char **line, t_gnl *g)
{
	if (g->status == -1)
		return (0);
	g->status = -1;
	(*g).tmp = ft_strchr(*line, '\n');
	if (g->tmp)
	{
		(*g).status = (*g).tmp - *line;
		if (!((*g).ltmp->content = ft_strdup((*g).tmp + 1)))
			return (0);
	}
	if (g->status >= 0)
		(*line)[(*g).status] = '\0';
	return (1);
}

static t_list	*aux_lst_fd(t_list **node, t_gnl *g, int fd)
{
	if (*node)
	{
		(*g).ltmp = *node;
		while ((*g).ltmp)
		{
			if ((*g).ltmp->content_size == (size_t)fd)
				break ;
			(*g).ltmp = (*g).ltmp->next;
		}
		if (!((*g).ltmp))
		{
			if (!((*g).ltmp = ft_lstnew(NULL, 0)))
				return (NULL);
			ft_lstadd(node, (*g).ltmp);
		}
	}
	else
	{
		if (!(*node = ft_lstnew(NULL, fd)))
			return (NULL);
		(*g).ltmp = *node;
	}
	return ((*g).ltmp);
}

int				aux_read(char **line, t_gnl *g, const int fd)
{
	while (g->status > 0)
	{
		if ((g->status = read(fd, g->str, BUFF_SIZE)) == -1)
			return (ERROR);
		g->str[g->status] = '\0';
		if ((g->tmp = ft_strchr(g->str, '\n')))
			g->status = -2;
		if (!(*line = aux_join_free(line, g)))
			return (ERROR);
	}
	return (g->status);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*node;
	t_gnl			g;

	g.status = 1;
	if (!(g.str = ft_strnew(BUFF_SIZE)))
		return (ERROR);
	if (fd < 0 || !(line) || !(g.ltmp = aux_lst_fd(&node, &g, fd)))
	{
		free(g.str);
		return (ERROR);
	}
	if (g.ltmp->content && !(*line = NULL))
		*line = ft_strdup((char*)g.ltmp->content);
	if (*line && (g.tmp = ft_strchr(*line, '\n')))
		g.status = -2;
	if (g.status > 0)
		g.status = aux_read(line, &g, fd);
	ft_strdel((char**)&(g.ltmp->content));
	ft_strdel(&(g.str));
	if (g.status || (*line && ft_strcmp(*line, "") != 0))
		return ((g.status = aux_ret(line, &g)) ? 1 : -1);
	ft_strdel(line);
	g.ltmp = ft_lstpop(g.ltmp, node);
	ft_lstdelone(&(g.ltmp), &ft_del);
	return (0);
}
