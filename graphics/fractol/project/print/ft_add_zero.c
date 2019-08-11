/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:52 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:42:34 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static void	aux_add_zero(char *str, double param)
{
	double	test;
	int		i;

	test = param * 10;
	test = test < 0 ? -test : test;
	i = 0;
	while (test < 1 && i < 6)
	{
		ft_strcat(str, "0");
		test *= 10;
		i++;
	}
}

int			ft_add_zero(char *str, double param)
{
	char	*tmp;

	if (param < 1 && param > -1)
		tmp = ft_itoa(ft_abs((int)(param * 100000)));
	else
		tmp = ft_itoa(ft_abs((int)param));
	if (!tmp)
		return (0);
	if (param < 0)
		ft_strcat(str, "-");
	if (param < 1 && param > -1)
	{
		ft_strcat(str, "0.");
		aux_add_zero(str, param);
	}
	ft_strcat(str, tmp);
	free(tmp);
	return (1);
}
