/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:31:04 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:31:19 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_coord	ft_cpow(t_coord z, int n)
{
	t_coord	result;

	result = ft_coord(1, 0);
	if (n > 0)
	{
		while (n-- > 0)
		{
			result = ft_cmult(result, z);
		}
	}
	else if (z.x != 0 || z.y != 0)
	{
		while (n++ < 0)
		{
			result = ft_cdiv(result, z);
		}
	}
	return (result);
}
