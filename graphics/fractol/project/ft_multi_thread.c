/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:35:26 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/01/24 14:35:44 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "project.h"

static void	aux_start_thread(t_frac *f, pthread_t *thread, t_coord end)
{
	int		i;
	int		*cast;
	t_multi	param[THREAD];
	double	zoom;

	cast = (int*)f->mypic;
	zoom = f->zoom * WIDTH;
	i = 0;
	while (i < THREAD)
	{
		param[i].end = end;
		param[i].zoom = zoom;
		param[i].mypic = cast + i * WIDTH;
		param[i].save = f;
		param[i].i = i;
		pthread_create(&thread[i], NULL, ft_game_loop, &param[i]);
		i++;
	}
}

static void	aux_close_thread(pthread_t *thread)
{
	int	i;

	i = 0;
	while (i < THREAD)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}

int			ft_multi_thread(t_frac *f)
{
	pthread_t	thread[THREAD];
	t_coord		end;

	end = ft_coord(WIDTH + f->position.x, HEIGHT + f->position.y);
	aux_start_thread(f, thread, end);
	aux_close_thread(thread);
	return (1);
}
