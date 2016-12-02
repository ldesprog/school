#include "rtv1.h"

int		ft_inter_plane(void *plan, t_vector *pos, t_vector *dir, double *t)
{
	double denom;
	t_vector *truc;
	double t2;
	t_plan *p;

	p = (t_plan *)plan;
	denom = ft_vector_dot(dir, p->normale);
	//printf("deno : %f\n", denom);
	//printf("t = %f\n", *t);
	if (fabs(denom) > *t)
		return (0);
	//printf("sa passe la\n");
	truc = ft_vector_sub(p->point, pos);
	t2 = ft_vector_dot(truc, p->normale) / denom;
	free(truc);
	if (t2 > 0.01 && t2 < *t)
		*t = t2;
	else
		return (0);
	return (1);
}

int		ft_inter_sphere(void *sphere, t_vector *pos, t_vector *dir, double *t)
{
	t_vector	*dist;
	double		t0;
	double		t1;
	double		b;
	double		d;
	int			res;
	t_sphere *s;

	s = (t_sphere *)sphere;
	dist = ft_vector_sub(s->pos, pos);
	b = ft_vector_dot(dir, dist);
	d = b * b - ft_vector_dot(dist, dist) + s->radius * s->radius;
	free(dist);
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

int		ft_inter_cylinder(void	*o, t_vector *pos, t_vector *dir, double *t)
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
	tmp->x = dir->x - ft_vector_dot(dir, obj->dir) * obj->dir->x;
	tmp->y = dir->y - ft_vector_dot(dir, obj->dir) * obj->dir->y;
	tmp->z = dir->z - ft_vector_dot(dir, obj->dir) * obj->dir->z;
	v = ft_vector_sub(pos, obj->pos);
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

static int	solve_quad_ext(double delta, double b, double *t)
{
	if (delta < 0)
		return (0);
	else if (*t < b && b > .1)
	{
		*t = b;
		return (1);
	}
	return (0);
}

static int	solve_quad(double a, double b, double c, double *t)
{
	double delta;
	double x0;
	double x1;
	double q;

	delta = b * b - 4 * a * c;
	if (delta > 0)
	{
		q = (b > 0) ? -.5 * (b + sqrt(delta)) : -.5 * (b + sqrt(delta));
		x0 = q / a;
		x1 = c / q;
		if (x0 > x1 && x1 > 0.01)
			x0 = x1;
		if (*t > x0 && x0 > 0.01)
		{
			*t = x0;
			return (1);
		}
	}
	else
		return (solve_quad_ext(delta, b, t));
	return (0);
}

t_vector 	*vmult_dbl(t_vector *a, double b)
{
	t_vector *ret;

	ret = (t_vector *)ft_malloc(sizeof(t_vector));
	ret->x = a->x * b;
	ret->y = a->y * b;
	ret->z = a->z * b;
	return (ret);
}

int				ft_inter_cone(void *o, t_vector *pos, t_vector *dir, double *t)
{
	double			alpha;
	t_vector		*origin;	
	t_vector		*tmp1;
	t_vector		*tmp2;
	t_vector		*dir_dir;
	t_vector		*o_dir;
	t_cone 			*cone;
	int				ret;
	double			arg1;
	double			arg2;
	double			arg3;

	// printf("cone-nard\n");
	cone = (t_cone *)o;
	alpha = cone->angle / 180 * M_PI;
	origin = ft_vector_sub(pos, cone->pos);
	dir_dir = vmult_dbl(cone->dir, ft_vector_dot(dir, cone->dir));
	o_dir = vmult_dbl(cone->dir, ft_vector_dot(origin, cone->dir));
	tmp1 = ft_vector_sub(dir, dir_dir);
	tmp2 = ft_vector_sub(origin, o_dir);
	free(dir_dir);
	free(o_dir);
	arg1 = pow(cos(alpha), 2) * ft_vector_dot(tmp1, tmp1) - pow(sin(alpha), 2) * pow(ft_vector_dot(dir, cone->dir), 2);
	arg2 = 2 * (pow(cos(alpha), 2) * ft_vector_dot(tmp1, tmp2)) - 2 * (pow(sin(alpha), 2) * ft_vector_dot(dir, cone->dir) * ft_vector_dot(origin, cone->dir));
	arg3 = pow(cos(alpha), 2) * ft_vector_dot(tmp2, tmp2) - pow(sin(alpha), 2) * pow(ft_vector_dot(origin, cone->dir), 2);
	ret = solve_quad(arg1, arg2, arg3, t);
	free(origin);
	free(tmp1);
	free(tmp2);
	return (ret);
}
