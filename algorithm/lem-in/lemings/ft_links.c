/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:06:25 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 14:49:28 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

static int	aux_update_matrice(t_config *config, char *s1, char *s2)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	tmp = ft_find_node_byname(s1, config->rooms);
	tmp2 = ft_find_node_byname(s2, config->rooms);
	if (tmp && tmp2)
	{
		i = ft_get_number(tmp) * config->len + ft_get_number(tmp2);
		config->matrice[i] = '1';
		i = ft_get_number(tmp2) * config->len + ft_get_number(tmp);
		config->matrice[i] = '1';
		return (1);
	}
	return (ft_usage_error(6));
}

static int	aux_get_link(t_config *config, char *line)
{
	char	*s1;
	char	*s2;
	int		out;

	if ((s2 = ft_strchr(line, '-')) && s2 == ft_strrchr(line, '-'))
	{
		if (!(s1 = ft_strndup(line, s2 - line)))
			return (ft_usage_error(0));
		if (s1 && (s2 = ft_strdup(s2 + 1)))
			out = aux_update_matrice(config, s1, s2);
		ft_strdel(&s1);
		if (!s2)
			return (ft_usage_error(0));
		ft_strdel(&s2);
		return (out);
	}
	return (ft_usage_error(5));
}

int			ft_links(t_config *config, char **str)
{
	int	out;

	out = 1;
	if (*str)
	{
		ft_putendl(*str);
		out = aux_get_link(config, *str);
		ft_strdel(str);
	}
	while (out > 0 && (out = get_next_line(0, str)) > 0)
	{
		ft_putendl(*str);
		if (**str != '#')
			out = aux_get_link(config, *str);
		ft_strdel(str);
	}
	return (out);
}
