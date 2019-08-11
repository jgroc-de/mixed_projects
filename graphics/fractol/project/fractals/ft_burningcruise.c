/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningcruise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:23 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:35:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	ft_burningship(t_frac *f, t_coord c)
{
	int		i;
	t_coord	z;

	z = ft_coord(0, 0);
	i = 0;
	while (ft_cnorme(z) < 16 && i < f->n)
	{
		if (z.x < 0)
			z.x = -z.x;
		if (z.y < 0)
			z.y = -z.y;
		z = ft_cadd(ft_cpow(z, f->d), c);
		i++;
	}
	return (i);
}
