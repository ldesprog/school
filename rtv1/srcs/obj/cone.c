#include <rtv1.h>

void	ft_fill_cone(t_env *e, char *line)
{
	t_obj *tmp;
	t_cone *c;
	char *word;

	tmp = e->obj;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
	tmp = tmp->next;
	tmp->obj = (t_cone *)ft_malloc(sizeof(t_cone));
	c = tmp->obj;
	tmp->ft_intersect = ft_inter_cone;
	tmp->ft_hit = ft_cone_hit;
	c->pos = (t_vector *)ft_malloc(sizeof(t_vector));
	c->dir = (t_vector *)ft_malloc(sizeof(t_vector));
	ft_fill_vector_from_file(c->pos, line, 1);

	ft_fill_vector_from_file(c->dir, line, 4);
	ft_vector_normalize(c->dir);
	c->angle = ft_is_int((word = get_word(line, 7)));
	ft_put_color_from_line(tmp, line, 8);
	free(word);
	tmp->next = NULL;
	printf("je fait le connnnne\n");
	printf("%f, %f, %f\n", c->pos->x, c->pos->y, c->pos->z);
	printf("%f, %f, %f\n", c->dir->x, c->dir->y, c->dir->z);
	printf("%f\n", c->angle);
	printf("%d, %d, %d\n", tmp->c->r, tmp->c->g, tmp->c->b);
}