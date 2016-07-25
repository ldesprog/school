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

# define MULTI 10
# define MULTI_X 8

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
	int			sizeline;
	int			bpp;
	char		*data;
	int			endian;
	int			high;
	int			*len;
	t_pos		**map_3d;
	int			h;
}				t_env;

char			**ft_strsplit_fdf(const char *s);
int				get_next_line(int fd, char **line);
int				ft_atoi(const char *str);
void			ft_ligne(t_pos map_3d, t_pos map_3d_2, t_env e, int c);
void			ft_put_map(t_env e, int color);
void			ft_begin_map(char ***map_char);
void			ft_calc_map(t_env e, t_pos p, int **map);
int				ft_put_to_win(t_env *e);
int				key_hook(int keycode, t_env *e);
int				**ft_change_map(char ***map, int *len, int high);
void			ft_compte_taille(int **len, int *high, char ***map);
int				ft_taille(int **map, int *len);
char			***remaloc_map(char ***map);
void			ft_clean(char *str);
void			ft_put_img(t_env e, int x, int y, int color);
void			ft_inverse_1(int *x1, int *y1, int *x2, int *y2);
void			ft_inverse_2(int *x1, int *y1, int *x2, int *y2);
void			ft_init_pos_ligne(t_pos *p1, t_pos *p2, t_pos map_3d,
					t_pos map_3d_2);
void			main_2(int fd, char ****map);

#endif
