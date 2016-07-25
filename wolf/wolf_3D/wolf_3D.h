/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 00:12:18 by ldesprog          #+#    #+#             */
/*   Updated: 2015/01/31 00:12:20 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H


#define mapWidth 24
#define mapHeight 24
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

typedef struct	s_rvb
{
	int		r;
	int		v;
	int		b;
}				t_rvb;

typedef struct	s_ray
{
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	map_x;
	double	map_y;
	double	s_dist_x;
	double	s_dist_y;
	double	d_dist_x;
	double	d_dist_y;
	double	line_height;
	double	draw_start;
	double	draw_end;
}				t_ray;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	hit;
	double	step_x;
	double	step_y;
	double	wall_side;
}				t_player;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	t_ray		ray;
	t_player	player;
	double		time;
	double		old_time;
	int			sizeline;
	int			bpp;
	char		*data;
	int			endian;
	t_rvb		c;
}				t_env;

#endif
