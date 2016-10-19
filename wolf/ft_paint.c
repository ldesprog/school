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

void	ft_color(int c, int *color, t_env *e, int wall)
{
	if ((c <= 2 && e->nb_case_a == 1) || (c > 2 && e->nb_case_b == 1))
	{
		if (c == 1)
			*color = 0x0012fa;
		else if (c == 2)
			*color = 0x005a8b;
		else if (c == 3)
			*color = 0x8a003a;
		else if (c == 4)
			*color = 0xfa5300;
	}
	else if ((e->nb_case_a == 3 && wall == 1)
		|| (e->nb_case_b == 3 && wall == 2))
		*color = 0x22ff00;
	else if ((e->nb_case_a == 4 && wall == 1)
		|| (e->nb_case_b == 4 && wall == 2))
		*color = 0x222288;
	else if ((e->nb_case_a == 5 && wall == 1)
		|| (e->nb_case_b == 5 && wall == 2))
		*color = 0xaa00aa;
}

void	ft_paint(t_env e, int color)
{
	(void)e;
	(void)color;
}

void	ft_ray(t_env *e, int wall, int x, int color)
{
	float dist;

	if (wall == 1)
		dist = e->a;
	else
		dist = e->b;
	e->x = x;
	e->c = color;
	ft_color(e->c, &color, e, wall);
	e->mur = (int)((float)e->size / dist * e->hight);
	e->plafond = e->hight / 2 - e->mur / 2;
	e->y = -1;
	while (++(e->y) < e->plafond)
		*(e->data + e->y * e->s_line / 4 + e->x) = 0;
	e->mur += e->y;
	(e->y)--;
	while (++(e->y) < e->mur && e->y < e->hight)
		*(e->data + e->y * e->s_line / 4 + e->x) = color;
	(e->y)--;
	while (++(e->y) < e->hight)
		*(e->data + e->y * e->s_line / 4 + e->x) = 0;
}
