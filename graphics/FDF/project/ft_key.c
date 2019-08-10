/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:22:16 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 17:43:32 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

static void	aux_slate(int key, t_fdf *f)
{
	t_coord *mat;

	ft_init(&(f->slate));
	if (key == 123)
		f->slate.x -= 20;
	else if (key == 126)
		f->slate.y -= 20;
	else if (key == 124)
		f->slate.x += 20;
	else if (key == 125)
		f->slate.y += 20;
	mat = ft_slate(f->slate.x, f->slate.y, 0);
	ft_fdfvdot(&(mat), f);
}

static void	aux_zoom(int key, t_fdf *f)
{
	t_coord	*mat;
	float	pas;

	if (key == 24)
		pas = 1.3333;
	else
		pas = 0.75;
	mat = ft_slate(-f->size.x / 2, -f->size.y / 2, 0);
	ft_fdfvdot(&(mat), f);
	mat = ft_multmat(pas, pas, pas);
	ft_fdfvdot(&(mat), f);
	mat = ft_slate(f->size.x / 2, f->size.y / 2, 0);
	ft_fdfvdot(&(mat), f);
}

static int	aux_reset(t_fdf *f)
{
	t_coord *mat;
	t_coord	len;

	len = f->len;
	ft_freegrid(f);
	ft_reset(f);
	f->len = len;
	if (!(ft_mkgrid(f)))
		ft_usage_error(1);
	mat = ft_rotz(f);
	ft_fdfvdot(&(mat), f);
	mat = ft_rotx(f);
	ft_fdfvdot(&(mat), f);
	if (ft_v2p(f) == 0)
		ft_usage_error(1);
	return (1);
}

int			ft_key(int key, t_fdf *f)
{
	if (key == 6 || key == 0)
		ft_keyrot(key, f, &ft_rotz);
	else if (key == 7 || key == 1)
		ft_keyrot(key, f, &ft_rotx);
	else if (key == 8 || key == 2)
		ft_keyrot(key, f, &ft_roty);
	else if (key == 69 || key == 78)
		ft_high(key, f);
	else if (key == 24 || key == 27)
		aux_zoom(key, f);
	else if (key == 126 || key == 125 || key == 124 || key == 123)
		aux_slate(key, f);
	else if (key == 49)
		aux_reset(f);
	else if (key == 53)
		ft_usage_error(2);
	else
		return (1);
	mlx_destroy_image(f->mlx, f->pic);
	f->pic = mlx_new_image(f->mlx, f->size.x, f->size.y);
	f->mypic = mlx_get_data_addr(f->pic, &(f->bpp), &(f->s_l), &(f->endian));
	ft_fdf(*f);
	mlx_put_image_to_window(f->mlx, f->win, f->pic, 0, 0);
	return (1);
}
