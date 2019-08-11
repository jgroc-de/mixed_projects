/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:35:31 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:35:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

int	ft_usage(char **av)
{
	ft_printf("Usage: %s <name>\n\twhere <name> can be:\n", av[0]);
	ft_printf("\t\tmandelbrot\n");
	ft_printf("\t\tjulia\n");
	ft_printf("\t\tnewton\n");
	ft_printf("\t\tbs\n");
	ft_printf("\t\tphoenix\n");
	ft_printf("\t\trm1\n");
	ft_printf("\t\trm2\n");
	ft_printf("\t\trm3\n");
	ft_printf("\t\tex: %s Mandelbrot\n", av[0]);
	ft_printf("\t\tcontrol:\n");
	ft_printf("\t\t\tquit: esc\n");
	ft_printf("\t\t\treset: backspace\n");
	ft_printf("\t\t\tdebug info: enter\n");
	ft_printf("\t\t\ttranslation: arrow keys\n");
	ft_printf("\t\t\tzoom: mouse wheel or +/-\n");
	ft_printf("\t\t\ttravel mode: o\n");
	ft_printf("\t\t\tdecrease/increase mode: press one time \"maj\"\n");
	ft_printf("\t\t\tincrease details: n\n");
	ft_printf("\t\t\tincrease power: d\n");
	ft_printf("\t\t\tincrease colors: r/g/b\n");
	ft_printf("\t\t\treverse colors: tab\n");
	return (0);
}
