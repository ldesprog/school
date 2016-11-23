#include <rtv1.h>

void	ft_fill_plane(t_env *e, char *line)
{
	t_obj *tmp;
	t_plan *p;

	tmp = e->obj;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
	tmp = tmp->next;
	tmp->obj = (t_plan *)ft_malloc(sizeof(t_plan));
	p = tmp->obj;
	tmp->ft_intersect = ft_inter_plane;
	tmp->ft_hit = ft_plan_hit;
	p->point = (t_vector *)ft_malloc(sizeof(t_vector));
	p->normale = (t_vector *)ft_malloc(sizeof(t_vector));
	ft_fill_vector_from_file(p->point, line, 1);
	ft_fill_vector_from_file(p->normale, line, 4);
	ft_vector_normalize(p->normale);
	ft_put_color_from_line(tmp, line, 7);
	tmp->next = NULL;
}
