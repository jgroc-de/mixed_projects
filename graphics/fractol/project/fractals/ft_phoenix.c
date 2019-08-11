/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phoenix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:39 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:35:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	ft_phoenix(t_frac *f, t_coord z)
{
	int		i;
	t_coord	save;
	t_coord	tmp;

	i = 0;
	save = ft_coord(0, 0);
	z = ft_coord(-z.y, -z.x);
	while (ft_cnorme(z) < 8 && i < f->n)
	{
		tmp = z;
		save.x *= -0.5;
		save.y *= -0.5;
		z = ft_cadd(ft_cadd(ft_cpow(z, f->d), f->c), save);
		save = tmp;
		i++;
	}
	return (i);
}
