#include "ft_fractol.h"

void	ft_set_pixel(int x, int y, int iter, t_env *e)
{
	char *pos;

	pos = e->data + y * e->s_line + e->bpp / 8 * x;
	if (iter == 100)
	{
		*pos = 0x00;
		*(pos + 1) = 0x00;
		*(pos + 2) = 0x00;
	}
	else
	{
		*pos = 0x00;
		*(pos + 1) = 0x00;
		*(pos + 2) = 0x00 + iter * 5;
	}
}

void	ft_get_color(int iter, t_env *e)
{
	;
}
