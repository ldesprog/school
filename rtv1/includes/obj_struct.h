#ifndef OBJ_STRUCT_H
# define OBJ_STRUCT_H

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

#endif
