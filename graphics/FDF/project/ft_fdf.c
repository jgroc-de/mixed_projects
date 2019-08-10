/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:06:24 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 18:02:04 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	aux_fill_pixel(t_fdf *f, int x, int y, int color)
{
	int		ind;
	int		*a;

	ind = -1;
	if (x >= 0 && x < f->size.x)
		ind = 4 * (y * f->size.x + x);
	if (ind >= 0 && ind < 4 * f->size.y * f->size.x)
	{
		a = (int*)&(f->mypic[ind]);
		*a = color;
	}
}

int		aux_color(float a, t_fdf *f)
{
	float d;

	d = 0;
	if (a == 0)
		return (0x001E90FF);
	else if (a < 0)
		return (0x0000008B);
	else
	{
		d = f->max.color / 10;
		if (a < d)
			return (0x00336600);
		else if (a < 2 * d)
			return (0x00339900);
		else if (a < 3 * d)
			return (0x00996600);
		else if (a < 8 * d)
			return (0x00663300);
		else
			return (0x00FFFFFF);
	}
}

void	aux_seg(t_fdf f, t_coord a, t_coord b)
{
	t_coord d;
	int		step;
	int		i;

	(void)f;
	d.x = b.x - a.x;
	d.y = b.y - a.y;
	d.color = a.color - b.color;
	if (ft_abs(d.x) > ft_abs(d.y))
		step = ft_abs(d.x);
	else
		step = ft_abs(d.y);
	i = 0;
	while (i < step)
	{
		aux_fill_pixel(&f, a.x + i * d.x / step, a.y + d.y * i / step,
				aux_color(a.color - d.color * i / step, &f));
		i++;
	}
}

void	ft_fdf(t_fdf f)
{
	int		i;
	int		j;

	j = 0;
	while (j < f.len.y)
	{
		i = 0;
		while (i < f.len.x)
		{
			aux_fill_pixel(&f, f.grid[j][i].x, f.grid[j][i].y,
				aux_color(f.grid[j][i].color, &f));
			if (j < f.len.y - 1)
				aux_seg(f, f.grid[j][i], f.grid[j + 1][i]);
			if (i < f.len.x - 1)
				aux_seg(f, f.grid[j][i], f.grid[j][i + 1]);
			i++;
		}
		j++;
	}
}
