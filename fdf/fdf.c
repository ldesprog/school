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

void	ft_put_map(t_env *e, int color)
{
	int i;
	int j;

	i = 0;
	e->img = mlx_new_image(e->mlx, 1000, 1000);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian));
	while (i < e->high)
	{
		j = 0;
		while (j < e->len[i])
		{
			if (i && e->len[i - 1] > j)
				ft_ligne(e->map_3d[i][j], e->map_3d[i - 1][j], *e, color);
			if (j)
				ft_ligne(e->map_3d[i][j], e->map_3d[i][j - 1], *e, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

void	ft_calc_map(t_env *e, t_pos p, int **map)
{
	int i;
	int j;

	i = 0;
	while (p.y < e->high * MULTI)
	{
		j = 0;
		p.x = 0;
		e->map_3d[i] = (t_pos *)ft_malloc(sizeof(t_pos) * e->len[p.y / MULTI]);
		while (p.x < e->len[p.y / MULTI] * MULTI_X)
		{
			if (map[i][j] != 0)
				p.z = map[i][j] / e->h;
			else
				p.z = 0;
			e->map_3d[i][j].z = p.z;
			e->map_3d[i][j].x = p.x - p.y;
			e->map_3d[i][j].y = p.y + p.x
				- e->map_3d[i][j].z * 2 * (4 * MULTI / 5);
			p.x += MULTI_X;
			j++;
		}
		p.z += 4 * MULTI / 5;
		p.y += MULTI;
		i++;
	}
}

int 	ft_fdf(t_env *e)
{
	t_pos p;
	int i;

	p.y = 0;
	if (e->up == 1)
		e->move_y -= 5;
	if (e->down == 1)
		e->move_y += 5;
	if (e->left == 1)
		e->move_x -= 5;
	if (e->right == 1)
		e->move_x += 5;
	ft_calc_map(e, p, e->imap);
	ft_put_map(e, 1);
	i = 0;
	while (i < e->high)
	{
		free(e->map_3d[i]);
		e->map_3d[i] = NULL;
		i++;
	}
	return (0);
}

int 	ft_key_press(int keycode, t_env *e)
{
	if (keycode == 53)
		ft_free(e);
	else if (keycode == 123)
		e->left = 1;
	else if (keycode == 124)
		e->right = 1;
	else if (keycode == 125)
		e->down = 1;
	else if (keycode == 126)
		e->up = 1;
	return (0);
}

int 	ft_key_release(int keycode, t_env *e)
{
	if (keycode == 123)
		e->left = 0;
	else if (keycode == 124)
		e->right = 0;
	else if (keycode == 125)
		e->down = 0;
	else if (keycode == 126)
		e->up = 0;
	return (0);
}

void	ft_begin_map(char ***map_char, t_env *e)
{
	e->move_x = 500;
	e->move_y = 250;
	e->up = 0;
	e->down = 0;
	e->right = 0;
	e->left = 0;
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
