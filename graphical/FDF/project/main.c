/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 17:39:33 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:55:47 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	aux_init_mlx(t_fdf *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->size.x, f->size.y, "test");
	f->pic = mlx_new_image(f->mlx, f->size.x, f->size.y);
	f->mypic = mlx_get_data_addr(f->pic, &(f->bpp), &(f->s_l), &(f->endian));
}

int			main(int ac, char **av)
{
	t_fdf	f;
	t_coord *mat;

	if (ac != 2)
		ft_usage_error(1);
	ft_reset(&f);
	aux_init_mlx(&f);
	f.len.x = -1;
	if (!(f.map = ft_getmap(av[1], &f)))
		ft_usage_error(1);
	if (f.len.x < 10 && f.len.y < 10)
		ft_printmap(&f);
	if (!(ft_mkgrid(&f)))
		ft_usage_error(1);
	mat = ft_rotz(&f);
	ft_fdfvdot(&(mat), &f);
	mat = ft_rotx(&f);
	ft_fdfvdot(&(mat), &f);
	if (ft_v2p(&f) == 0)
		ft_usage_error(1);
	ft_fdf(f);
	mlx_put_image_to_window(f.mlx, f.win, f.pic, 0, 0);
	mlx_key_hook(f.win, ft_key, &f);
	mlx_loop(f.mlx);
	return (0);
}
