/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antswaltz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:05:09 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/12 19:07:00 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

static int	aux_waltz(t_list **ant, t_list **path, t_list **waltz)
{
	(*ant)->content = (*path)->content;
	if (!((*ant)->next = ft_lstnew(NULL, 0)))
	{
		ft_lstdel(waltz, &ft_del);
		return (0);
	}
	*ant = (*ant)->next;
	*path = (*path)->next;
	return (1);
}

static int	aux_compare(t_config *config, t_list *path)
{
	t_list	*tmp;
	t_list	*paths;

	paths = config->paths;
	tmp = paths->next;
	if (path->content_size == paths->content_size)
		return (1);
	while (tmp)
	{
		if (path->content_size <= tmp->content_size)
			break ;
		if ((size_t)config->ants <=
				path->content_size - tmp->content_size)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

/*
**		if (path->content_size == 2)
**		{
**			while (config->ants)
**			{
**				config->ants--;
**				ant->content_size = i++;
**				if (!aux_waltz(&ant, &path, &waltz))
**					return (0);
**				path = config->paths;
**			}
**		}
*/

int			ft_antswaltz(t_config *config)
{
	t_list	*path;
	t_list	*waltz;
	t_list	*ant;
	int		i;

	i = 1;
	if (!(waltz = ft_lstnew(NULL, 0)))
		return (0);
	ant = waltz;
	while (ft_print_waltz(config->rooms, waltz) || i == 1)
	{
		path = config->paths;
		while (config->ants && path && aux_compare(config, path))
		{
			config->ants--;
			ant->content_size = i++;
			if (!aux_waltz(&ant, &path, &waltz))
				return (0);
		}
	}
	ft_lstdel(&waltz, &ft_del_void);
	return (1);
}
