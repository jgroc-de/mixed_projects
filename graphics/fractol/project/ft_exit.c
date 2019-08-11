/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:35:16 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:35:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

void	ft_exit(t_frac *f)
{
	if (f->pic)
		mlx_destroy_image(f->mlx, f->pic);
	if (f->background)
		mlx_destroy_image(f->mlx, f->background);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
		free(f->mlx);
	if (f->color)
		free(f->color);
	ft_putstr("That's all folks!\n");
	exit(EXIT_SUCCESS);
}
