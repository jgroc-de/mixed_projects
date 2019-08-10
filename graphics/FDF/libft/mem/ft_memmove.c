/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:39:37 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/30 14:51:10 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;
	char		*tmp;

	tmp = (char*)malloc(sizeof(*tmp) * len);
	if (tmp)
	{
		i = 0;
		d = dst;
		s = src;
		while (i < len)
		{
			tmp[i] = s[i];
			i++;
		}
		while (i--)
			d[i] = tmp[i];
		free(tmp);
		return (d);
	}
	return (NULL);
}
