/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:22:31 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/08 14:58:56 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countnchr(char *str, int len, char search)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	if (str)
	{
		while (str[i] && i < len)
		{
			if (str[i] == search)
				++count;
			++i;
		}
	}
	return (count);
}
