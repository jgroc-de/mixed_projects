/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:04:57 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 14:47:25 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

int			ft_paths(t_config *config)
{
	char	*ans;

	if (config->matrice)
	{
		if (!(ans = ft_strnew_ch(config->len * config->len, '0')))
			return (ft_usage_error(0));
		if (ft_find_paths(config, config->matrice,
					&ans, ft_get_number(config->start)) == ERROR)
		{
			ft_strdel(&ans);
			return (ERROR);
		}
		if (config->paths)
		{
			//ft_lstiter(config->paths, &ft_print_path);
			//ft_print_matrice(config->matrice, config->len);
		}
		config->paths = ft_lstsort(config->paths, &ft_sort_ans);
		//ft_putendl("del");
		ft_delete_path(config);
		ft_strdel(&ans);
	}
	return (ft_lstlen(config->paths));
}
