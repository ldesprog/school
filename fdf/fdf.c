/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 16:47:34 by ldesprog          #+#    #+#             */
/*   Updated: 2015/01/02 16:47:35 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_put_to_win(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	ft_put_map(t_env e, int color)
{
	int i;
	int j;

	i = 0;
	while (i < e.high)
	{
		j = 0;
		while (j < e.len[i])
		{
			if (i && e.len[i - 1] > j)
				ft_ligne(e.map_3d[i][j], e.map_3d[i - 1][j], e, color);
			if (j)
				ft_ligne(e.map_3d[i][j], e.map_3d[i][j - 1], e, color);
			j++;
		}
		i++;
	}
	ft_put_to_win(&e);
}

void	ft_calc_map(t_env e, t_pos p, int **map)
{
	int i;
	int j;

	i = 0;
	while (p.y < e.high * MULTI)
	{
		j = 0;
		p.x = 0;
		e.map_3d[i] = (t_pos *)ft_malloc(sizeof(t_pos) * e.len[p.y / MULTI]);
		while (p.x < e.len[p.y / MULTI] * MULTI_X)
		{
			if (map[i][j] != 0)
				p.z = map[i][j] / e.h;
			else
				p.z = 0;
			e.map_3d[i][j].z = p.z;
			e.map_3d[i][j].x = p.x - p.y;
			e.map_3d[i][j].y = p.y + p.x
				- e.map_3d[i][j].z * 2 * (4 * MULTI / 5);
			p.x += MULTI_X;
			j++;
		}
		p.z += 4 * MULTI / 5;
		p.y += MULTI;
		i++;
	}
}

void	ft_begin_map(char ***map_char)
{
	t_env	e;
	t_pos	p;
	int		**map;

	ft_compte_taille(&(e.len), &(e.high), map_char);
	map = ft_change_map(map_char, e.len, e.high);
	e.h = ft_taille(map, e.len);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1920, 1080, "42");
	e.img = mlx_new_image(e.mlx, 1920, 1080);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.sizeline), &(e.endian));
	p.y = 0;
	e.map_3d = (t_pos **)malloc(sizeof(t_pos *) * e.high);
	ft_calc_map(e, p, map);
	ft_put_map(e, 1);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, &ft_put_to_win, &e);
	mlx_loop(e.mlx);
}
