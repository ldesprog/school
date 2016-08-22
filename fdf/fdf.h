/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:45:47 by ldesprog          #+#    #+#             */
/*   Updated: 2015/01/02 17:45:48 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "libft/libft.h"

typedef struct	s_pos
{
	int			x;
	int			y;
	double		z;
}				t_pos;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			s_line;
	int			bpp;
	char		*data;
	int			endian;
	int			high;
	int			*len;
	t_pos		**map_3d;
	int			h;
	char		***map;
	int			**imap;
	int			move_x;
	int			move_y;
	int			up;
	int			down;
	int			left;
	int			right;
	int			r;
	int			p;
	int			z;
	int			dz;
	int			zoom;
	int			c1;
	int			c2;
	int			c3;
}				t_env;

char			**ft_strsplit_fdf(const char *s);
int				get_next_line(int fd, char **line);
int				ft_atoi(const char *str);
void			ft_ligne(t_pos map_3d, t_pos map_3d_2, t_env e);
void			ft_put_map(t_env *e);
void			ft_begin_map(char ***map_char, t_env *e);
void			ft_calc_map(t_env *e, int x, int y, int z);
int				key_hook(int keycode, t_env *e);
int				**ft_change_map(char ***map, int *len, int high);
void			ft_compte_taille(int **len, int *high, char ***map);
int				ft_taille(int **map, int *len);
char			***remaloc_map(char ***map);
void			ft_clean(char *str);
void			ft_put_img(t_env e, int x, int y);
void			ft_inverse_1(int *x1, int *y1, int *x2, int *y2);
void			ft_inverse_2(int *x1, int *y1, int *x2, int *y2);
void			ft_init_pos_ligne(t_pos *p1, t_pos *p2, t_pos map_3d,
					t_pos map_3d_2);
void			main_2(int fd, t_env *e);
void			ft_free(t_env *e);
int				ft_key_press(int keycode, t_env *e);
int				ft_key_release(int keycode, t_env *e);
void			ft_point(t_pos map_3d, t_pos map_3d_2, t_env e);
void			ft_init(t_env *e);

#endif
