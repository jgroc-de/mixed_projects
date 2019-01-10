/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:31:09 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/12/05 15:18:53 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t end;
	size_t j;

	end = 0;
	j = 0;
	while (end < size && dst[end])
		end++;
	while (src[j] && (end + j + 1) < size)
	{
		dst[end + j] = src[j];
		j++;
	}
	if (end < size)
		dst[end + j] = '\0';
	return (end + ft_strlen(src));
}
