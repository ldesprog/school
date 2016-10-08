/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:39:27 by ldesprog          #+#    #+#             */
/*   Updated: 2016/09/21 16:39:29 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_zoom(t_env *e, t_pos mouse)
{
	double tmp;

	tmp = e->z;
	e->z *= 1.1;
	e->decal_x += ((mouse.x - 300) / 600) / ((e->z - tmp) * 55);
	e->decal_y += ((mouse.y - 300) / 600) / ((e->z - tmp) * 55);
}

void	ft_dezoom(t_env *e, t_pos mouse)
{
	double tmp;

	tmp = e->z;
	e->z /= 1.1;
	e->decal_x += ((mouse.x - 300) / 600) / ((e->z - tmp) * 55);
	e->decal_y += ((mouse.y - 300) / 600) / ((e->z - tmp) * 55);
}
