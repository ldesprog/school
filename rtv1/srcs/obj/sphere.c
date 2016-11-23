#include <rtv1.h>

void	ft_fill_sphere(t_env *e, char *line)
{
	t_obj *tmp;
	t_sphere *s;
	char *word;

	tmp = e->obj;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
	tmp = tmp->next;
	tmp->obj = (t_sphere *)ft_malloc(sizeof(t_sphere));
	s = tmp->obj;
	tmp->ft_intersect = ft_inter_sphere;
	tmp->ft_hit = ft_sphere_hit;
	s->pos = (t_vector *)ft_malloc(sizeof(t_vector));
	ft_fill_vector_from_file(s->pos, line, 1);
	s->radius = ft_is_int((word = get_word(line, 4)));
	ft_put_color_from_line(tmp, line, 5);
	free(word);
	tmp->next = NULL;
}
