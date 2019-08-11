/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:31:11 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:31:19 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_factorial(int k)
{
	int	out;

	out = 1;
	while (k > 1)
	{
		out *= k--;
	}
	return (out);
}
