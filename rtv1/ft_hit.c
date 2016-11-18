#include "rtv1.h"

double	ft_sphere_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *x)
{
	t_vector *n_hit;
	double angle;
	t_env *e;
	t_sphere *s;

	e = (t_env *)x;
	s = (t_sphere *)o;
	n_hit = ft_vector_sub(p_hit, s->pos);
	ft_vector_normalize(n_hit);
	ft_vector_normalize(l_vector);
	angle = ft_vector_dot(n_hit, l_vector);
	return (angle);
}

double	ft_plan_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *x)
{
	double angle;
	t_env *e;
	t_plan *p;

	e = (t_env *)x;
	p = (t_plan *)o;
	ft_vector_normalize(l_vector);
	angle = ft_vector_dot(p->normale, l_vector);
	(void)p_hit;
	return (angle);
}

double	ft_cylinder_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *x)
{
	double angle;
	t_env *e;
	t_cylinder *obj;
	t_vector *b;
	t_vector *c;
	t_vector *r;
	double n;
	double n2;
	float dist;

	e = (t_env *)x;
	obj = (t_cylinder *)o;
	
	b = ft_vector_sub(p_hit, obj->pos);
	n = ft_vector_dot(b, b);
	if ((float)n == obj->r * obj->r)
		dist = 0;
	else
		dist = sqrt(n - obj->r * obj->r);
	b->x = obj->dir->x * dist + obj->pos->x;
	b->y = obj->dir->y * dist + obj->pos->y;
	b->z = obj->dir->z * dist + obj->pos->z;
	c = ft_vector_sub(p_hit, b);
	n2 = ft_vector_dot(c, c);
	if (n2 > n)
	{
		b->x = -(obj->dir->x * dist) + obj->pos->x;
		b->y = -(obj->dir->y * dist) + obj->pos->y;
		b->z = -(obj->dir->z * dist) + obj->pos->z;
	}
	r = ft_vector_sub(p_hit, b);
	ft_vector_normalize(r);
	ft_vector_normalize(l_vector);
	angle = ft_vector_dot(r, l_vector);
	return (angle);
}

double	ft_cone_hit(void *o, t_vector *p_hit, t_vector *l_vector, void *x)
{
	t_env *e;
	t_cone *obj;
	double hypo;
	double opp;
	double adj;
	t_vector *b;
	t_vector *c;
	double alpha;
	double dist;
	double angle;

	e = (t_env *)x;
	obj = (t_cone *)o;

	alpha = M_PI * obj->angle / 180;
	c = ft_vector_sub(p_hit, obj->pos);
	hypo = sqrt(ft_vector_dot(c, c));
	adj = hypo * cos(alpha);
	opp = adj * tan(alpha);
	c->x = obj->dir->x * adj + obj->pos->x;
	c->y = obj->dir->y * adj + obj->pos->y;
	c->z = obj->dir->z * adj + obj->pos->z;
	b = ft_vector_sub(p_hit, c);
	dist = sqrt(ft_vector_dot(b, b));
	if ((float)dist > (float)opp)
	{
		c->x = obj->dir->x * -adj + obj->pos->x;
		c->y = obj->dir->y * -adj + obj->pos->y;
		c->z = obj->dir->z * -adj + obj->pos->z;
	}
	b = ft_vector_sub(p_hit, c);
	// printf("%f, %f, %f\n", b->x, b->y, b->z);
	ft_vector_normalize(b);
	ft_vector_normalize(l_vector);
	angle = ft_vector_dot(b, l_vector);
	// printf("%f\n", angle);
	if (angle < 0)
		angle = 0;
	return (angle);
}

























