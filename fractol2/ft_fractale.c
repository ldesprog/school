#include "ft_fractol.h"

void	ft_julia(t_env *e, t_complexe c)
{
	t_pos pos;
	t_complexe u;
	int iter;
	double tmp;

	pos.x = -1;
	while (++(pos.x) < 600)
	{
		pos.y = -1;
		while (++(pos.y) < 600)
		{
			u.r = 1.5 * (pos.x - 600 / 2) / (0.5 * e->z * 600) + e->decal_x;
			u.i = (pos.y - 600 / 2) / (0.5 * e->z * 600) + e->decal_y;
			iter = -1;
			while (++iter < 100)
			{
				tmp = u.r;
				u.r = u.r * u.r - u.i * u.i + c.r;
				u.i = 2 * u.i * tmp + c.i;
				if (u.r * u.r + u.i * u.i > 4)
					break;
			}
			ft_set_pixel(pos.x, pos.y, iter, e);
		}
	}
}

void	ft_mandelbrot(t_env *e, t_complexe u)
{
	t_pos pos;
	t_complexe c;
	int iter;
	double tmp;

	pos.x = -1;
	while (++(pos.x) < 600)
	{
		pos.y = -1;
		while (++(pos.y) < 600)
		{
			c.r = 1.5 * (pos.x - 600 / 2) / (0.5 * e->z * 600) + e->decal_x;
			c.i = (pos.y - 600 / 2) / (0.5 * e->z * 600) + e->decal_y;
			iter = -1;
			u.r = c.r;
			u.i = c.i;
			while (++iter < 100)
			{
				tmp = u.r;
				u.r = u.r * u.r - u.i * u.i + c.r;
				u.i = 2 * u.i * tmp + c.i;
				if (u.r * u.r + u.i * u.i > 4)
					break;
			}
			ft_set_pixel(pos.x, pos.y, iter, e);
		}
	}
}
