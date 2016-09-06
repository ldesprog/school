#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

#include <stdio.h>

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

typedef struct	s_env
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*data;
	int		bpp;
	int		s_line;
	int		endian;
	t_pos	mouse;
	t_pos	f_mouse;
	t_complexe	u;
	t_complexe	c;
	double		z;
	double		decal_x;
	double		decal_y;
	int			fractale;
}				t_env;

//main
void	ft_print_usage();
void	ft_check_param(int ac, char **av, t_env *e);
int		ft_gestion_fractal(t_env *e);
void	ft_init(t_env *e);
int 	main(int ac, char **av);

//ft_fractal
void	ft_julia(t_env *e, t_complexe c);
void	ft_mandelbrot(t_env *e, t_complexe u);

//ft_event
int		ft_red_cross(t_env *e);
int		ft_key_press(int keycode, t_env *e);
int		ft_key_release(int keycode, t_env *e);
int		ft_mouse_dragg(int x, int y, t_env *e);
int		ft_mouse_hook(int button, int x, int y, t_env *e);

//ft_paint
void	ft_set_pixel(int x, int y, int iter, t_env *e);
void	ft_get_color(int iter, t_env *e);

//ft_calc
void	ft_zoom(t_env *e, t_pos mouse);
void	ft_dezoom(t_env *e, t_pos mouse);

#endif
