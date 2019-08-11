/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:19 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:36:17 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"
#include <float.h>

void	ft_zoom(t_frac *f, int key)
{
	if (key == 43 || key == 4)
		f->zoom *= 2;
	else
		f->zoom /= 2;
	if (f->zoom == 0)
		f->zoom = 1;
}
