/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:49:20 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:55:43 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_init(t_coord *p)
{
	p->x = 0;
	p->y = 0;
	p->z = 0;
	p->n = 0;
	p->color = 0;
}

void	ft_reset(t_fdf *f)
{
	ft_init(&(f->len));
	ft_init(&(f->max));
	ft_init(&(f->min));
	ft_init(&(f->slate));
	ft_init(&(f->save_rot));
	f->size.x = 2600;
	f->size.y = 1400;
	f->high = 0.9;
	f->k = 20;
	f->high = 0;
	f->rotx = M_PI / 6;
	f->roty = 0;
	f->rotz = M_PI / 4;
}
