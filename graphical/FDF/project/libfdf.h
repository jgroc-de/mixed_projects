/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 14:50:33 by jgroc-de          #+#    #+#             */
/*   Updated: 2018/01/25 17:40:59 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H

# include <fcntl.h>
# include <errno.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/printf/libprintf.h"

# define WIDTH 800
# define HEIGHT 800
# define THREAD 8
# define TRUE 1
# define FALSE 0

/*
** keys
*/

# define SPACE 32
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define BACKSPACE 65288
# define ENTER 65293
# define R 114
# define G 103
# define B 98
# define POWER 100
# define DEPTH 110
# define MAJ 65505
# define TAB 65289
# define ESC 53


typedef struct	s_coord3
{
	float	x;
	float	y;
	float	z;
	float	n;
	float	color;
}				t_coord3;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	void		*pic;
	char		*mypic;
	int			bpp;
	int			s_l;
	int			endian;
	t_coord3	size;

	int			**map;
	t_coord3	**grid;
	t_coord3 	max;
	t_coord3 	min;

	t_coord3	slate;
	float		rotx;
	float		roty;
	float		rotz;
	t_coord3 	save_rot;

	t_coord3 	len;
	t_coord3 	pas;
	int			k;
	float		high;
}				t_fdf;

void			ft_init(t_coord3 *p);
void			ft_reset(t_fdf *f);
int				**ft_getmap(char *file, t_fdf *f);
void			ft_printmap(t_fdf *f);
int				ft_mkgrid(t_fdf *f);
int				ft_v2p(t_fdf *f);
void			ft_fdf(t_fdf f);
int				ft_key(int keycode, t_fdf *f);
void			ft_usage_error(int a);

void			ft_fdfvdot(t_coord3 **mult, t_fdf *f);
t_coord3		*ft_multmat(float a, float b, float c);
t_coord3		*ft_slate(float a, float b, float c);
t_coord3		*ft_rotx(t_fdf *f);
t_coord3		*ft_roty(t_fdf *f);
t_coord3		*ft_rotz(t_fdf *f);
void			ft_keyrot(int key, t_fdf *f, t_coord3 *(*funct)(t_fdf *f));
void			aux_updown_map(t_fdf *f);
int				ft_high(int key, t_fdf *f);
void			ft_freegrid(t_fdf *f);

#endif
