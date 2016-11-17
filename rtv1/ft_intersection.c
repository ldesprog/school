#include "rtv1.h"

int		ft_inter_plane(void *plan, t_vector *ray_O, t_vector *ray_D, double *t)
{
	double denom;
	t_vector *truc;
	double t2;
	t_plan *p;

	p = (t_plan *)plan;
	denom = ft_vector_dot(ray_D, p->normale);
	//printf("deno : %f\n", denom);
	//printf("t = %f\n", *t);
	if (fabs(denom) > *t)
		return (0);
	//printf("sa passe la\n");
	truc = ft_vector_sub(p->point, ray_O);
	t2 = ft_vector_dot(truc, p->normale) / denom;
	if (t2 > 0.01 && t2 < *t)
		*t = t2;
	else
		return (0);
	return (1);
}

int		ft_inter_sphere(void *sphere, t_vector *ray_O, t_vector *ray_D, double *t)
{
	t_vector	*dist;
	double		t0;
	double		t1;
	double		b;
	double		d;
	int			res;
	t_sphere *s;

	s = (t_sphere *)sphere;
	dist = ft_vector_sub(s->pos, ray_O);
	b = ft_vector_dot(ray_D, dist);
	d = b * b - ft_vector_dot(dist, dist) + s->radius * s->radius;
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

int		ft_inter_cylinder(void	*o, t_vector *ray_O, t_vector *ray_D, double *t)
{
	int res;
	t_cylinder *obj;
	t_vector *v;
	t_vector *tmp;
	t_vector *tmp2;
	double a;
	double b;
	double c;
	double t0;
	double t1;
	double delta;

	tmp = (t_vector *)ft_malloc(sizeof(t_vector));
	tmp2 = (t_vector *)ft_malloc(sizeof(t_vector));

	
	obj = (t_cylinder *)o;
	tmp->x = ray_D->x - ft_vector_dot(ray_D, obj->dir) * obj->dir->x;
	tmp->y = ray_D->y - ft_vector_dot(ray_D, obj->dir) * obj->dir->y;
	tmp->z = ray_D->z - ft_vector_dot(ray_D, obj->dir) * obj->dir->z;
	v = ft_vector_sub(ray_O, obj->pos);
	tmp2->x = v->x - ft_vector_dot(v, obj->dir) * obj->dir->x;
	tmp2->y = v->y - ft_vector_dot(v, obj->dir) * obj->dir->y;
	tmp2->z = v->z - ft_vector_dot(v, obj->dir) * obj->dir->z;

	a = ft_vector_dot(tmp, tmp);
	b = ft_vector_dot(tmp, tmp2) * 2;
	c = ft_vector_dot(tmp2, tmp2) - (obj->r * obj->r);

	free(v);
	v = NULL;
	free(tmp);
	tmp = NULL;
	free(tmp2);
	tmp2 = NULL;

	delta = b * b - 4 * (a * c);
	if (delta <= 0)
		return 0;
	delta = sqrt(delta);
	t0 = (-b - delta) / (2 * a);
	t1 = (-b + delta) / (2 * a);
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
