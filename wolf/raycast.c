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
	if (e->map[(int)(e->player->pos->y + y) / e->size][(int)(e->player->pos->x)
		/ e->size] == 5 || e->map[(int)(e->player->pos->y + y)
		/ e->size][(int)(e->player->pos->x) / e->size] == 2 ||
		!e->map[(int)(e->player->pos->y + y) / e->size][(int)(e->player->pos->x)
		/ e->size])
	{
		y = 20 * -1 * i * sin(M_PI * e->player->dir / 180);
		e->player->pos->y += y;
	}
	if (e->map[(int)(e->player->pos->y) / e->size][(int)(e->player->pos->x + x)
		/ e->size] == 5 || e->map[(int)(e->player->pos->y)
		/ e->size][(int)(e->player->pos->x + x) / e->size] == 2 ||
		!e->map[(int)(e->player->pos->y) / e->size][(int)(e->player->pos->x + x)
		/ e->size])
	{
		x = 20 * i * cos(M_PI * e->player->dir / 180);
		e->player->pos->x += x;
	}
	ft_raycast(e);
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

void	ft_raycast_2(t_env *e, int x, float dir_x, float dir)
{
	float dir_cos;

	dir_cos = cos(M_PI * dir_x / 180);
	if (e->b == -1 || (e->a != -1 && e->a < e->b))
	{
		e->a = e->a * dir_cos;
		if (dir > 180)
			ft_ray(e, 1, x, 1);
		else
			ft_ray(e, 1, x, 2);
	}
	else if (e->a == -1 || (e->b != -1 && e->a > e->b))
	{
		e->b = e->b * dir_cos;
		if (dir > 90 && dir < 270)
			ft_ray(e, 2, x, 3);
		else
			ft_ray(e, 2, x, 4);
	}
	else if (e->a == e->b)
	{
		e->b = e->b * dir_cos;
		ft_ray(e, 2, x, e->c);
	}
}

void	ft_raycast_1(t_env *e, int x, float dir_p, float dir_x)
{
	float dir;

	dir = dir_x + dir_p;
	if (dir != 0 && dir != 180)
		e->a = ft_wall_hori(e, dir);
	else
		e->a = -1;
	if (dir != 90 && dir != 270)
		e->b = ft_wall_verti(e, dir);
	else
		e->b = -1;
	ft_raycast_2(e, x, dir_x, dir);
}

void	ft_raycast(t_env *e)
{
	int		x;
	float	add_angle;

	e->img = mlx_new_image(e->mlx, e->weight, e->hight);
	e->data = (int *)mlx_get_data_addr(e->img, &(e->bpp),
		&(e->s_line), &(e->endian));
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
	ft_curseur(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->key->key_menu_v == 1)
		ft_menu(e);
	mlx_destroy_image(e->mlx, e->img);
}
