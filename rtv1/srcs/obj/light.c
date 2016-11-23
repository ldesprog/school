#include <rtv1.h>

void	ft_fill_light(t_env *e, char *line)
{
	t_light *tmp;

	printf("debut light\n");
	tmp = e->light;
	while (tmp->next)
	{
		printf("boucle\n");
		tmp = tmp->next;
	}
	printf("fin boucle next\n");
	tmp->next = (t_light *)ft_malloc(sizeof(t_light));
	tmp = tmp->next;
	tmp->pos = (t_vector *)ft_malloc(sizeof(t_vector));
	ft_fill_vector_from_file(tmp->pos, line, 1);
	tmp->next = NULL;
}
