/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:35:24 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:35:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

void	ft_init_param(t_frac *f)
{
	f->d = 2;
	f->mask = 0x00FCFCF9;
	f->maj = -1;
	f->neg = 1;
	f->pause = 0;
	f->print = 1;
	f->n = 50;
	f->zoom = 0.25;
	f->position.x = -WIDTH / 2;
	f->position.y = -HEIGHT / 2;
	f->center.x = 0;
	f->center.y = 0;
	f->mult = 0xFF;
	f->count = 0;
	if (f->fractale == &ft_julia)
		f->c = ft_coord(-0.0519, 0.688);
	else if (f->fractale == &ft_phoenix)
		f->c = ft_coord(0.5667, 0);
	else
		f->c = ft_coord(0, 0);
}
