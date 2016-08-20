/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:06:50 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/17 15:06:52 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_avance(int i, t_env *e)
{
	int x;
	int y;

	x = 80 * i * cos(M_PI * e->player->dir / 180);
	y = 80 * -1 * i * sin(M_PI * e->player->dir / 180);
	if (e->map[(int)(e->player->pos->y + y) / e->size]
		[(int)(e->player->pos->x + x) / e->size] == 0)
	{
		x = 20 * i * cos(M_PI * e->player->dir / 180);
		y = 20 * -1 * i * sin(M_PI * e->player->dir / 180);
		e->player->pos->x += x;
		e->player->pos->y += y;
		ft_raycast(e);
	}
}

void	ft_tourne(int i, t_env *e)
{
	e->player->dir += i;
	if (e->player->dir >= 360)
		e->player->dir -= 360;
	else if (e->player->dir < 0)
		e->player->dir += 360;
	ft_raycast(e);
}

void	ft_raycast_2(t_env *e, int x, float dir_x, float dir_p)
{
	if (e->b == -1 || (e->a != -1 && e->a < e->b))
	{
		e->a = e->a * cos(M_PI * dir_x / 180);
		if (dir_x + dir_p > 180)
			ft_ray(e, e->a, x, 1);
		else
			ft_ray(e, e->a, x, 2);
	}
	else if (e->a == -1 || (e->b != -1 && e->a > e->b))
	{
		e->b = e->b * cos(M_PI * dir_x / 180);
		if (dir_x + dir_p > 90 && dir_x + dir_p < 270)
			ft_ray(e, e->b, x, 3);
		else
			ft_ray(e, e->b, x, 4);
	}
	else if (e->a == e->b)
	{
		e->b = e->b * cos(M_PI * dir_x / 180);
		ft_ray(e, e->b, x, e->c);
	}
}

void	ft_raycast_1(t_env *e, int x, float dir_p, float dir_x)
{
	if (dir_x + dir_p != 0 && dir_x + dir_p != 180)
		e->a = ft_wall_hori(e, dir_x + dir_p);
	else
		e->a = -1;
	if (dir_x + dir_p != 90 && dir_x + dir_p != 270)
		e->b = ft_wall_verti(e, dir_x + dir_p);
	else
		e->b = -1;
	ft_raycast_2(e, x, dir_x, dir_p);
}

void	ft_raycast(t_env *e)
{
	int		x;
	float	add_angle;

	e->img = mlx_new_image(e->mlx, e->weight, e->hight);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	e->dir_p = e->player->dir;
	e->dir_x = e->angle / 2;
	add_angle = (float)e->angle / e->weight;
	x = 0;
	while (x < e->weight)
	{
		if (e->dir_x + e->dir_p >= 360)
			e->dir_p -= 360;
		if (e->dir_x + e->dir_p < 0)
			e->dir_p += 360;
		ft_raycast_1(e, x, e->dir_p, e->dir_x);
		x++;
		e->dir_x -= add_angle;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}
