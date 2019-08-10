/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:07:20 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/07 16:32:23 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int			i;
	const char	*d;

	i = 0;
	d = s;
	while (*d)
	{
		if (*d && *d != c)
		{
			i++;
			while (*d && *d != c)
				d++;
		}
		while (*d && *d == c)
			d++;
	}
	return (i);
}

static int	ft_tabsplit(char **tab, const char *s, char c, int end)
{
	int			j;
	int			i;
	const char	*d;

	j = 0;
	while (*s && j < end)
	{
		i = 0;
		while (*s && *s == c)
			s++;
		d = s;
		while (*s && *(s++) != c)
			i++;
		if (i > 0)
		{
			tab[j] = ft_strndup(d, i);
			if (!(tab[j]))
				return (0);
		}
		j++;
	}
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	int			i;
	char		**tab;

	if (!(s))
		return (NULL);
	i = ft_count_word(s, c);
	if (!(tab = (char **)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	if (!(ft_tabsplit(tab, s, c, i)))
		return (NULL);
	return (tab);
}
