/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:39:11 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/05 11:56:04 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	char	*d;
	int		i;

	d = NULL;
	if (s)
	{
		while (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		len = ft_strlen(s);
		while ((len - 1 >= 0) && (s[len - 1] == ' ' ||
					s[len - 1] == '\n' || s[len - 1] == '\t'))
			len--;
		d = ft_strnew(len);
		if (d)
		{
			i = 0;
			while (i < len)
				d[i++] = *(s++);
			d[i] = '\0';
		}
	}
	return (d);
}
