/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 21:57:25 by ldesprog          #+#    #+#             */
/*   Updated: 2015/01/28 21:57:27 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3D.h"

#define mapWidth 24
#define mapHeight 24
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

int world_map[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	ft_put_pixel_to_img(t_env *e, t_rvb *c, int x, int y)
{
	*(e->data + y * e->sizeline + e->bpp / 8 * x) = mlx_get_color_value(e->mlx, c->b);
	*(e->data + y * e->sizeline + e->bpp / 8 * x + 1) = mlx_get_color_value(e->mlx, c->v);
	*(e->data + y * e->sizeline + e->bpp / 8 * x + 2) = mlx_get_color_value(e->mlx, c->r);
}

void	ft_set_colors(t_rvb *c, int r, int v, int b)
{
	c->r = r;
	c->v = v;
	c->b = b;
}

void	ft_choice_color(t_env *e)
{
	if (e->player.wall_side == 0)
	{
		if (e->player.step_x < 0)
			ft_set_colors(&(e->c), 0, 0, 255);
		else
			ft_set_colors(&(e->c), 0, 255, 0);
	}
	else
	{
		if (e->player.step_y < 0)
			ft_set_colors(&(e->c), 255, 0, 255);
		else
			ft_set_colors(&(e->c), 255, 255, 0);
	}
}

void	ft_calculate(t_env *e)
{
	int perp_wall_dist;

	if (e->player.wall_side == 0)
		perp_wall_dist = fabs((e->ray.map_x - e->ray.pos_x + (1 - e->player.step_x) / 2) / e->ray.dir_x);
	else
		perp_wall_dist = fabs((e->ray.map_y - e->ray.pos_y + (1 - e->player.step_y) / 2) / e->ray.dir_y);
	if (perp_wall_dist != 0)
		e->ray.line_height = abs(WIN_HEIGHT / perp_wall_dist);
	else
		e->ray.line_height = 0;
	e->ray.draw_start = -e->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (e->ray.draw_start < 0)
		e->ray.draw_start = 0;
	e->ray.draw_end = e->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (e->ray.draw_end >= WIN_HEIGHT)
		e->ray.draw_end = WIN_HEIGHT - 1;
	ft_choice_color(e);
}

void	ft_dda(t_env *e)
{
	while (e->player.hit == 0)
	{
		if (e->ray.s_dist_x < e->ray.s_dist_y)
		{
			e->ray.s_dist_x += e->ray.d_dist_x;
			e->ray.map_x += e->player.step_x;
			e->player.wall_side = 0;
		}
		else
		{
			e->ray.s_dist_y += e->ray.d_dist_y;
			e->ray.map_y += e->player.step_y;
			e->player.wall_side = 1;
		}
		if (world_map[(int)e->ray.map_x][(int)e->ray.map_y] > 0)
			e->player.hit = 1;
	}
	ft_calculate(e);
}

void	ft_componente(t_env *e)
{
	if (e->ray.dir_x < 0)
	{
		e->player.step_x = -1;
		e->ray.s_dist_x = (e->ray.pos_x - e->ray.map_x) * e->ray.d_dist_x;
	}
	else
	{
		e->player.step_x = 1;
		e->ray.s_dist_x = (e->ray.map_x + 1 - e->ray.pos_x) * e->ray.d_dist_x;
	}
	if (e->ray.dir_y < 0)
	{
		e->player.step_y = -1;
		e->ray.s_dist_y = (e->ray.pos_y - e->ray.map_y) * e->ray.d_dist_y;
	}
	else
	{
		e->player.step_y = 1;
		e->ray.s_dist_y = (e->ray.map_y + 1 - e->ray.pos_y) * e->ray.d_dist_y;
	}
	ft_dda(e);
}

void	ft_send_ray(t_env *e, int x)
{
	e->ray.camera_x = 2 * x / WIN_WIDTH - 1;
	e->ray.pos_x = e->player.pos_x;
	e->ray.pos_y = e->player.pos_y;
	e->ray.dir_x = e->ray.pos_x + e->ray.plane_x * e->ray.camera_x;
	e->ray.dir_y = e->ray.pos_y + e->ray.plane_y * e->ray.camera_x;
	e->ray.map_x = e->ray.pos_x;
	e->ray.map_y = e->ray.pos_y;
	e->ray.d_dist_x = sqrt(1 + pow(e->ray.dir_y, 2) / pow(e->ray.dir_x, 2));
	e->ray.d_dist_y = sqrt(1 + pow(e->ray.dir_x, 2) / pow(e->ray.dir_y, 2));
	e->player.hit = 0;
	ft_componente(e);
}

void	ft_draw_ray(t_env *e, t_rvb c, int x)
{
	int y;
	t_rvb decor;

	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian));
	ft_set_colors(&decor, 128, 128, 128);
	y = 0;
	while (y < e->ray.draw_start)
	{
		ft_put_pixel_to_img(e, &decor, x, y);
		y++;
	}
	while (y < e->ray.draw_end)
	{
		ft_put_pixel_to_img(e, &c, x, y);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		ft_put_pixel_to_img(e, &decor, x, y);
		y++;
	}
	
}

int		my_loop(t_env *e)
{
	int x;

	e->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	x = 0;
	while (x < WIN_WIDTH)
	{
		ft_send_ray(e, x);
		ft_draw_ray(e, e->c, x);
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	e->img = NULL;
	return (0);
}

int		main(void)
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1920, 1080, "wolf_3D");
	e.player.pos_x = 1;
	e.player.pos_y = 1;
	e.player.dir_x = -1;
	e.player.dir_y = 0;
	e.ray.plane_x = 0;
	e.ray.plane_y = 0.7;
	e.time = 0;
	e.old_time = 0;
	mlx_loop_hook(e.mlx, &my_loop, &e);
	//mlx_hook(e.win, 2, (1L<<0), &key_press, &e);
	//mlx_hook(e.win, 3, (1L<<1), &key_release, &e);
	mlx_loop(e.mlx);
	return (0);
}
