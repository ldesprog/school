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
	void *mlx;
	void *win;
	void *img;
	int	sizeline;
	int	bpp;
	char *data;
	int	endian;
	int **map;
	int map_hight;
	int map_weight;
	t_player *player;
	int hight;
	int weight;
	int angle;
	int dist_ecran;
	int size;
	int mur;
	int plafond;
	float a;
	float b;
	int c;
	float dir_x;
	float dir_p;
	int x;
	int y;
}				t_env;

void			ft_raycast(t_env *env);
void			ft_raycast_1(t_env *e, int x, float dir_p, float dir_x);
void			ft_wolf(t_env *env);
int				get_next_line(int fd, char **line);

#endif