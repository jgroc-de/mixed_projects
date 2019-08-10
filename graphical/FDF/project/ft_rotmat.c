/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotmat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:50:25 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:50:55 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"
#include <math.h>

t_coord	*ft_rotz(t_fdf *f)
{
	t_coord	*tmp;

	tmp = NULL;
	if (!(tmp = (t_coord*)ft_memalloc(sizeof(t_coord) * 4)))
		return (0);
	tmp[0].x = cos(f->rotz);
	tmp[0].y = -sin(f->rotz);
	tmp[1].y = cos(f->rotz);
	tmp[1].x = sin(f->rotz);
	tmp[2].z = 1;
	tmp[3].n = 1;
	f->save_rot.z += f->rotz;
	return (tmp);
}

t_coord	*ft_rotx(t_fdf *f)
{
	t_coord	*tmp;

	tmp = NULL;
	if (!(tmp = (t_coord*)ft_memalloc(sizeof(t_coord) * 4)))
		return (0);
	tmp[0].x = 1;
	tmp[1].y = cos(f->rotx);
	tmp[1].z = -sin(f->rotx);
	tmp[2].y = sin(f->rotx);
	tmp[2].z = cos(f->rotx);
	tmp[3].n = 1;
	f->save_rot.x += f->rotx;
	return (tmp);
}

t_coord	*ft_roty(t_fdf *f)
{
	t_coord	*tmp;

	tmp = NULL;
	if (!(tmp = (t_coord*)ft_memalloc(sizeof(t_coord) * 4)))
		return (0);
	tmp[0].x = cos(f->roty);
	tmp[0].z = sin(f->roty);
	tmp[2].x = -sin(f->roty);
	tmp[2].z = cos(f->roty);
	tmp[1].y = 1;
	tmp[3].n = 1;
	f->save_rot.y += f->roty;
	return (tmp);
}
