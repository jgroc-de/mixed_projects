/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:30:48 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/10 14:42:56 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_reset(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i1;
	int		i2;
	char	*d;

	d = NULL;
	ft_reset(&i1, &i2);
	if (s1 && s2)
	{
		d = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (d)
		{
			while (s1[i1])
			{
				d[i1] = s1[i1];
				i1++;
			}
			while (s2[i2])
			{
				d[i1 + i2] = s2[i2];
				i2++;
			}
			d[i1 + i2] = '\0';
		}
	}
	return (d);
}
