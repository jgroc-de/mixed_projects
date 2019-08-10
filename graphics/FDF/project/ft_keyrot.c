/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:22:20 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:49:02 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_keyrot(int key, t_fdf *f, t_coord *(*funct)(t_fdf *f))
{
	t_coord *mat;

	if (key == 6)
		f->rotz = M_PI / 36;
	else if (key == 0)
		f->rotz = -M_PI / 36;
	else if (key == 7)
		f->rotx = -M_PI / 6;
	else if (key == 1)
		f->rotx = M_PI / 6;
	else if (key == 8)
		f->roty = -M_PI / 6;
	else if (key == 2)
		f->roty = M_PI / 6;
	mat = ft_slate(-f->size.x / 2, -f->size.y / 2, 0);
	ft_fdfvdot(&(mat), f);
	mat = (*funct)(f);
	ft_fdfvdot(&(mat), f);
	mat = ft_slate(f->size.x / 2, f->size.y / 2, 0);
	ft_fdfvdot(&(mat), f);
}
