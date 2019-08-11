/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:37 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:35:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	ft_newton(t_frac *f, t_coord z)
{
	int		i;
	t_coord	divid;
	t_coord	divis;
	t_coord	drei;

	i = 0;
	drei = ft_coord(3, 0);
	while (ft_cnorme(z) < 64 && i < f->n)
	{
		divid = ft_cpow(z, f->d + 1);
		divid.x -= 1;
		divis = ft_cmult(ft_cpow(z, f->d), drei);
		z = ft_cremove(z, ft_cdiv(divid, divis));
		i++;
	}
	return (i);
}
