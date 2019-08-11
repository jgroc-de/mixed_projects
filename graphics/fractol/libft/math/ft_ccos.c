/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:30:47 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:31:19 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** n'a pas été vérifiée!!!
*/

t_coord	ft_ccos(t_coord z)
{
	int		k;
	int		fact;
	t_coord	result;

	k = 0;
	result.x = 0;
	result.y = 0;
	while (k < 10)
	{
		fact = ft_factorial(2 * k);
		result = ft_cadd(result, ft_cpow(z, k));
		result.x *= ft_pow(-1, k);
		result.y *= ft_pow(-1, k);
		result.x /= fact;
		result.y /= fact;
		k++;
	}
	return (result);
}
