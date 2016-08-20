/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:06:37 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/17 15:06:38 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_color(int c, int *c1, int *c2, int *c3)
{
	if (c == 1)
	{
		*c1 = 0xfa;
		*c2 = 0x12;
		*c3 = 0x00;
	}
	else if (c == 2)
	{
		*c1 = 0x8b;
		*c2 = 0x5a;
		*c3 = 0x00;
	}
	else if (c == 3)
	{
		*c1 = 0x3a;
		*c2 = 0x00;
		*c3 = 0x8a;
	}
	else
	{
		*c1 = 0x00;
		*c2 = 0x53;
		*c3 = 0xfa;
	}
}

void	ft_paint(t_env e, int c1, int c2, int c3)
{
	*(e.data + e.y * e.s_line + e.bpp / 8 * e.x) = c1;
	*(e.data + e.y * e.s_line + e.bpp / 8 * e.x + 1) = c2;
	*(e.data + e.y * e.s_line + e.bpp / 8 * e.x + 2) = c3;
}

void	ft_ray(t_env *e, float dist, int x, int color)
{
	int c1;
	int c2;
	int c3;

	e->x = x;
	e->c = color;
	ft_color(e->c, &c1, &c2, &c3);
	e->mur = (int)((float)e->size / dist * e->hight);
	e->plafond = e->hight / 2 - e->mur / 2;
	e->y = -1;
	while (++(e->y) < e->plafond)
		ft_paint(*e, 0x00, 0x00, 0x00);
	e->mur += e->y;
	(e->y)--;
	while (++(e->y) < e->mur && e->y < e->hight)
		ft_paint(*e, c1, c2, c3);
	(e->y)--;
	while (++(e->y) < e->hight)
		ft_paint(*e, 0x00, 0x00, 0x00);
}
