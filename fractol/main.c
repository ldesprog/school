#include "fractol.h"

t_ecart	ft_zoom(t_ecart e, t_pos souris)
{
	e.z *= 1.01;
	e.decal_x += ((souris.x - 300) / 600) / (e.z * 33);
	e.decal_y += ((souris.y - 300) / 600) / (e.z * 50);
	return (e);
}

t_ecart	ft_dezoom(t_ecart e, t_pos souris)
{
	e.z /= 1.01;
	e.decal_x -= ((souris.x - 300) / 600) / (e.z * 33);
	e.decal_y -= ((souris.y - 300) / 600) / (e.z * 50);
	return (e);
}

int		ft_gestion_fractal(t_env *env)
{
	if (env->e.z == 1)
	{
		env->c.r = -0.7 + ((double)env->souris.x / (double)600);
		env->c.i = 0.27 + ((double)env->souris.y / (double)600);
	}
	//gestion de la fractal demander
	ft_julia(env);
	return (0);
}

int		main(void)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	if (e->mlx == NULL)
	{
		write(1, "error, unable to launch mlx\n", 28);
		exit(0);
	}
	e->win = mlx_new_window(e->mlx, 600, 600, "fractol");
	if (e->win == NULL)
		printf("win null\n");
	e->souris.x = 50;
	e->souris.y = 400;
	e->c.r = -0.7;
	e->c.i = 0.27;
	e->e.z = 1.0;
	e->e.decal_x = 0;
	e->e.decal_y = 0;
	mlx_hook(e->win, 2, 0, &ft_key_press, e);
	mlx_hook(e->win, 3, 0, &ft_key_release, e);
	mlx_hook(e->win, 17, 0, &ft_red_cross, e);
	mlx_hook(e->win, 6, 0, &ft_dragged_mouse, e);
	mlx_mouse_hook(e->win, &ft_mouse_hook, e);
	mlx_loop_hook(e->mlx, &ft_gestion_fractal, e);
	mlx_loop(e->mlx);
	mlx_destroy_window(e->mlx, e->win);
	return (0);
}