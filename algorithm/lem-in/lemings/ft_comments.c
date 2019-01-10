/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:05:18 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 13:08:50 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

int	ft_comments(t_config *config, char *str)
{
	if (ft_strequ(str, "##start"))
	{
		if (config->start)
			return (ft_usage_error(7));
		return (1);
	}
	else if (ft_strequ(str, "##end"))
	{
		if (config->end)
			return (ft_usage_error(7));
		return (2);
	}
	return (0);
}
