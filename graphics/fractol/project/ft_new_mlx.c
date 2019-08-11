/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:35:29 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:41:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	ft_new_mlx(t_frac *f)
{
	if (!f->pause)
	{
		mlx_destroy_image(f->mlx, f->pic);
		f->pic = mlx_new_image(f->mlx, WIDTH, HEIGHT);
		f->mypic = mlx_get_data_addr(
				f->pic, &(f->bpp), &(f->s_l), &(f->endian));
		if (!ft_init_color(f))
			return (0);
		ft_multi_thread(f);
		mlx_put_image_to_window(f->mlx, f->win, f->pic, 0, 0);
	}
	if (f->print)
	{
		mlx_put_image_to_window(f->mlx, f->win, f->background, 20, 20);
		if (!ft_debug(f))
		{
			ft_putstr(strerror(errno));
			return (0);
		}
	}
	return (1);
}
