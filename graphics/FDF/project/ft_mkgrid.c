/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkgrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:06:30 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:55:45 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int		ft_mkgrid(t_fdf *f)
{
	int		i;
	int		j;

	if (!(f->grid = (t_coord**)ft_memalloc(sizeof(t_coord*) * (f->len.y))))
		return (0);
	j = 0;
	while (j < f->len.y)
	{
		i = 0;
		if (!(f->grid[j] = (t_coord*)ft_memalloc(sizeof(t_coord) * (f->len.x))))
			return (0);
		while (i < f->len.x)
		{
			f->grid[j][i].x = i;
			f->grid[j][i].y = j;
			f->grid[j][i].z = f->map[j][i];
			f->grid[j][i].n = 1;
			f->grid[j][i].color = f->map[j][i];
			i++;
		}
		j++;
	}
	return (1);
}
