/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str2int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:05:27 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 13:09:43 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

static int	aux_get_next(char *matrice, int i)
{
	char	*find;

	find = ft_strchr(matrice + i, '1');
	return (find - (matrice + i));
}

/*
** convert string to int array
*/

int			*ft_convert_str2int(t_config *config, t_list *path)
{
	int		*link;
	int		i;
	int		j;

	i = ft_get_number(config->start);
	if (!(link = (int*)malloc(sizeof(int) * (path->content_size + 1))))
		return (0);
	link[path->content_size] = -1;
	link[0] = i;
	j = 1;
	while (i != ft_get_number(config->end))
	{
		i = aux_get_next((char*)path->content, i * config->len);
		link[j++] = i;
	}
	return (link);
}
