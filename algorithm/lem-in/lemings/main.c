/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:06:51 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 13:06:57 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

int			main(void)
{
	t_config	config;

	config.ants = 0;
	config.len = 0;
	config.rooms = NULL;
	config.start = NULL;
	config.end = NULL;
	config.matrice = NULL;
	config.paths = NULL;
	if (ft_parser(&config) != ERROR)
	{
		if (ft_paths(&config) > 0)
		{
			ft_putendl("");
			if (!(ft_antswaltz(&config)))
				ft_usage_error(0);
		}
		else
			ft_usage_error(8);
	}
	ft_lstdel(&config.rooms, &ft_del_room);
	ft_lstdel(&config.paths, &ft_del_path);
	if (config.matrice)
		ft_strdel(&config.matrice);
	return (1);
}
