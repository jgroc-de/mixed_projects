/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:21:03 by jgroc-de          #+#    #+#             */
/*   Updated: 2017/11/11 18:33:19 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** search a string in an array
** seems dumb…
*/

int	ft_array_search(char *search, char **array)
{
	int	i;

	i = 0;
	if (array && search)
	{
		while (array[i])
		{
			if (ft_strequ(array[i], search))
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}
