/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcugni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 10:59:23 by zcugni            #+#    #+#             */
/*   Updated: 2017/11/08 17:35:38 by zcugni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int cpt;

	cpt = 0;
	while (src[cpt])
	{
		dst[cpt] = src[cpt];
		cpt++;
	}
	dst[cpt] = '\0';
	return (dst);
}