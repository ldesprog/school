#include "rtv1.h"

void	ft_print_pixel(t_env *e, int x, int y, double angle)
{
	char *pos;

	if (angle < 0)
		angle *= -1;
	pos = e->mlx->data + y * e->mlx->s_line + e->mlx->bpp / 8 * x;
	*pos = e->o_hit->c->b * (float)angle;
	*(pos + 1) = e->o_hit->c->g * (float)angle;
	*(pos + 2) = e->o_hit->c->r * (float)angle;
}

void	ft_put_color(t_obj *obj, int r, int g, int b)
{
	obj->c = (t_color *)ft_malloc(sizeof(t_color));
	obj->c->r = r;
	obj->c->g = g;
	obj->c->b = b;
}