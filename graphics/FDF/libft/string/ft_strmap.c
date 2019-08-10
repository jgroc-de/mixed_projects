/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:05:16 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/11/14 16:58:54 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*d;
	int		i;

	i = 0;
	d = NULL;
	if (s)
	{
		len = ft_strlen(s);
		d = (char*)malloc(sizeof(*d) * (len + 1));
		if (d)
		{
			while (i < len && *s)
				d[i++] = (*f)(*(s++));
			d[i] = '\0';
		}
	}
	return (d);
}
