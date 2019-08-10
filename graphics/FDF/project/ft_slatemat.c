/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slatemat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:51:01 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:51:16 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_coord	*ft_slate(float a, float b, float c)
{
	t_coord	*tmp;

	tmp = NULL;
	if (!(tmp = (t_coord*)ft_memalloc(sizeof(t_coord) * 4)))
		return (0);
	tmp[0].x = 1;
	tmp[0].n = a;
	tmp[1].y = 1;
	tmp[1].n = b;
	tmp[2].z = 1;
	tmp[2].n = c;
	tmp[3].n = 1;
	return (tmp);
}
