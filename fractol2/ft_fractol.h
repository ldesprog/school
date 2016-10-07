/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:39:56 by ldesprog          #+#    #+#             */
/*   Updated: 2016/09/21 16:39:57 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_pos
{
	double x;
	double y;
}				t_pos;

typedef struct	s_complexe
{
	double r;
	double i;
}				t_complexe;

typedef struct	s_palette {
	int			color_default;
	int			color_0;
	int			color_1;
	int			color_2;
	int			color_3;
	int			color_4;
	int			color_5;
	int			color_6;
	int			color_7;
	int			color_8;
	int			color_9;
}				t_palette;

typedef struct	s_env
{
	void		*mlx;
	void		*img;
	void		*win;
	int			*data;
	int			bpp;
	int			s_line;
	int			endian;
	t_pos		mouse;
	t_pos		f_mouse;
	t_complexe	u;
	t_complexe	c;
	double		z;
	double		decal_x;
	double		decal_y;
	int			fractale;
	int			p;
	t_palette	*color;
	int			color_nb;
	int			up;
	int			down;
	int			left;
	int			right;
	int			b;
}				t_env;

/*
** main
*/
void			ft_print_usage();
void			ft_check_param(int ac, char **av, t_env *e);
int				ft_gestion_fractal(t_env *e);
void			ft_init(t_env *e, int nb_fract);
int				main(int ac, char **av);

/*
** ft_fractal
*/
int				ft_is_fractal(int iter, t_complexe *u, t_complexe c);
void			ft_julia(t_env *e, t_complexe c);
void			ft_mandelbrot(t_env *e, t_complexe u);
void			ft_mandelbart(t_env *e, t_complexe u);
int				ft_red_cross(t_env *e);

/*
** ft_event
*/
int				ft_key_press(int keycode, t_env *e);
int				ft_key_release(int keycode, t_env *e);
int				ft_mouse_dragg(int x, int y, t_env *e);
int				ft_mouse_hook(int button, int x, int y, t_env *e);

/*
** ft_paint
*/
void			ft_set_pixel(int x, int y, int iter, t_env *e);
void			ft_color_init(t_env *e);

/*
** ft_calc
*/
void			ft_zoom(t_env *e, t_pos mouse);
void			ft_dezoom(t_env *e, t_pos mouse);

#endif
