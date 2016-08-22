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

void	ft_put_map(t_env *e)
{
	int i;
	int j;

	i = 0;
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	while (i < e->high)
	{
		j = 0;
		while (j < e->len[i])
		{
			if (i && e->len[i - 1] > j)
				ft_point(e->map_3d[i][j], e->map_3d[i - 1][j], *e);
			if (j)
				ft_point(e->map_3d[i][j], e->map_3d[i][j - 1], *e);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

void	ft_calc_map(t_env *e, int x, int y, int z)
{
	int i;
	int j;

	i = 0;
	while (y < e->high * e->zoom)
	{
		j = 0;
		x = 0;
		e->map_3d[i] = (t_pos *)malloc(sizeof(t_pos) * e->len[y / e->zoom]);
		while (x < e->len[y / e->zoom] * (4 * e->zoom / 5))
		{
			if (e->imap[i][j] != 0)
				z = e->imap[i][j] / e->h;
			else
				z = 0;
			e->map_3d[i][j].z = z;
			e->map_3d[i][j].x = x - y;
			e->map_3d[i][j].y = y + x - z * 2 * (4 * e->zoom / 5);
			x += (4 * e->zoom / 5);
			j++;
		}
		z += 4 * e->zoom / 5;
		y += e->zoom;
		i++;
	}
}

int		ft_fdf(t_env *e)
{
	int		i;

	if (e->r == 1)
		ft_init(e);
	if (e->z == 1)
		e->zoom += 1;
	if (e->dz == 1 && e->zoom > 2)
		e->zoom -= 1;
	if (e->up == 1)
		e->move_y -= 5;
	if (e->down == 1)
		e->move_y += 5;
	if (e->left == 1)
		e->move_x -= 5;
	if (e->right == 1)
		e->move_x += 5;
	ft_calc_map(e, 0, 0, 0);
	ft_put_map(e);
	i = -1;
	while (++i < e->high)
	{
		free(e->map_3d[i]);
		e->map_3d[i] = NULL;
	}
	return (0);
}

int		ft_red_cross(t_env *e)
{
	ft_free(e);
	return (0);
}

void	ft_begin_map(char ***map_char, t_env *e)
{
	ft_init(e);
	(void)map_char;
	ft_compte_taille(&(e->len), &(e->high), map_char);
	e->imap = ft_change_map(map_char, e->len, e->high);
	e->h = ft_taille(e->imap, e->len);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1000, 1000, "fdf");
	e->map_3d = (t_pos **)malloc(sizeof(t_pos *) * e->high);
	mlx_hook(e->win, 2, 0, &ft_key_press, e);
	mlx_hook(e->win, 3, 0, &ft_key_release, e);
	mlx_loop_hook(e->mlx, &ft_fdf, e);
	mlx_loop(e->mlx);
}
