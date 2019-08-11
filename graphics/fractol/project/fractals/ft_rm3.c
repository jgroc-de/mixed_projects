/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:46 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:39:22 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

/*
** f(z,c)= z^3 - 0.0352 * z^-5
*/

int	ft_rationnal_map3(t_frac *f, t_coord z)
{
	int		i;
	t_coord	lambda;

	lambda = ft_coord(0.0352, 0);
	i = 0;
	while (ft_cnorme(z) < 4 && i < f->n)
	{
		z = ft_cadd(ft_cremove(ft_cpow(z, f->d + 1),
					ft_cmult(lambda, ft_cpow(z, -f->d - 3))), f->c);
		i++;
	}
	return (i);
}
