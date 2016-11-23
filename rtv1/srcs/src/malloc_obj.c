#include "rtv1.h"

t_light		*ft_malloc_light(void)
{
	t_light *l;

	l = (t_light *)ft_malloc(sizeof(t_light));
	l->pos = (t_vector *)ft_malloc(sizeof(t_vector));
	return (l);
}

t_sphere	*ft_malloc_sphere(void)
{
	t_sphere *s;

	s = (t_sphere *)ft_malloc(sizeof(t_sphere));
	s->pos = (t_vector *)ft_malloc(sizeof(t_vector));
	return (s);
}

t_plan		*ft_malloc_plan(void)
{
	t_plan *plan;

	plan = (t_plan *)ft_malloc(sizeof(t_plan));
	plan->normale = (t_vector *)ft_malloc(sizeof(t_vector));
	plan->point = (t_vector *)ft_malloc(sizeof(t_vector));
	return (plan);
}

t_cylinder	*ft_malloc_cylinder(void)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)ft_malloc(sizeof(t_cylinder));
	cylinder->dir = (t_vector *)ft_malloc(sizeof(t_vector));
	cylinder->pos = (t_vector *)ft_malloc(sizeof(t_vector));
	return (cylinder);
}

t_cone		*ft_malloc_cone(void)
{
	t_cone *cone;

	cone = (t_cone *)ft_malloc(sizeof(t_cone));
	cone->pos = (t_vector *)ft_malloc(sizeof(t_vector));
	cone->dir = (t_vector *)ft_malloc(sizeof(t_vector));
	return (cone);
}