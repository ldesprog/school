#include <rtv1.h>

t_cam	*ft_malloc_cam(void)
{
	t_cam *cam;

	cam = (t_cam *)ft_malloc(sizeof(t_cam));
	cam->eye = (t_vector *)ft_malloc(sizeof(t_vector));
	cam->l_at = (t_vector *)ft_malloc(sizeof(t_vector));
	cam->up = (t_vector *)ft_malloc(sizeof(t_vector));
	cam->c = (t_vector *)ft_malloc(sizeof(t_vector));
	cam->l = (t_vector *)ft_malloc(sizeof(t_vector));
	cam->u = (t_vector *)ft_malloc(sizeof(t_vector));
	return (cam);
}

void	ft_calc_cam(t_cam *cam, t_env *e)
{
	cam->n = ft_vector_sub(cam->eye, cam->l_at);
	ft_vector_normalize(cam->n);
	cam->u->x = cam->up->y * cam->n->z - cam->up->z * cam->n->y;
	cam->u->y = cam->up->z * cam->n->x - cam->up->x * cam->n->z;
	cam->u->z = cam->up->x * cam->n->y - cam->up->y * cam->n->x;
	cam->h = tan(M_PI * (cam->fov / 2) / 180) * 2 * cam->dist;
	cam->w = cam->h * ((float)e->mlx->width / (float)e->mlx->height);
	cam->c->x = cam->eye->x - cam->n->x * cam->dist;
	cam->c->y = cam->eye->y - cam->n->y * cam->dist;
	cam->c->z = cam->eye->z - cam->n->z * cam->dist;
	cam->l->x = cam->c->x - cam->u->x * (cam->w / 2) - cam->up->x * (cam->h / 2);
	cam->l->y = cam->c->y - cam->u->y * (cam->w / 2) - cam->up->y * (cam->h / 2);
	cam->l->z = cam->c->z - cam->u->z * (cam->w / 2) - cam->up->z * (cam->h / 2);
}

void	ft_fill_cam(t_env *e, char *line)
{
	char *word;

	e->cam = ft_malloc_cam();
	word = get_word(line, 1);
	if (word == NULL || !strcmp(word, "camera"))
	{
		printf("Map error\n");
		exit(0);
	}
	free(word);
	ft_fill_vector_from_file(e->cam->eye, line, 1);
	ft_fill_vector_from_file(e->cam->l_at, line, 4);
	e->cam->fov = ft_atodi((word = get_word(line, 7)));
	free(word);
	e->cam->dist = 150;
	e->cam->up->x = 0;
	e->cam->up->y = -1;
	e->cam->up->z = 0;
	ft_vector_normalize(e->cam->up);
	ft_calc_cam(e->cam, e);
}
