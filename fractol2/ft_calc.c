#include "ft_fractol.h"

void	ft_zoom(t_env *e, t_pos mouse)
{
	double tmp;

	tmp = e->z;
	e->z *= 1.1;
	e->decal_x += ((mouse.x - 300) / 600) / ((e->z - tmp) * 37);
	e->decal_y += ((mouse.y - 300) / 600) / ((e->z - tmp) * 55);
}

void	ft_dezoom(t_env *e, t_pos mouse)
{
	double tmp;

	tmp = e->z;
	e->z /= 1.1;
	e->decal_x += ((mouse.x - 300) / 600) / ((e->z - tmp) * 37);
	e->decal_y += ((mouse.y - 300) / 600) / ((e->z - tmp) * 55);
}