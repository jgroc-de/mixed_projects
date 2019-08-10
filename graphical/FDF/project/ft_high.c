/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_high.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:22:13 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:47:02 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	aux_updown_grid(t_fdf *f)
{
	int	i;
	int j;

	i = 0;
	while (i < f->len.y)
	{
		j = 0;
		while (j < f->len.x)
		{
			if (f->grid[i][j].color > 0)
				f->grid[i][j].z *= f->high;
			else if (f->grid[i][j].color < 0)
				f->grid[i][j].z *= f->high;
			j++;
		}
		i++;
	}
}

int			ft_high(int key, t_fdf *f)
{
	t_coord *mat;

	if (key == 69)
		f->high += 0.05;
	else if (key == 78)
		f->high -= 0.05;
	f->rotx = f->save_rot.x;
	f->roty = f->save_rot.y;
	f->rotz = f->save_rot.z;
	ft_freegrid(f);
	ft_init(&(f->save_rot));
	if (!(ft_mkgrid(f)))
		ft_usage_error(1);
	aux_updown_grid(f);
	mat = ft_rotz(f);
	ft_fdfvdot(&(mat), f);
	mat = ft_rotx(f);
	ft_fdfvdot(&(mat), f);
	mat = ft_roty(f);
	ft_fdfvdot(&(mat), f);
	if (ft_v2p(f) == 0)
		ft_usage_error(1);
	return (1);
}
