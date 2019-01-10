/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:04:57 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 15:18:08 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

static void	aux_restore(char *mat, int len, int save)
{
	int j;
	int	line;
	int	box;

	line = save * len;
	j = 0;
	while (j < len)
	{
		box = line + j;
		if (mat[box] < '0' || mat[box] >= 'a')
			mat[box] -= 'a' - '1';
		++j;
	}
}

static int	aux_lstadd(t_config *config, char **ans)
{
	t_list	*node;

	if (!(node = ft_lstnew(NULL, 0)))
		return (ft_usage_error(0));
	node->content = *ans;
	node->content_size = ft_countchr(*ans, '1') + 1;
	if (!(node->content = ft_convert_str2int(config, node)))
	{
		free(node);
		return (ft_usage_error(0));
	}
	ft_lstadd(&(config->paths), node);
	return (1);
}

static char	*aux_find(char *mat, int len)
{
	char *find;

	find = ft_strchr(mat, '1');
	if (find - mat > len)
	{
		return (NULL);
	}
	return (find);
}

int			ft_find_paths(t_config *config, char *mat, char **ans, int i)
{
	char	*find;
	int		save;
	int		diff;

	if (i != ft_get_number(config->end))
	{
		save = i;
		find = aux_find(mat + save * config->len, config->len);
		diff = find - mat;
		i = diff - save * config->len;
		while (find)
		{
			mat[diff] = 'a';
			(*ans)[diff] += 1;
			ft_colorify(config, mat, save, 1);
			if (ft_find_paths(config, mat, ans, i) == ERROR)
				return (ERROR);
			ft_colorify(config, mat, save, -1);
			(*ans)[diff] -= 1;
			find = aux_find(find, config->len - (diff % config->len));
			diff = find - mat;
			i = diff - save * config->len;
			if (!find && save != ft_get_number(config->start))
				aux_restore(mat, config->len, save);
		}
	}
	else
		return (aux_lstadd(config, ans));
	return (i);
}
