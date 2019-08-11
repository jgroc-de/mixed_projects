/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_paramc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:35:10 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:42:49 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

char	*ft_print_paramc(t_frac *f, char *str, int i)
{
	if (f->fractale == &ft_julia)
	{
		ft_strcat(str, "c ([maj] mouse): (");
		if (!ft_add_zero(str, f->c.x))
			return (NULL);
		ft_strcat(str, ", ");
		if (!ft_add_zero(str, f->c.y))
			return (NULL);
		ft_print(f, ft_strcat(str, ")"), i);
	}
	return (str);
}
