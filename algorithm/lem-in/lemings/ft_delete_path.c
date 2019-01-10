/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:05:36 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/10/10 13:10:31 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblemin.h"

static int	aux_del_path(t_config *config, t_list *current, t_list *tmp)
{
	int		*ref;
	int		*test;
	int		i;
	int		j;

	i = 1;
	ref = current->content;
	test = tmp->content;
	while (ref[i] != -1)
	{
		if (ref[i] != ft_get_number(config->end))
		{
			j = 1;
			while (test[j] != -1 && ref[i] != test[j])
				j++;
			if (ref[i] == test[j])
			{
				tmp = ft_lstpop(tmp, current);
				ft_lstdelone(&tmp, &ft_del_path);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

void		ft_delete_path(t_config *config)
{
	t_list	*current;
	t_list	*save;
	t_list	*tmp;

	current = config->paths;
	while (current)
	{
		tmp = current->next;
		save = current;
		while (tmp)
		{
			if (aux_del_path(config, current, tmp))
				tmp = save->next;
			else
			{
				save = tmp;
				tmp = tmp->next;
			}
		}
		current = current->next;
	}
}
