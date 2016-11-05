#include "rtv1.h"

void	ft_print_pixel(t_env *e, int x, int y)
{
	*(e->mlx->data + y * e->mlx->s_line / 4 + x) = 0xff0000;	
}