/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:11:18 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/05 11:55:23 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	i = 0;
	d = NULL;
	if (s)
	{
		d = ft_strnew(len);
		if (d)
		{
			while (i < len)
				d[i++] = s[start++];
			d[len] = '\0';
		}
	}
	return (d);
}
