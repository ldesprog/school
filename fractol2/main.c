/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:40:10 by ldesprog          #+#    #+#             */
/*   Updated: 2016/09/21 16:40:12 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_print_usage(void)
{
	write(1, "usage: fractol [julia, mandelbrot, mandelbart]\n", 47);
	exit(0);
}

void	ft_check_param(int ac, char **av, t_env *e)
{
	if (ac != 2)
		ft_print_usage();
	if (ft_strcmp(av[1], "julia") == 0)
		e->fractale = 1;
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
		e->fractale = 2;
	else if (ft_strcmp(av[1], "mandelbart") == 0)
		e->fractale = 3;
	else
		ft_print_usage();
}

int		ft_gestion_fractal(t_env *e)
{
	if (e->up == 1)
		e->decal_y += 0.05 / e->z;
	if (e->down == 1)
		e->decal_y -= 0.05 / e->z;
	if (e->left == 1)
		e->decal_x += 0.05 / e->z;
	if (e->right == 1)
		e->decal_x -= 0.05 / e->z;
	if (e->fractale == 1)
	{
		e->c.r = -0.7 + ((double)e->f_mouse.x / (double)600 / 2);
		e->c.i = 0.27 + ((double)e->f_mouse.y / (double)600 / 2);
		ft_julia(e, e->c);
	}
	else if (e->fractale == 2)
		ft_mandelbrot(e, e->u);
	else if (e->fractale == 3)
		ft_mandelbart(e, e->u);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	ft_init(t_env *e, int nb_fract)
{
	e->fractale = nb_fract;
	e->mouse.x = 300;
	e->mouse.y = 300;
	e->f_mouse.x = 300;
	e->f_mouse.y = 300;
	if (e->fractale == 1)
		e->decal_x = 0;
	else
		e->decal_x = -0.5;
	e->decal_y = 0;
	e->z = 1;
	e->u.r = 0;
	e->u.i = 0;
	e->p = 1;
	ft_color_init(e);
	e->color_nb = 2;
	e->b = 1;
}

int		main(int ac, char **av)
{
	t_env *e;

	e = (t_env *)ft_malloc(sizeof(t_env));
	ft_check_param(ac, av, e);
	e->mlx = mlx_init();
	if (e->mlx == NULL)
	{
		write(1, "error, unable to launch mlx\n", 28);
		exit(0);
	}
	e->win = mlx_new_window(e->mlx, 600, 600, "fractol");
	e->img = mlx_new_image(e->mlx, 600, 600);
	e->data = (int *)mlx_get_data_addr(e->img, &(e->bpp), \
		&(e->s_line), &(e->endian));
	mlx_hook(e->win, 2, 0, &ft_key_press, e);
	mlx_hook(e->win, 3, 0, &ft_key_release, e);
	mlx_hook(e->win, 17, 0, &ft_red_cross, e);
	mlx_hook(e->win, 6, 0, &ft_mouse_dragg, e);
	mlx_mouse_hook(e->win, &ft_mouse_hook, e);
	mlx_loop_hook(e->mlx, &ft_gestion_fractal, e);
	ft_init(e, e->fractale);
	mlx_loop(e->mlx);
	return (0);
}
