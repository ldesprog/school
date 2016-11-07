#include "rtv1.h"

void	ft_parcing(t_env *e)
{
	//pour le moment on va doit juste creer une sphere
	//et la camera..
	printf("parcing debut\n");
	e->ray_O->x = 0;
	e->ray_O->y = 0;
	e->ray_O->z = 0;
	printf("parcing millieu 1\n");
	printf("%f, %f, %f\n", e->ray_O->x, e->ray_O->y, e->ray_O->z);
	printf("parcing millieu 2\n");
	e->object->pos->x = 0;
	e->object->pos->y = 0;
	e->object->pos->z = 200;
	e->light->pos->x = 200;
	e->light->pos->y = 200;
	e->light->pos->z =200;
	printf("parcing fin\n");
}

void	ft_init(t_env *e)
{
	e->mlx = (t_mlx *)ft_malloc(sizeof(t_mlx));
	e->ray_O = (t_vector *)ft_malloc(sizeof(t_vector));
	e->ray_D = (t_vector *)ft_malloc(sizeof(t_vector));
	e->b = (t_vector *)ft_malloc(sizeof(t_vector));
	//on pensera a changer le type ici aussi
	e->object = (t_sphere *)ft_malloc(sizeof(t_sphere));
	e->object->pos = (t_vector *)ft_malloc(sizeof(t_vector));
	e->object->radius = 20;
	e->light = (t_light *)ft_malloc(sizeof(t_light));
	e->light->pos = (t_vector *)ft_malloc(sizeof(t_vector));
	e->mlx->height = 480;
	e->mlx->width = 640;
}

void	ft_ray(int x, int y, t_env *e)
{
	double	dist;
	int		hit;
	t_vector *p_hit;
	double dist_l;
	int hit_l;
	t_vector *l_vector;
	t_vector *n_hit;


	e->b->x = x - e->mlx->width / 2;
	e->b->y = y - e->mlx->height / 2;
	e->b->z = -1 * (e->mlx->width / (2 * tan(30/2)));//30 : distance focale focale
	ft_vector_normalize(e->b);
	e->ray_D = ft_vector_sub(e->b, e->ray_O);
	//possible matrice de rotation sur ray_D pour rotate la camera
	dist = DIST_MAX;
	//faire une boucle pour gerer une mutitude d'object
	hit = ft_intersection(e->object, e->ray_O, e->ray_D, &dist);
	if (hit > 0 && dist < DIST_MAX)
	{
	//on lance le calcul pour la lumiere
		//on calcul la position d'intersection
		p_hit = ft_p_hit(e->ray_O, e->ray_D, dist);
		//on relance intersection entre le nouveau depart et la lumiere
		dist_l = DIST_MAX;
		l_vector = ft_vector_sub(e->light->pos, p_hit);
		hit_l = ft_intersection(e->object, p_hit, l_vector, &dist_l);
		//on calcule la force de la lumiere selon l'angle
		if (!hit_l)
		{
			n_hit = ft_vector_sub(p_hit, e->object->pos);
			ft_vector_normalize(n_hit);
			ft_vector_normalize(l_vector);
			ft_print_pixel(e, x, y, ft_vector_dot(n_hit, l_vector));
		}
	//on met le bon pixel
		
	}
}

void	ft_start(t_env *e)
{
	//et la on commence le ray tracing
	int x;
	int y;

	//boucle principale
	 x = 0;
	 while (x < e->mlx->width)
	 {
	 	y = 0;
	 	while (y < e->mlx->height)
	 	{
	 		//lancer le rayon
	 		ft_ray(x, y, e);
	 		y++;
	 	}
	 	x++;
	 }
	 printf("%i, %i\n", x, y);
}

int main(void)
{
	t_env *e;

	printf("debut\n");
	e = (t_env *)ft_malloc(sizeof(t_env));
	printf("init\n");
	ft_init(e);
	//faire le parcing
	printf("parcing\n");
	ft_parcing(e);
	//on prepare la mlx
	printf("mlx\n");
	e->mlx->mlx = mlx_init();
	e->mlx->win = mlx_new_window(e->mlx->mlx, e->mlx->width, e->mlx->height, "RTV1");
	e->mlx->img = mlx_new_image(e->mlx->mlx, e->mlx->width, e->mlx->height);
	e->mlx->data = mlx_get_data_addr(e->mlx->img, &(e->mlx->bpp),
		&(e->mlx->s_line), &(e->mlx->endian));
	//on lance le raytrace
	printf("sa start\n");
	ft_start(e);
	printf("sa va put\n");
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, e->mlx->img, 0, 0);
	//on loop
	mlx_loop(e->mlx->mlx);
	return (0);
}