/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:06:42 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/08 18:33:02 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*str;

	len = 0;
	while (s1[len] && len < n)
		len++;
	if ((str = (char*)malloc(sizeof(*str) * (len + 1))))
	{
		str = ft_strncpy(str, s1, len);
		str[len] = '\0';
	}
	return (str);
}
