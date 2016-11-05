#include "rtv1.h"

void		ft_vector_normalize(t_vector *v)
{
	double	id;
	double	x;
	double	y;
	double	z;

	x = v->x * v->x;
	y = v->y * v->y;
	z = v->z * v->z;
	if (x + y + z == 0)
		id = 0;
	else
		id = 1 / sqrt(x + y + z);
	v->x = v->x * id;
	v->y = v->y * id;
	v->z = v->z * id;
}

double		ft_vector_dot(t_vector *a, t_vector *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vector	*ft_vector_copy(t_vector *a)
{
	t_vector *v;

	v = (t_vector *)ft_malloc(sizeof(t_vector));
	v->x = a->x;
	v->y = a->y;
	v->z = a->z;
	return (v);
}

t_vector	*ft_vector_sub(t_vector *a, t_vector *b)
{
	t_vector *v;

	v = (t_vector *)ft_malloc(sizeof(t_vector));
	v->x = a->x - b->x;
	v->y = a->y - b->y;
	v->z = a->z - b->z;
	return (v);
}