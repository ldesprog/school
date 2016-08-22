/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 19:57:43 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/22 19:57:46 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_point(t_pos map_3d, t_pos map_3d_2, t_env e)
{
	if (e.p == 1)
	{
		ft_put_img(e, map_3d.x + e.move_x, map_3d.y + e.move_y);
		ft_put_img(e, map_3d_2.x + e.move_x, map_3d_2.y + e.move_y);
	}
	else
		ft_ligne(map_3d, map_3d_2, e);
}
