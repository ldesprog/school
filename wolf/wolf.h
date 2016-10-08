/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:07:57 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/17 15:07:58 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <mlx.h>

typedef struct	s_pos
{
	float x;
	float y;
}				t_pos;

typedef struct	s_player
{
	t_pos *pos;
	float dir;
}				t_player;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			s_line;
	int			bpp;
	int			*data;
	int			endian;
	int			**map;
	int			map_hight;
	int			map_weight;
	t_player	*player;
	int			hight;
	int			weight;
	int			angle;
	int			dist_ecran;
	int			size;
	int			mur;
	int			plafond;
	float		a;
	float		b;
	int			c;
	float		dir_x;
	float		dir_p;
	int			x;
	int			y;
	int			left;
	int			right;
	int			up;
	int			down;
}				t_env;

void			ft_raycast(t_env *env);
void			ft_raycast_1(t_env *e, int x, float dir_p, float dir_x);
int				ft_wolf(t_env *env);
int				get_next_line(int fd, char **line);
void			ft_free(t_env *env);
void			ft_avance(int i, t_env *e);
void			ft_tourne(int i, t_env *e);
int				ft_key_down(int keycode, t_env *e);
int				ft_key_up(int keycode, t_env *e);
int				ft_red_cross(t_env *e);
float			ft_abs(float n);
void			ft_ray(t_env *e, float dist, int x, int color);
float			ft_wall_hori(t_env *e, float dir);
float			ft_wall_verti(t_env *e, float dir);
char			**ft_remalloc_tab(char **tab, int n);
int				**ft_split_to_int(char **tab, int i, int *j);
int				ft_verif_map(int **map, int len, int high);

#endif
