#ifndef RTV1_H
# define RTV1_H

//on me supprime se truc a la fin
#include <stdio.h>
//on garde ceux la normalement
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"

#define DIST_MAX 20000

typedef struct	s_vector
{
	double x;
	double y;
	double z;
}				t_vector;

typedef struct	s_color
{
	int r;
	int v;
	int b;
}				t_color;

typedef struct	s_sphere
{
	t_vector	*pos;
	double		radius;
	t_color		c;
}				t_sphere;

typedef struct	s_light
{
	t_vector	*pos;
	t_color		c;
}				t_light;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int 	s_line;
	int		endian;
	int		height;
	int		width;
}				t_mlx;

typedef struct	s_env
{
	t_mlx		*mlx;
	t_vector	*ray_O;
	t_vector	*ray_D;
	//t_vector	*a;
	t_vector	*b;
	//la faudra changer le type 
	//pour passer en object pour le moment ya que la sphere
	t_sphere	*object;
	t_light		*light;
}				t_env;

/*
** fonc_vector
*/
void		ft_vector_normalize(t_vector *v);
double		ft_vector_dot(t_vector *a, t_vector *b);
t_vector	*ft_vector_copy(t_vector *a);
t_vector	*ft_vector_sub(t_vector *a, t_vector *b);
t_vector	*ft_p_hit(t_vector *v_O, t_vector *v_dir, double dist);

/*
** ft_intersection
*/
int		ft_intersection(t_sphere *object, t_vector *ray_O, t_vector *ray_D, double *t);

/*
** ft_put_pixel
*/
void	ft_print_pixel(t_env *e, int x, int y, double angle);

#endif