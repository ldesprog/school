#include "rtv1.h"

void	ft_full_light(t_light *l, double x, double y, double z, double intensity)
{
	l->pos->x = x;
	l->pos->y = y;
	l->pos->z = z;
	l->intensity = intensity;
}

void	ft_full_sphere(t_sphere *s, double x, double y, double z, double radius)
{
	s->pos->x = x;
	s->pos->y = y;
	s->pos->z = z;
	s->radius = radius;
}

void	ft_full_plan(t_plan *p, double xn, double yn, double zn, double xp, double yp, double zp)
{
	p->normale->x = xn;
	p->normale->y = yn;
	p->normale->z = zn;
	p->point->x = xp;
	p->point->y = yp;
	p->point->z = zp;
}

void	ft_full_cylinder(t_cylinder *c, double xd, double yd, double zd, double xp, double yp, double zp, double r)
{
	c->dir->x = xd;
	c->dir->y = yd;
	c->dir->z = zd;
	ft_vector_normalize(c->dir);
	c->pos->x = xp;
	c->pos->y = yp;
	c->pos->z = zp;
	c->r = r;
}
