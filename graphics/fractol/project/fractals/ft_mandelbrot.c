/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:31 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:35:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	ft_mandelbrot(t_frac *f, t_coord c)
{
	t_coord	z;
	t_coord	origin;
	int		i;

	i = 0;
	origin = ft_coord(0, 0);
	z = origin;
	while (ft_cnorme(z) < 4 && i < f->n)
	{
		z = ft_cadd(ft_cpow(z, f->d), c);
		i++;
	}
	return (i);
}
