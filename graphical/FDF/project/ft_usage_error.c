/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:51:25 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:51:37 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_usage_error(int a)
{
	if (a == 1)
	{
		ft_putstr("This software reach an error.\n");
		ft_putstr("It could be due to a malloc who failed\n");
		ft_putstr("or a bad input file.\n");
		ft_putstr("Plz insure yourself that the file given is a map.\n");
		ft_putstr("Valid map must be a rectangle.\n");
		ft_putstr("If not, behavior maybe a bit random");
		ft_putstr(" (and i f******* dont care).\n\n");
		ft_putstr("usage: ./fdf map_valide\n");
	}
	else
		ft_putstr("That's all folks!\n");
	exit(1);
}
