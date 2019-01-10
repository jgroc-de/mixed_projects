/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:53:00 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 13:43:18 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

int	ft_usage_error(int i)
{
	int	fd;

	fd = 1;
	if (i == 0)
		ft_putstr_fd("Error (malloc fail)\n", fd);
	else if (i == 1)
		ft_putstr_fd("Error (no ants)\n", fd);
	else if (i == 2)
		ft_putstr_fd("Error (no start or no end)\n", fd);
	else if (i == 3)
		ft_putstr_fd("Error (start is end)\n", fd);
	else if (i == 4)
		ft_putstr_fd("Error (room start by 'L')\n", fd);
	else if (i == 5)
		return (ft_putstr_fd("Error (more or less than 2 '-')\n", fd));
	else if (i == 6)
		return (ft_putstr_fd(
					"Error (reference to a non-identified node)\n", fd));
	else if (i == 7)
		ft_putstr_fd("Error (start or end set 2 times)\n", fd);
	else if (i == 8)
		ft_putstr_fd("Error (no valid path)\n", fd);
	return (ERROR);
}
