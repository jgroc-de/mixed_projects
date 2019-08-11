/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:35:19 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:40:57 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

void	*ft_game_loop(void *param)
{
	t_multi thread;
	t_coord	point;
	t_frac	*f;

	thread = *(t_multi*)param;
	f = thread.save;
	point.y = f->position.y + thread.i;
	thread.i = 0;
	while (point.y < thread.end.y)
	{
		point.x = f->position.x;
		thread.mypic += thread.i * THREADXWIDTH;
		while (point.x != thread.end.x)
		{
			ft_color(f,
				f->fractale(f, ft_cadd(
					ft_cdiv(point, ft_coord(thread.zoom, 0)), f->center)),
				thread.mypic++);
			point.x++;
		}
		thread.i = 1;
		point.y += THREAD;
	}
	return (NULL);
}
