/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:13 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:36:29 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	ft_mouse_move(int x1, int y1, t_frac *f)
{
	if (f->maj == 1 && ++f->count > 4)
	{
		f->count = 0;
		f->c = ft_coord(
				(double)x1 / (WIDTH / 2) - 1,
				(double)y1 / (HEIGHT / 2) - 1);
		ft_new_mlx(f);
	}
	return (1);
}
