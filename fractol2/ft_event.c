#include "ft_fractol.h"

int		ft_red_cross(t_env *e)
{
	exit(0);
	return (0);
}

int		ft_key_press(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 69)
		ft_zoom(e, e->mouse);
	else if (keycode == 78)
		ft_dezoom(e, e->mouse);
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	return (0);
}

int		ft_mouse_dragg(int x, int y, t_env *e)
{
	e->f_mouse.x += ((double)x - e->mouse.x) / e->z;
	e->f_mouse.y += ((double)y - e->mouse.y) / e->z;
	e->mouse.x = x;
	e->mouse.y = y;
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
		ft_zoom(e, e->mouse);
	else if (button == 5)
		ft_dezoom(e, e->mouse);
	return (0);
}
