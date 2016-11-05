#include "rtv1.h"

int		ft_inter_sphere(t_sphere *sphere, t_vector *ray_O, t_vector *ray_D, double *t)
{
	t_vector	*dist;
	double		t0;
	double		t1;
	double		b;
	double		d;
	int			res;

	dist = ft_vector_copy(sphere->pos);
	dist = ft_vector_sub(dist, ray_O);
	b = ft_vector_dot(ray_D, dist);
	d = b * b - ft_vector_dot(dist, dist) + sphere->radius * sphere->radius;
	if (d < 0)
		return (0);
	t0 = b - sqrt(d);
	t1 = b + sqrt(d);
	res = 0;
	if (t0 > 0.1 && t0 < *t)
	{
		*t = t0;
		res = 1;
	}
	if (t1 > 0.1 && t1 < *t)
	{
		*t = t1;
		res = 1;
	}
	return (res);
}

int		ft_intersection(t_sphere *object, t_vector *ray_O, t_vector *ray_D, double *t)
{
	return (ft_inter_sphere(object, ray_O, ray_D, t));
}