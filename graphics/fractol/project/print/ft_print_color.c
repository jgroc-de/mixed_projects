/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:35:06 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:35:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

char	*ft_print_color(t_frac *f, char *out, int j)
{
	char	*color;
	int		i;

	ft_strcpy(out, "R|G|B ([maj]): ");
	i = 0;
	while (i < 3)
	{
		ft_strcpy(out + 15 + 4 * i, "000");
		if (!(color = ft_itoa((f->mask / ft_pow(0x0100, 2 - i) % 0x0100))))
			return (NULL);
		ft_strcpy(out + 15 + 4 * i + 3 - ft_strlen(color), color);
		free(color);
		i++;
		out[14 + 4 * i] = '|';
	}
	ft_strclr(out + 15 + 4 * i);
	ft_print(f, out, j);
	return (out);
}
