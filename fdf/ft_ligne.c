/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 15:07:17 by ldesprog          #+#    #+#             */
/*   Updated: 2015/01/27 15:07:19 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_img(t_env e, int x, int y, int color)
{
	if (x < 1920 && x >= 0 && y < 1080 && y >= 0)
	{
		if (color == 1)
		{
			*(e.data + y * e.sizeline + e.bpp / 8 * x) = 0x00;
			*(e.data + y * e.sizeline + e.bpp / 8 * x + 1) = 0x00;
			*(e.data + y * e.sizeline + e.bpp / 8 * x + 2) = 0xFF;
		}
		if (color == 0)
		{
			*(e.data + y * e.sizeline + e.bpp / 8 * x) = 0x00;
			*(e.data + y * e.sizeline + e.bpp / 8 * x + 1) = 0x00;
			*(e.data + y * e.sizeline + e.bpp / 8 * x + 2) = 0x00;
		}
	}
}

void	ft_inverse_1(int *x1, int *y1, int *x2, int *y2)
{
	int x;

	if (*x1 > *x2 && (*x2 - *x1) <= abs(*y2 - *y1))
	{
		x = *x1;
		*x1 = *x2;
		*x2 = x;
		x = *y1;
		*y1 = *y2;
		*y2 = x;
	}
}

void	ft_inverse_2(int *x1, int *y1, int *x2, int *y2)
{
	int x;

	if (*y1 > *y2 && (*x2 - *x1) <= abs(*y2 - *y1))
	{
		x = *x1;
		*x1 = *x2;
		*x2 = x;
		x = *y1;
		*y1 = *y2;
		*y2 = x;
	}
}

void	ft_init_pos_ligne(t_pos *p1, t_pos *p2, t_pos map_3d, t_pos map_3d_2)
{
	p1->x = map_3d.x;
	p1->y = map_3d.y;
	p2->x = map_3d_2.x;
	p2->y = map_3d_2.y;
}

void	ft_ligne(t_pos map_3d, t_pos map_3d_2, t_env e, int c)
{
	int		x;
	t_pos	p1;
	t_pos	p2;

	ft_init_pos_ligne(&p1, &p2, map_3d, map_3d_2);
	ft_inverse_1(&(p1.x), &(p1.y), &(p2.x), &(p2.y));
	if (p1.x <= p2.x && (p2.x - p1.x) >= abs(p2.y - p1.y))
	{
		x = p1.x - 1;
		if (x + e.move_x < 0)
			x = -e.move_x - 1;
		while (++x <= p2.x && p2.x - p1.x != 0)
		{
			ft_put_img(e, e.move_x + x, e.move_y + p1.y + (p2.y - p1.y)
				* (x - p1.x) / (p2.x - p1.x), c);
		}
	}
	else
	{
		ft_inverse_2(&(p1.x), &(p1.y), &(p2.x), &(p2.y));
		x = p1.y - 1;
		if (x + e.move_y < 0)
			x = -e.move_y - 1;
		while (++x <= p2.y && p2.y - p1.y != 0)
		{
			ft_put_img(e, e.move_x + p1.x + (p2.x - p1.x) * (x - p1.y)
				/ (p2.y - p1.y), e.move_y + x, c);
		}
	}
}
