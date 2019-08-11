/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:00 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:40:11 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static void	aux_color(t_frac *f, int key)
{
	if (key == R)
	{
		if ((f->maj == -1 && (f->mask & 0xFF0000) > 0x010000)
				|| (f->maj == 1 && (f->mask & 0xFF0000) < 0xFF0000))
			f->mask += f->maj * 0x030000;
	}
	else if (key == G)
	{
		if ((f->maj == -1 && (f->mask & 0xFF00) > 0x0100)
				|| (f->maj == 1 && (f->mask & 0xFF00) < 0xFF00))
			f->mask += f->maj * 0x0300;
	}
	else
	{
		if ((f->maj == -1 && (f->mask & 0xFF) > 0x01)
				|| (f->maj == 1 && (f->mask & 0xFF) < 0xFF))
			f->mask += f->maj * 0x03;
	}
}

static void	aux_translate(t_frac *f, int key)
{
	if (key == LEFT)
		f->position.x -= 50 * f->zoom;
	else if (key == UP)
		f->position.y -= 50 * f->zoom;
	else if (key == RIGHT)
		f->position.x += 50 * f->zoom;
	else
		f->position.y += 50 * f->zoom;
}

static void	aux_change_fractal(t_frac *f, int key)
{
	if (key == 65430)
		f->fractale = &ft_mandelbrot;
	else if (key == 65433)
		f->fractale = &ft_julia;
	else if (key == 65435)
		f->fractale = &ft_newton;
	else if (key == 65436)
		f->fractale = &ft_rationnal_map1;
	else if (key == 65439)
		f->fractale = &ft_rationnal_map2;
	else if (key == 65440)
		f->fractale = &ft_rationnal_map3;
	else if (key == 65437)
		f->fractale = &ft_phoenix;
	else if (key == 65438)
		f->fractale = &ft_burningship;
}

static void	aux_misc(t_frac *f, int key)
{
	if (key == 109)
		f->mult += f->maj * 0x10;
	else if (key == ENTER)
		f->print = f->print ? FALSE : TRUE;
	else if (key == TAB)
		f->neg = f->neg ? 0 : 1;
	else if (key == DEPTH)
	{
		f->n += 5 * f->maj;
		if (f->n <= 0)
			f->n = 1;
	}
	else if (key == POWER)
	{
		f->d += f->maj;
		if (f->d > 10)
			f->d = 10;
		else if (f->d < 1)
			f->d = 1;
	}
}

int			ft_key(int key, t_frac *f)
{
	ft_printf("key: %d\n", key);
	if (key == SPACE)
		f->pause = f->pause ? FALSE : TRUE;
	else if (key >= LEFT && key <= DOWN)
		aux_translate(f, key);
	else if (key == BACKSPACE)
		ft_init_param(f);
	else if (key == 109 || key == ENTER || key == TAB
			|| key == DEPTH || key == POWER)
		aux_misc(f, key);
	else if (key >= 65430 && key <= 65437)
		aux_change_fractal(f, key);
	else if (key == R || key == G || key == B)
		aux_color(f, key);
	else if (key == 43 || key == 45)
		ft_zoom(f, key);
	else if (key == MAJ)
		return (f->maj = (f->maj == -1 ? 1 : -1));
	else if (key == ESC || key == 65307)
		ft_exit(f);
	else if (key == 111)
		return (ft_auto(f));
	return (ft_new_mlx(f));
}
