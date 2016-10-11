/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:39:36 by ldesprog          #+#    #+#             */
/*   Updated: 2016/09/21 16:39:38 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_key_press_2(int keycode, t_env *e)
{
	if (keycode == 18)
		e->color_nb = 0;
	else if (keycode == 19)
		e->color_nb = 1;
	else if (keycode == 20)
		e->color_nb = 2;
	else if (keycode == 21)
		e->color_nb = 3;
	else if (keycode == 123)
		e->left = 1;
	else if (keycode == 124)
		e->right = 1;
	else if (keycode == 125)
		e->down = 1;
	else if (keycode == 126)
		e->up = 1;
	else if (keycode == 83)
		ft_init(e, 1);
	else if (keycode == 84)
		ft_init(e, 2);
	else if (keycode == 85)
		ft_init(e, 3);
	else if (keycode == 86)
		ft_init(e, 4);
}

int		ft_key_press(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 15)
		ft_init(e, e->fractale);
	else if (keycode == 35 && e->p == 1)
		e->p = 0;
	else if (keycode == 35 && e->p == 0)
		e->p = 1;
	else if (keycode == 69)
		ft_zoom(e, e->mouse);
	else if (keycode == 78)
		ft_dezoom(e, e->mouse);
	else if (keycode == 11 && e->b == 1)
		e->b = 0;
	else if (keycode == 11 && e->b == 0)
		e->b = 1;
	else
		ft_key_press_2(keycode, e);
	return (0);
}

int		ft_key_release(int keycode, t_env *e)
{
	if (keycode == 123)
		e->left = 0;
	else if (keycode == 124)
		e->right = 0;
	else if (keycode == 125)
		e->down = 0;
	else if (keycode == 126)
		e->up = 0;
	return (0);
}

int		ft_mouse_dragg(int x, int y, t_env *e)
{
	if ((e->p == 1 && e->b == 0) || (e->p == 1 && x >= 0 \
		&& x < 600 && y >= 0 && y < 600))
	{
		e->f_mouse.x += ((double)x - e->mouse.x) / e->z;
		e->f_mouse.y += ((double)y - e->mouse.y) / e->z;
	}
	e->mouse.x = x;
	e->mouse.y = y;
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 4)
		ft_zoom(e, e->mouse);
	else if (button == 5)
		ft_dezoom(e, e->mouse);
	return (0);
}
