/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:30:49 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:31:19 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_coord	ft_cdiv(t_coord dividende, t_coord diviseur)
{
	t_coord	conjug;

	conjug = ft_conj(diviseur);
	diviseur = ft_cmult(diviseur, conjug);
	if (diviseur.x != 0)
	{
		dividende = ft_cmult(dividende, conjug);
		dividende.x = dividende.x / diviseur.x;
		dividende.y = dividende.y / diviseur.x;
	}
	return (dividende);
}
