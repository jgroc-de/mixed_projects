/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:13:03 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/11/18 20:19:47 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*d;

	d = NULL;
	if (s)
	{
		len = ft_strlen(s);
		i = 0;
		d = (char*)malloc(len + 1);
		if (d)
		{
			while (*s)
			{
				d[i] = (*f)(i, *(s++));
				i++;
			}
			d[len] = '\0';
		}
	}
	return (d);
}
