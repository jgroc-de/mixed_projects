/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdfvdot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:22:49 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:39:53 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_fdfvdot(t_coord **m, t_fdf *f)
{
	int		i;
	int		j;
	t_coord	tmp;

	i = 0;
	while (i < f->len.y)
	{
		j = 0;
		while (j < f->len.x)
		{
			tmp.x = f->grid[i][j].x * (*m)[0].x + f->grid[i][j].y * (*m)[0].y
				+ f->grid[i][j].z * (*m)[0].z + f->grid[i][j].n * (*m)[0].n;
			tmp.y = f->grid[i][j].x * (*m)[1].x + f->grid[i][j].y * (*m)[1].y
				+ f->grid[i][j].z * (*m)[1].z + f->grid[i][j].n * (*m)[1].n;
			tmp.z = f->grid[i][j].x * (*m)[2].x + f->grid[i][j].y * (*m)[2].y
				+ f->grid[i][j].z * (*m)[2].z + f->grid[i][j].n * (*m)[2].n;
			tmp.n = f->grid[i][j].x * (*m)[3].x + f->grid[i][j].y * (*m)[3].y
				+ f->grid[i][j].z * (*m)[3].z + f->grid[i][j].n * (*m)[3].n;
			tmp.color = f->grid[i][j].color;
			f->grid[i][j] = tmp;
			j++;
		}
		i++;
	}
	ft_memdel((void*)m);
}
