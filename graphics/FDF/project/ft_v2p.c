/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v2p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:51:46 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:52:26 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	aux_center(t_fdf *f)
{
	t_coord center;
	t_coord *slate;

	ft_init(&center);
	slate = ft_slate(-(f->min.x), 0, 0);
	ft_fdfvdot(&(slate), f);
	f->max.x -= f->min.x;
	f->min.x = 0;
	f->max.y -= f->min.y;
	slate = ft_slate(0, -(f->min.y), 0);
	ft_fdfvdot(&(slate), f);
	f->max.y -= f->min.y;
	f->min.y = 0;
	center.x = f->size.x / 2 - f->max.x / 2;
	center.y = f->size.y / 2 - f->max.y / 2;
	slate = ft_slate(center.x, center.y, 0);
	ft_fdfvdot(&(slate), f);
}

static void	aux_mmsearch(t_fdf *f)
{
	int		i;
	int		j;

	i = 0;
	while (i < f->len.y)
	{
		j = 0;
		while (j < f->len.x)
		{
			if (f->grid[i][j].x > f->max.x)
				f->max.x = f->grid[i][j].x;
			else if (f->grid[i][j].x < f->min.x)
				f->min.x = f->grid[i][j].x;
			if (f->grid[i][j].y > f->max.y)
				f->max.y = f->grid[i][j].y;
			else if (f->grid[i][j].y < f->min.y)
				f->min.y = f->grid[i][j].y;
			if (f->grid[i][j].color > f->max.color)
				f->max.color = f->grid[i][j].color;
			else if (f->grid[i][j].color < f->min.color)
				f->min.color = f->grid[i][j].color;
			j++;
		}
		i++;
	}
}

int			ft_v2p(t_fdf *f)
{
	t_coord *mat;

	f->max = f->grid[0][0];
	f->min = f->grid[0][0];
	aux_mmsearch(f);
	aux_center(f);
	if ((f->pas.x = (f->size.x - 2 * f->k) / f->max.x) < 1)
		f->pas.x = 1;
	if ((f->pas.y = (f->size.y - 2 * f->k) / f->max.y) < 1)
		f->pas.y = 1;
	if (f->pas.x < f->pas.y)
		f->pas.y = f->pas.x;
	else
		f->pas.x = f->pas.y;
	mat = ft_slate(-f->size.x / 2, -f->size.y / 2, 0);
	ft_fdfvdot(&mat, f);
	mat = ft_multmat(f->pas.x, f->pas.x, f->pas.x);
	ft_fdfvdot(&(mat), f);
	mat = ft_slate(f->size.x / 2, f->size.y / 2, 0);
	ft_fdfvdot(&(mat), f);
	return (1);
}
