/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:35:22 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:41:23 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static int	aux_compute_color(t_frac *f, int j)
{
	if (f->neg)
		j = 255 - j;
	return ((j * f->mask) & f->mask);
}

int			ft_init_color(t_frac *f)
{
	int	i;
	int	j;

	if (f->color)
		free(f->color);
	if (!(f->color = (int*)malloc(sizeof(int) * (f->n + 1))))
		return (0);
	i = 0;
	while (i < f->n + 1)
	{
		j = i * 255 / f->n;
		f->color[i++] = aux_compute_color(f, j);
	}
	return (1);
}
