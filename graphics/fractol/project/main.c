/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:35:34 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:53:34 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static int	aux_set_fractale(char **av, t_frac *f)
{
	if (ft_strequ(av[1], "mandelbrot"))
		f->fractale = &ft_mandelbrot;
	else if (ft_strequ(av[1], "julia"))
		f->fractale = &ft_julia;
	else if (ft_strequ(av[1], "newton"))
		f->fractale = &ft_newton;
	else if (ft_strequ(av[1], "bs"))
		f->fractale = &ft_burningship;
	else if (ft_strequ(av[1], "phoenix"))
		f->fractale = &ft_phoenix;
	else if (ft_strequ(av[1], "rm1"))
		f->fractale = &ft_rationnal_map1;
	else if (ft_strequ(av[1], "rm2"))
		f->fractale = &ft_rationnal_map2;
	else if (ft_strequ(av[1], "rm3"))
		f->fractale = &ft_rationnal_map3;
	else
		return (0);
	return (1);
}

static int	aux_init(t_frac *f)
{
	f->color = NULL;
	f->mlx = mlx_init();
	if (!(f->pic = mlx_new_image(f->mlx, WIDTH, HEIGHT)))
	{
		ft_putstr(strerror(errno));
		return (0);
	}
	if (!(f->background = mlx_new_image(f->mlx, 400, 225)))
	{
		ft_putstr(strerror(errno));
		mlx_destroy_image(f->mlx, f->pic);
		return (0);
	}
	if (!(f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol")))
	{
		ft_putstr(strerror(errno));
		mlx_destroy_image(f->mlx, f->pic);
		mlx_destroy_image(f->mlx, f->background);
		return (0);
	}
	f->mypic = mlx_get_data_addr(f->pic, &(f->bpp), &(f->s_l), &(f->endian));
	return (1);
}

int			main(int ac, char **av)
{
	t_frac	f;

	if (ac != 2 || !aux_set_fractale(av, &f))
		ft_usage(av);
	else if (aux_init(&f))
	{
		ft_init_param(&f);
		if (ft_new_mlx(&f))
		{
			mlx_mouse_hook(f.win, ft_mouse, &f);
			if (f.fractale == &ft_julia
					|| f.fractale == &ft_phoenix
					|| f.fractale == &ft_rationnal_map1
					|| f.fractale == &ft_rationnal_map2
					|| f.fractale == &ft_rationnal_map3)
				mlx_hook(f.win, 6, 1L << 6, ft_mouse_move, &f);
			mlx_hook(f.win, 2, 1L << 0, ft_key, &f);
			if (!mlx_loop(f.mlx))
				ft_exit(&f);
		}
	}
	return (EXIT_SUCCESS);
}
