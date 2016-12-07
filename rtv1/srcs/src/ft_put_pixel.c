#include "rtv1.h"

void	ft_print_pixel(t_env *e, int x, int y, double angle)
{
	char *pos;

	if (angle < 0)
		angle *= -1;
	if (angle < 0.1)
		angle = 0.1;
	pos = e->mlx->data + y * e->mlx->s_line + e->mlx->bpp / 8 * x;
	*pos = e->c_hit->b * (float)angle;
	*(pos + 1) = e->c_hit->g * (float)angle;
	*(pos + 2) = e->c_hit->r * (float)angle;
}

void	ft_put_color_from_line(t_obj *obj, char *line, int i)
{
	char *word;

	obj->c = (t_color *)ft_malloc(sizeof(t_color));
	obj->c->r = ft_atodi((word = get_word(line, i)));
	free(word);
	obj->c->g = ft_atodi((word = get_word(line, i + 1)));
	free(word);
	obj->c->b = ft_atodi((word = get_word(line, i + 2)));
	free(word);
}