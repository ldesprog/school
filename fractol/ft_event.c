# include "fractol.h"

int		ft_red_cross(t_env *env)
{
	exit(0);
}

int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 4)
	{
		printf("roll up\n");
	}
	else if (button == 5)
	{
		printf("roll down\n");
	}
	return (0);
}

int		ft_dragged_mouse(int x, int y, t_env *e)
{
	if (x >= 0 && x < 600 && y >= 0 && y < 600)
	{
		e->souris.x = x;
		e->souris.y = y;
	}
	return (0);
}

int		ft_key_press(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		e->e = ft_zoom(e->e, e->souris);
	}
	else if (keycode == 78)
	{
		e->e = ft_dezoom(e->e, e->souris);
	}
	return (0);
}

int		ft_key_release(int keycode, t_env *env)
{
	printf("key release\n");
	return (0);
}
