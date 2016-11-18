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
	int g;
	int b;
}				t_color;

typedef struct	s_sphere
{
	t_vector	*pos;
	double		radius;
}				t_sphere;

typedef struct	s_plan
{
	t_vector	*normale;
	t_vector	*point;
}				t_plan;

typedef struct	s_cylinder
{
	t_vector *dir;
	t_vector *pos;
	double r;
}				t_cylinder;

typedef struct		s_cone
{
	t_vector		*pos;
	t_vector		*dir;
	double			angle;
}					t_cone;

typedef struct	s_light
{
	t_vector	*pos;
	double		intensity;
	struct s_light	*next;
}				t_light;

typedef struct	s_cam
{
	t_vector *eye;
	t_vector *l_at;
	t_vector *up;
	double		dist;
	double		fov;
	double		h;
	double		w;
	t_vector *c;
	t_vector *l;
	t_vector *n;
	t_vector *u;
}				t_cam;

typedef struct	s_obj
{
	int		(*ft_intersect)(void *, t_vector *, t_vector *, double *);
	double	(*ft_hit)(void *, t_vector *, t_vector *, void *);
	void	*obj;
	t_color	*c;
	struct s_obj	*next;
}				t_obj;

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
	t_vector	*dir;
	//t_vector	*a;
	t_vector	*b;
	t_obj		*obj;
	t_light		*light;
	t_obj		*o_hit;
	t_cam		*cam;
	double 		angle;
	int x;
	int y;
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
int		ft_inter_plane(void *plan, t_vector *pos, t_vector *dir, double *t);
int		ft_inter_sphere(void *sphere, t_vector *pos, t_vector *dir, double *t);
int		ft_inter_cylinder(void	*o, t_vector *pos, t_vector *dir, double *t);
int		ft_inter_cone(void *o, t_vector *pos, t_vector *dir, double *t);

/*
** ft_put_pixel
*/
void	ft_print_pixel(t_env *e, int x, int y, double angle);
void	ft_put_color(t_obj *obj, int r, int g, int b);

/*
** ft_hit
*/
double	ft_sphere_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *e);
double	ft_plan_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *e);
double	ft_cylinder_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *x);
double	ft_cone_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *x);

/*
** ft_malloc_obj
*/
t_light		*ft_malloc_light(void);
t_sphere	*ft_malloc_sphere(void);
t_plan		*ft_malloc_plan(void);
t_cylinder	*ft_malloc_cylinder(void);
t_cone		*ft_malloc_cone(void);

/*
** ft_full_obj
*/
void	ft_full_light(t_light *l, double x, double y, double z, double intensity);
void	ft_full_sphere(t_sphere *s, double x, double y, double z, double radius);
void	ft_full_plan(t_plan *p, double xn, double yn, double zn, double xp, double yp, double zp);
void	ft_full_cylinder(t_cylinder *c, double xd, double yd, double zd, double xp, double yp, double zp, double r);
void	ft_full_cone(t_cone *c, double xp, double yp, double zp, double xd, double yd, double zd, double angle);

#endif
