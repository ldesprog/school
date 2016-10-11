/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:39:47 by ldesprog          #+#    #+#             */
/*   Updated: 2016/09/21 16:39:49 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int		ft_is_fractal(int iter, t_complexe *u, t_complexe c, int nb)
{
	double tmp;

	while (++iter < 100)
	{
		tmp = (*u).r;
		tmp *= nb;
		(*u).r = (*u).r * (*u).r - (*u).i * (*u).i + c.r;
		(*u).i = 2 * (*u).i * tmp + c.i;
		if ((*u).r * (*u).r + (*u).i * (*u).i > 4)
			break ;
	}
	return (iter);
}

void	ft_julia(t_env *e, t_complexe c)
{
	t_pos		pos;
	t_complexe	u;
	int			iter;

	pos.x = -1;
	while (++(pos.x) < 600)
	{
		pos.y = -1;
		while (++(pos.y) < 600)
		{
			u.r = 1 * (pos.x - 600 / 2) / (0.5 * e->z * 600) + e->decal_x;
			u.i = (pos.y - 600 / 2) / (0.5 * e->z * 600) + e->decal_y;
			iter = ft_is_fractal(-1, &u, c, 1);
			ft_set_pixel(pos.x, pos.y, iter, e);
		}
	}
}

void	ft_mandelbrot(t_env *e, t_complexe u)
{
	t_pos		pos;
	t_complexe	c;
	int			iter;

	pos.x = -1;
	while (++(pos.x) < 600)
	{
		pos.y = -1;
		while (++(pos.y) < 600)
		{
			c.r = 1 * (pos.x - 600 / 2) / (0.5 * e->z * 600) + e->decal_x;
			c.i = (pos.y - 600 / 2) / (0.5 * e->z * 600) + e->decal_y;
			u.r = c.r;
			u.i = c.i;
			iter = ft_is_fractal(-1, &u, c, 1);
			ft_set_pixel(pos.x, pos.y, iter, e);
		}
	}
}

void	ft_mandelbelse(t_env *e, t_complexe u)
{
	t_pos		pos;
	t_complexe	c;

	pos.x = -1;
	while (++(pos.x) < 600)
	{
		pos.y = -1;
		while (++(pos.y) < 600)
		{
			c.r = 1 * (pos.x - 600 / 2) / (0.5 * e->z * 600) + e->decal_x;
			c.i = (pos.y - 600 / 2) / (0.5 * e->z * 600) + e->decal_y;
			u.r = c.r;
			u.i = c.i;
			ft_is_fractal(-1, &u, c, 1);
			ft_set_pixel(pos.x, pos.y, u.r * u.r + u.i * u.i * 20, e);
		}
	}
}

void	ft_tricorn(t_env *e, t_complexe u)
{
	t_pos		pos;
	t_complexe	c;
	int			iter;

	pos.x = -1;
	while (++(pos.x) < 600)
	{
		pos.y = -1;
		while (++(pos.y) < 600)
		{
			c.r = 1 * (pos.x - 600 / 2) / (0.5 * e->z * 600) + e->decal_x;
			c.i = (pos.y - 600 / 2) / (0.5 * e->z * 600) + e->decal_y;
			u.r = c.r;
			u.i = c.i;
			iter = ft_is_fractal(-1, &u, c, -1);
			ft_set_pixel(pos.x, pos.y, iter, e);
		}
	}
}

int		ft_red_cross(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}
