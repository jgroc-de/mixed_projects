/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:08 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:36:51 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	ft_mouse(int button, int x, int y, t_frac *f)
{
	t_coord	zoom;

	if (button != 5)
		ft_zoom(f, button);
	if (button == 4 || button == 5)
	{
		zoom = ft_coord(f->zoom * WIDTH, 0);
		zoom = ft_cdiv(ft_cadd(ft_coord(x, y), f->position), zoom);
		if (button == 5)
		{
			f->center = ft_cadd(f->center, ft_coord(-zoom.x, -zoom.y));
			ft_zoom(f, button);
		}
		else
			f->center = ft_cadd(f->center, zoom);
	}
	return (ft_new_mlx(f));
}
