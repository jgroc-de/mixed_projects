/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:22:29 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:22:38 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_printmap(t_fdf *f)
{
	int i;
	int j;

	ft_putstr("\n ---------- \n");
	i = 0;
	while (i < f->len.y)
	{
		j = 0;
		while (f->map[i][j] && j < f->len.x)
		{
			ft_putnbr(f->map[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putstr(" ---------- \n\n");
}
