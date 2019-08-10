/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freegrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:22:08 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:40:25 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_freegrid(t_fdf *f)
{
	int i;

	i = 0;
	while (i < f->len.y)
		free(f->grid[i++]);
	free(f->grid);
}
