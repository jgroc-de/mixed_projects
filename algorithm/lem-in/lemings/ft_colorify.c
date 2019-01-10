/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:04:57 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 15:18:08 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

static void	aux_increment(char *mat, int ind, int inc)
{
	if (mat[ind] != '0')
		mat[ind] += inc;
}

void		ft_colorify(t_config *config, char *mat, int i, int inc)
{
	int		len;
	int		j;

	len = config->len;
	j = 0;
	if (i != ft_get_number(config->end))
	{
		while (j < len)
		{
			aux_increment(mat, i * len + j, inc);
			aux_increment(mat, j * len + i, inc);
			++j;
		}
	}
}
