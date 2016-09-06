#include "fractol.h"

void ft_setPixel(t_env *env, int x, int y, int color)
{
	char *pos;

	pos = env->data + y * env->s_line + env->bpp / 8 * x;
	if (color <= 0)
	{
		*pos = 0x00;
		*(pos + 1) = 0x00;
		*(pos + 2) = 0x00;
	}
	else
	{
		*pos = 0x00;
		*(pos + 1) = 0x00;
		*(pos + 2) = 0x00 + color;
	}
	
}

int		ft_si_dans_fractale(t_complexe z, t_complexe c)
{
	int n;
	double tmp;

	n = 0;
	while (n < 50)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		if (z.r * z.r + z.i * z.i > 4)
			return (n * 5);
		n++;
	}
	return (0);

}

void	ft_print_julia(t_env *env)
{
	t_pos pos;
	t_pos som;
	t_complexe u;
	int n;

	env->img = mlx_new_image(env->mlx, 600, 600);
	env->data = mlx_get_data_addr(env->img, &(env->bpp), &(env->s_line), &(env->endian));
	pos.x = 0;
	while (pos.x < 600)
	{
		pos.y = 0;
		while (pos.y < 600)
		{
			u.r = 1.5 * (pos.x - 600 / 2) / (0.5 * env->e.z * 600) + env->e.decal_x;
			u.i = (pos.y - 600 / 2) / (0.5 * env->e.z * 600) + env->e.decal_y;
			if ((n = ft_si_dans_fractale(u, env->c)))
				ft_setPixel(env, pos.x, pos.y, n);
			else
				ft_setPixel(env, pos.x, pos.y, n);
			pos.y++;
		}
		pos.x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}

void	ft_julia(t_env *env)
{
	
	
	ft_print_julia(env);
}