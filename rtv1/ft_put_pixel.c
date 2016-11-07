#include "rtv1.h"

void	ft_print_pixel(t_env *e, int x, int y, double angle)
{
	char *pos;
	if (angle < 0)
		angle *= -1;
	if ((float)angle != 1)
		printf("%f\n", angle);

	pos = e->mlx->data + y * e->mlx->s_line + e->mlx->bpp / 8 * x;
	*pos = 0xff * (float)angle;
	*(pos + 1) = 0x00;
	*(pos + 2) = 0x00;
}