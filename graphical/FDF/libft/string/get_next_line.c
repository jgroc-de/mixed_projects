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

#include "get_next_line.h"
#include "../printf/libprintf.h"

char	*aux_join(char **line, t_list *node, int max)
{
	t_list	*tmp;
	int		len;
	char	*test;

	tmp = node;
	if (!tmp)
		return (NULL);
	if ((test = ft_strchr(tmp->content, '\n')))
	{
		len = test - (char*)tmp->content;
		(*line)[max] = '\0';
		max -= len;
		ft_strncpy(*line + max, tmp->content, len);
		tmp = tmp->next;
	}
	while (tmp)
	{
		max -= tmp->content_size;
		ft_strncpy(*line + max, tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	ft_lstdel(&node, &ft_del);
	return (*line);
}

int	aux_lstadd(t_list **node, char *save, int *status, int *len)
{
	t_list	*tmp;
	char	*test;

	if (!(tmp = ft_lstnew(save, *status + 1)))
		return (0);
	((char*)tmp->content)[*status] = '\0';
	tmp->content_size--;
	ft_lstadd(node, tmp);
	ft_bzero(save, BUFF_SIZE + 1);
	if ((test = ft_strchr(tmp->content, '\n')))
	{
		*len += test - (char*)tmp->content;
		ft_strcpy(save, test + 1);
		return (2);
	}
	else
	{
		*len += *status;
		return (1);
	}
}

int		aux_read_loop(t_list **node, char *save, const int fd, int *status)
{
	int	len;
	int	out;

	out = 1;
	len = 0;
	if (*status > 0)
	{
		if (!(out = aux_lstadd(node, save, status, &len)))
			return (-1);
	}
	while (*status && out == 1)
	{
		if ((*status = read(fd, save, BUFF_SIZE)) == -1)
			return (-1);
		if (*status && !(out = aux_lstadd(node, save, status, &len)))
			return (-1);
	}
	save[*status] = '\0';
	return (len);
}

int				get_next_line(const int fd, char **line)
{
	static char		save[BUFF_SIZE + 1];
	t_list			*node;
	int				len;
	int				status;

	node = NULL;
	if (!(status = ft_strlen(save)))
		status = -1;
	if (fd < 0 || !(line))
		return (ERROR);
	if ((len = aux_read_loop(&node, save, fd, &status)) == -1)
		return (ERROR);
	if (!(*line = ft_strnew(len)))
	{
		ft_lstdel(&node, &ft_del);
		return (-1);
	}
	aux_join(line, node, len);
	if (len == 0 && status == 0)
		free(*line);
	return (status >= 1? 1 : 0);
}
