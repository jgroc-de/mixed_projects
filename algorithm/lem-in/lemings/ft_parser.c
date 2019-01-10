/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:06:21 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 15:17:11 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

static int	aux_init(t_config *config, char **str)
{
	int	out;

	ft_strdel(str);
	out = ft_rooms(config, str);
	if (out > 0)
	{
		config->len = ft_lstlen(config->rooms);
		if (!(config->matrice = ft_strnew_ch(config->len * config->len, '0')))
			return (ft_usage_error(0));
		out = ft_links(config, str);
	}
	return (out);
}

static int	aux_error(t_config *config)
{
	if (config->ants <= 0)
		return (ft_usage_error(1));
	if (!config->start || !config->end)
		return (ft_usage_error(2));
	if (config->start == config->end)
		return (ft_usage_error(3));
	return (1);
}

static void	aux_gnl(int out)
{
	char *str;

	str = NULL;
	if (out != 0)
	{
		while (get_next_line(0, &str) > 0)
			ft_strdel(&str);
	}
}

int			ft_parser(t_config *config)
{
	char	*str;
	int		out;

	str = NULL;
	while ((out = get_next_line(0, &str)) > 0)
	{
		ft_putendl(str);
		if (*str == '#')
		{
			if (ft_comments(config, str) > 0)
				break ;
		}
		else if (ft_isinteger(str))
		{
			if ((config->ants = ft_atoi(str)) > 0)
				out = aux_init(config, &str);
			break ;
		}
		ft_strdel(&str);
	}
	if (str)
		ft_strdel(&str);
	aux_gnl(out);
	return (aux_error(config) == ERROR ? ERROR : out);
}
