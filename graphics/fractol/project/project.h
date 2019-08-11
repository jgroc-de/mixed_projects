/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroc-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:42:27 by jgroc-de          #+#    #+#             */
/*   Updated: 2019/03/24 16:51:23 by jgroc-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

# include <errno.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/printf/libprintf.h"

# define WIDTH 800
# define HEIGHT 600
# define THREAD 50

/*
** (THREAD - 1) * WIDTH
*/
# define THREADXWIDTH 39200
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

/*
**	mlx param:
**	mlx : mlx "object"
**	win : mlx windows "object" size WIDTH * HEIGHT
**	pic	: mlx image "object"
**	mypic : string describing each pixel of the windows
**	bpp : bits per pixel (usually 4)
**	s_l : size of mypic (width * bpp * height)
**	endian : left / right?
**
**	fractals param:
**	fractale : fonction currrently used to generated the fractale
**	c : constante/variable in formula Zn+1 = Zn^2 + c
**	n : n max for formula Zn+1 = Zn^2 + c
**	d : power for mandelbrot and julia
**
**	colors param:
**	mask : used for color
**	neg : negative color
**	mult : modify something in color "pallette" in ft_color
**	color[] : array containing each colors for the current "pallette"
**
**	controls param: (ourrait etre rassemblée dans une seule variable option)
**	maj : maj key activated? 1 : -1
**	pause : update screen or not
**	print : print debug infos
*/
typedef struct		s_frac
{
	void			*mlx;
	void			*win;
	void			*pic;
	char			*mypic;
	char			*background;
	int				bpp;
	int				s_l;
	int				endian;
	int				count;

	int				(*fractale)(struct s_frac *f, t_coord point);
	t_coord			c;
	int				n;
	int				d;

	t_coord			position;
	t_coord			center;
	double			zoom;

	int				*color;
	int				mask;
	char			neg;
	unsigned int	mult;

	char			maj;
	char			pause;
	char			print;
}					t_frac;

typedef struct		s_multi
{
	t_frac			*save;
	double			zoom;
	int				*mypic;
	t_coord			end;
	int				i;
}					t_multi;

/*
** misc
*/

int					ft_usage(char **av);
void				ft_init_param(t_frac *f);
int					ft_init_color(t_frac *f);
void				ft_exit(t_frac *f);

/*
**	print & debug
*/

int					ft_debug(t_frac *f);
void				ft_print(t_frac *f, char *str, int i);
char				*ft_print_color(t_frac *f, char *out, int j);
char				*ft_print_paramc(t_frac *f, char *str, int i);
int					ft_add_zero(char *str, double param);

/*
** game loop
*/

int					ft_multi_thread(t_frac *f);
int					ft_new_mlx(t_frac *f);
void				*ft_game_loop(void *param);
void				ft_color(t_frac *f, int result, int *color);

/*
**	input management (keyboard/mouse)
*/

int					ft_auto(t_frac *f);
int					ft_key(int key, t_frac *f);
int					ft_mouse(int button, int x, int y, t_frac *f);
int					ft_mouse_move(int x1, int y1, t_frac *f);
void				ft_zoom(t_frac *f, int key);

/*
**	fractale
*/

int					ft_phoenix(t_frac *f, t_coord z);
int					ft_burningship(t_frac *f, t_coord z);
int					ft_julia(t_frac *f, t_coord point);
int					ft_mandelbrot(t_frac *f, t_coord c);
int					ft_newton(t_frac *f, t_coord z);
int					ft_rationnal_map1(t_frac *f, t_coord z);
int					ft_rationnal_map2(t_frac *f, t_coord z);
int					ft_rationnal_map3(t_frac *f, t_coord z);

#endif
