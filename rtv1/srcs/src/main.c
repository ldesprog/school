#include "rtv1.h"

// void	ft_parcing(t_env *e)
// {
// 	t_obj *tmp;
// 	t_light	*l_tmp;
// 	//pour le moment on va doit juste creer une sphere
// 	//et la camera..

// 	ft_fill_cam(e, "camera -150 150 -200 0 0 200 60");

// 	// e->cam->eye->x = -1500;
// 	// e->cam->eye->y = 150;
// 	// e->cam->eye->z = -2000;
// 	// e->cam->l_at->x = 0;
// 	// e->cam->l_at->y = 0;
// 	// e->cam->l_at->z = 200;
// 	// e->cam->up->x = 0;
// 	// e->cam->up->y = -1;
// 	// e->cam->up->z = 0;
// 	// ft_vector_normalize(e->cam->up);
// 	// e->cam->fov = 45;
// 	// e->cam->dist = 150;
// 	// e->cam->n = ft_vector_sub(e->cam->eye, e->cam->l_at);
// 	// ft_vector_normalize(e->cam->n);
// 	// e->cam->u->x = e->cam->up->y * e->cam->n->z - e->cam->up->z * e->cam->n->y;
// 	// e->cam->u->y = e->cam->up->z * e->cam->n->x - e->cam->up->x * e->cam->n->z;
// 	// e->cam->u->z = e->cam->up->x * e->cam->n->y - e->cam->up->y * e->cam->n->x;
// 	// e->cam->h = tan(M_PI * (e->cam->fov / 2) / 180) * 2 * e->cam->dist;
// 	// e->cam->w = e->cam->h * ((float)e->mlx->width / (float)e->mlx->height);
// 	// e->cam->c->x = e->cam->eye->x - e->cam->n->x * e->cam->dist;
// 	// e->cam->c->y = e->cam->eye->y - e->cam->n->y * e->cam->dist;
// 	// e->cam->c->z = e->cam->eye->z - e->cam->n->z * e->cam->dist;
// 	// e->cam->l->x = e->cam->c->x - e->cam->u->x * (e->cam->w / 2) - e->cam->up->x * (e->cam->h / 2);
// 	// e->cam->l->y = e->cam->c->y - e->cam->u->y * (e->cam->w / 2) - e->cam->up->y * (e->cam->h / 2);
// 	// e->cam->l->z = e->cam->c->z - e->cam->u->z * (e->cam->w / 2) - e->cam->up->z * (e->cam->h / 2);

// 	tmp = e->obj;

// 	tmp->obj = ft_malloc_sphere();
// 	ft_put_color(tmp, 0xff, 0x00, 0x00);
// 	ft_full_sphere(tmp->obj, 500, 500, 200, 40);
// 	tmp->ft_intersect = ft_inter_sphere;
// 	tmp->ft_hit = ft_sphere_hit;
// 	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
// 	tmp = tmp->next;

// 	tmp->obj = ft_malloc_sphere();
// 	ft_put_color(tmp, 0xff, 0x00, 0x00);
// 	ft_full_sphere(tmp->obj, 0, 0, 200, 40);
// 	tmp->ft_intersect = ft_inter_sphere;
// 	tmp->ft_hit = ft_sphere_hit;
// 	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
// 	tmp = tmp->next;

// 	tmp->obj = ft_malloc_sphere();
// 	ft_put_color(tmp, 0xff, 0x00, 0x00);
// 	ft_full_sphere(tmp->obj, 0, 50, 150, 40);
// 	tmp->ft_intersect = ft_inter_sphere;
// 	tmp->ft_hit = ft_sphere_hit;
// 	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
// 	tmp = tmp->next;

// 	tmp->obj = ft_malloc_plan();
// 	ft_put_color(tmp, 0x00, 0x00, 0xff);
// 	ft_full_plan(tmp->obj, 0, 1, 0, 0, -50, 200);
// 	tmp->ft_intersect = ft_inter_plane;
// 	tmp->ft_hit = ft_plan_hit;
// 	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
// 	tmp = tmp->next;

// 	tmp->obj = ft_malloc_plan();
// 	ft_put_color(tmp, 0x00, 0x00, 0xdd);
// 	ft_full_plan(tmp->obj, 0, 0, 1, 0, 0, 300);
// 	tmp->ft_intersect = ft_inter_plane;
// 	tmp->ft_hit = ft_plan_hit;
// 	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
// 	tmp = tmp->next;

// 	tmp->obj = ft_malloc_cone();
// 	ft_put_color(tmp, 0xff, 0xff, 0x00);
// 	ft_full_cone(tmp->obj, 1, 1, 0, 0, 0, 100, 30.0);
// 	tmp->ft_intersect = ft_inter_cone;
// 	tmp->ft_hit = ft_cone_hit;
// 	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
// 	tmp = tmp->next;

// 	tmp->obj = ft_malloc_cylinder();
// 	ft_put_color(tmp, 0xff, 0x00, 0xff);
// 	ft_full_cylinder(tmp->obj, 0, 1, 0, 0, 0, 250, 30);
// 	tmp->ft_intersect = ft_inter_cylinder;
// 	tmp->ft_hit = ft_cylinder_hit;
// 	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
// 	tmp = tmp->next;

// 	tmp->obj = ft_malloc_cylinder();
// 	ft_put_color(tmp, 0xff, 0x00, 0xff);
// 	ft_full_cylinder(tmp->obj, -1, 1, 0, 0, 500, 250, 30);
// 	tmp->ft_intersect = ft_inter_cylinder;
// 	tmp->ft_hit = ft_cylinder_hit;
// 	tmp->next = (t_obj *)ft_malloc(sizeof(t_obj));
// 	tmp = tmp->next;

// 	tmp->obj = ft_malloc_cylinder();
// 	ft_put_color(tmp, 0xff, 0x00, 0xff);
// 	ft_full_cylinder(tmp->obj, 0, 1, 0, -500, 0, 250, 30);
// 	tmp->ft_intersect = ft_inter_cylinder;
// 	tmp->ft_hit = ft_cylinder_hit;

// 	tmp->next = NULL;
// 	e->light = ft_malloc_light();
// 	ft_full_light(e->light, -100, 300, -100, 1);
// 	l_tmp = e->light;
// 	l_tmp->next = ft_malloc_light();
// 	l_tmp = l_tmp->next;
// 	ft_full_light(l_tmp, 100, 300, -100, 1);

// 	l_tmp->next = NULL;
// }

void	ft_init(t_env *e)
{
	e->mlx = (t_mlx *)ft_malloc(sizeof(t_mlx));

	e->b = (t_vector *)ft_malloc(sizeof(t_vector));
	e->obj = (t_obj *)ft_malloc(sizeof(t_obj));
	e->obj->next = NULL;
	e->light = (t_light *)ft_malloc(sizeof(t_light));
	e->light->next = NULL;
	e->c_hit = (t_color *)ft_malloc(sizeof(t_color));
	e->mlx->height = 768;
	e->mlx->width = 1024;
}

void	ft_ray(int x, int y, t_env *e)
{
	double	dist;
	int		hit;
	t_vector *p_hit;
	double dist_l;
	int hit_l;
	t_vector *l_vector;
	double angle;
	t_obj *tmp;
	t_light *l_tmp;

	e->b->x = e->cam->l->x + e->cam->u->x * x * (e->cam->w / e->mlx->width) + e->cam->up->x * y * (e->cam->h / e->mlx->height);
	e->b->y = e->cam->l->y + e->cam->u->y * x * (e->cam->w / e->mlx->width) + e->cam->up->y * y * (e->cam->h / e->mlx->height);
	e->b->z = e->cam->l->z + e->cam->u->z * x * (e->cam->w / e->mlx->width) + e->cam->up->z * y * (e->cam->h / e->mlx->height);

	e->dir = ft_vector_sub(e->b, e->cam->eye);
	ft_vector_normalize(e->dir);
	dist = DIST_MAX;
	tmp = e->obj;
	e->o_hit = NULL;
	ft_fill_color(e->c_hit, 0x00, 0x00, 0x00);
	while (tmp)
	{
		hit = tmp->ft_intersect(tmp->obj, e->cam->eye, e->dir, &dist);
		if (hit)
		{
			e->o_hit = tmp;
			ft_fill_color(e->c_hit, tmp->c->r, tmp->c->g, tmp->c->b);
		}
		tmp = tmp->next;
	}
	l_tmp = e->light;
	e->angle = 0;
	while (dist < DIST_MAX && l_tmp)
	{
		p_hit = ft_p_hit(e->cam->eye, e->dir, dist);
		l_vector = ft_vector_sub(l_tmp->pos, p_hit);
		dist_l = sqrt(ft_vector_dot(l_vector, l_vector));
		ft_vector_normalize(l_vector);
		tmp = e->obj;
		while (tmp)
		{
			hit_l = tmp->ft_intersect(tmp->obj, p_hit, l_vector, &dist_l);
			if (hit_l)
				break;
			tmp = tmp->next;
		}
		if (!hit_l)
		{
			angle = e->o_hit->ft_hit(e->o_hit->obj, p_hit, l_vector, e);
			if (angle < 0)
				angle *= -1;
			e->angle += angle;
		}
		l_tmp = l_tmp->next;
		free(l_vector);
		free(p_hit);
	}
	if (e->angle > 1)
		e->angle = 1;
	ft_print_pixel(e, x, y, e->angle);
	free(e->dir);
}

void	ft_start(t_env *e)
{
	//et la on commence le ray tracing
	int x;
	int y;

	//boucle principale
	 y = 0;
	 while (y < e->mlx->height)
	 {
	 	
	 	x = 0;
	 	while (x < e->mlx->width)
	 	{
	 		//lancer le rayon
	 		
	 		ft_ray(x, y, e);
	 		x++;

	 	}
	 	y++;
	 	// break;
	 }
}

// void	ft_test_parcing(t_env *e)
// {
// 	printf("camera\n");
// 	printf("pos : %f, %f, %f\ndir : %f, %f, %f\nfov : %f", e->cam->eye->x, e->cam->eye->y, e->cam->eye->z, e->cam->l_at->x, e->cam->l_at->y, e->cam->l_at->z, e->cam->fov);
// 	printf("\n");
// 	printf("light\n");
// 	printf("pos : %f, %f, %f\n", e->light->pos->x, e->light->pos->y, e->light->pos->z);
// 	printf("light 2\n");
// 	printf("pos : %f, %f, %f\n", e->light->next->pos->x, e->light->next->pos->y, e->light->next->pos->z);
// 	printf("\n");
// 	printf("la suite g la flemme, sa marche ?\n");
// }

int main(int ac, char **av)
{
	t_env *e;

	(void)ac;
	e = (t_env *)ft_malloc(sizeof(t_env));
	ft_init(e);
	ft_parcing(e, av[1]);

	// ft_test_parcing(e);
	//on prepare la mlx
	e->mlx->mlx = mlx_init();
	e->mlx->win = mlx_new_window(e->mlx->mlx, e->mlx->width, e->mlx->height, "RTV1");
	e->mlx->img = mlx_new_image(e->mlx->mlx, e->mlx->width, e->mlx->height);
	e->mlx->data = mlx_get_data_addr(e->mlx->img, &(e->mlx->bpp),
		&(e->mlx->s_line), &(e->mlx->endian));

	//on lance le raytrace
	ft_start(e);
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, e->mlx->img, 0, 0);
	//on loop

	mlx_loop(e->mlx->mlx);
	return (0);
}
