/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 20:15:23 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/22 20:15:25 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_key_press_2(int keycode, t_env *e)
{
	if (keycode == 69)
		e->z = 1;
	else if (keycode == 78)
		e->dz = 1;
	else if (keycode == 123)
		e->left = 1;
	else if (keycode == 124)
		e->right = 1;
	else if (keycode == 125)
		e->down = 1;
	else if (keycode == 126)
		e->up = 1;
}

int		ft_key_press(int keycode, t_env *e)
{
	if (keycode == 53)
		ft_free(e);
	else if (keycode == 15)
		e->r = 1;
	else if (keycode == 35 && e->p == 0)
		e->p = 1;
	else if (keycode == 35 && e->p == 1)
		e->p = 0;
	else if (keycode == 18 && e->c1 == 0)
		e->c1 = 255;
	else if (keycode == 19 && e->c2 == 0)
		e->c2 = 255;
	else if (keycode == 20 && e->c3 == 0)
		e->c3 = 255;
	else if (keycode == 18 && e->c1 == 255)
		e->c1 = 0;
	else if (keycode == 19 && e->c2 == 255)
		e->c2 = 0;
	else if (keycode == 20 && e->c3 == 255)
		e->c3 = 0;
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
	else if (keycode == 15)
		e->r = 0;
	else if (keycode == 69)
		e->z = 0;
	else if (keycode == 78)
		e->dz = 0;
	return (0);
}
