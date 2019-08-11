/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:35:09 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/02/08 16:40:34 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(intmax_t n)
{
	char		*str;
	size_t		i;
	intmax_t	number;

	i = 0;
	number = n;
	while ((number = number / 10))
		i++;
	if (n < 0)
		i++;
	if ((str = ft_strnew(i + 1)))
	{
		if (n < 0)
			str[0] = '-';
		else if (n == 0)
			*str = '0';
		while (n)
		{
			str[i--] = ft_abs(n % 10) + '0';
			n = n / 10;
		}
	}
	return (str);
}
