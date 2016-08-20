/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:06:08 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/17 15:06:11 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_pos(t_pos *pos, float x, float y)
{
	pos->x = x;
	pos->y = y;
}

void	ft_init_wall_hori(t_env *e, float dir, t_pos *a, t_pos *t)
{
	if (dir < 180)
	{
		t->y = -1 * e->size;
		t->x = e->size / tan(M_PI * dir / 180);
		a->y = (int)(e->player->pos->y / e->size) * e->size - 1;
		a->x = e->player->pos->x + (e->player->pos->y - a->y - 1)
			/ tan(M_PI * dir / 180);
	}
	else
	{
		t->y = e->size;
		t->x = e->size / tan(M_PI * dir / 180) * -1;
		a->y = (int)(e->player->pos->y / e->size) * e->size + e->size;
		a->x = e->player->pos->x + (e->player->pos->y - a->y)
			/ tan(M_PI * dir / 180);
	}
}

float	ft_wall_hori(t_env *e, float dir)
{
	t_pos a;
	t_pos t;

	ft_init_wall_hori(e, dir, &a, &t);
	while (a.y >= 0 && a.y < e->map_hight && a.x >= 0 && a.x < e->map_weight
		&& !e->map[(int)a.y / e->size][(int)a.x / e->size])
		ft_init_pos(&a, a.x + t.x, a.y + t.y);
	if (a.y < 0 || a.y >= e->map_hight || a.x < 0 || a.x >= e->map_weight)
		return (-1);
	if (dir < 180)
	{
		return (sqrt(ft_abs(pow((e->player->pos->y - a.y - 1), 2))
			+ ft_abs(pow((e->player->pos->x - a.x), 2))));
	}
	return (sqrt(ft_abs(pow((e->player->pos->y - a.y), 2))
		+ ft_abs(pow((e->player->pos->x - a.x), 2))));
}

void	ft_init_wall_verti(t_env *e, float dir, t_pos *b, t_pos *t)
{
	if (dir > 90 && dir < 270)
	{
		t->x = -1 * e->size;
		t->y = e->size * tan(M_PI * dir / 180);
		b->x = (int)(e->player->pos->x / e->size) * e->size - 1;
		b->y = e->player->pos->y + (e->player->pos->x - b->x - 1)
			* tan(M_PI * dir / 180);
	}
	else
	{
		t->x = e->size;
		t->y = e->size * tan(M_PI * dir / 180) * -1;
		b->x = (int)(e->player->pos->x / e->size) * e->size + e->size;
		b->y = e->player->pos->y + (e->player->pos->x - b->x)
			* tan(M_PI * dir / 180);
	}
}

float	ft_wall_verti(t_env *e, float dir)
{
	t_pos b;
	t_pos t;

	ft_init_wall_verti(e, dir, &b, &t);
	while (b.y >= 0 && b.y < e->map_hight && b.x >= 0 && b.x < e->map_weight
		&& !e->map[(int)b.y / e->size][(int)b.x / e->size])
		ft_init_pos(&b, b.x + t.x, b.y + t.y);
	if (b.y < 0 || b.y >= e->map_hight || b.x < 0 || b.x >= e->map_weight)
		return (-1);
	if (dir > 90 && dir < 270)
	{
		return (sqrt(ft_abs(pow((e->player->pos->y - b.y), 2))
			+ ft_abs(pow((e->player->pos->x - b.x - 1), 2))));
	}
	return (sqrt(ft_abs(pow((e->player->pos->y - b.y), 2))
		+ ft_abs(pow((e->player->pos->x - b.x), 2))));
}
