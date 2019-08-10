/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multmat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:22:25 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 14:55:46 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_coord	*ft_multmat(float a, float b, float c)
{
	t_coord	*tmp;

	tmp = NULL;
	if (!(tmp = (t_coord*)ft_memalloc(sizeof(t_coord) * 4)))
		return (0);
	tmp[0].x = a;
	tmp[1].y = b;
	tmp[2].z = c;
	tmp[3].n = 1;
	tmp[3].color = 1;
	return (tmp);
}
