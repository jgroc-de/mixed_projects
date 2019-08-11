/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:34:57 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:43:27 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static char	*aux_power(t_frac *f, char *str, int i)
{
	char	*tmp;

	if (!(tmp = ft_itoa(f->d)))
		return (NULL);
	ft_strcat(str, "power ([maj] d): ");
	ft_strcat(str, tmp);
	free(tmp);
	ft_print(f, str, i);
	return (str);
}

static char	*aux_depth(t_frac *f, char *str, int i)
{
	char	*tmp;

	if (!(tmp = ft_itoa(f->n)))
		return (NULL);
	ft_strcat(str, "depth ([maj] n): ");
	ft_strcat(str, tmp);
	free(tmp);
	ft_print(f, str, i);
	return (str);
}

static void	aux_strcat(char *dest, char *src1, int test)
{
	ft_strclr(dest);
	ft_strcat(dest, src1);
	ft_strcat(dest, test == 1 ? "yes" : "no");
}

static void	aux_strclr(char *str)
{
	int	i;

	i = 0;
	while (i < 100)
		str[i++] = '\0';
}

int			ft_debug(t_frac *f)
{
	char	str[100];
	int		i;

	i = 0;
	aux_strclr(str);
	aux_strcat(str, "pause (space): ", f->pause);
	ft_print(f, str, i++);
	aux_strcat(str, "maj: ", f->maj);
	ft_print(f, str, i++);
	aux_strcat(str, "neg: ", f->neg);
	ft_print(f, str, i++);
	ft_strcat(str, "zoom (+/-): ");
	if (!ft_add_zero(str, f->zoom))
		return (0);
	ft_print(f, str, i++);
	if (!(aux_power(f, str, i++)))
		return (0);
	if (!(aux_depth(f, str, i++)))
		return (0);
	if (!(ft_print_color(f, str, i++)))
		return (0);
	if (!(ft_print_paramc(f, str, i++)))
		return (0);
	return (1);
}
