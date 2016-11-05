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
	ft_vector_normalize(e->ray_O);
	printf("%f, %f, %f\n", e->ray_O->x, e->ray_O->y, e->ray_O->z);
	printf("parcing millieu 2\n");
	e->object->pos->x = 0;
	e->object->pos->y = 0;
	e->object->pos->z = 200;
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
	e->mlx->height = 480;
	e->mlx->width = 640;
}

void	ft_ray(int x, int y, t_env *e)
{
	double	dist;
	int		intersection;

	e->b->x = x - e->mlx->width / 2;
	e->b->y = y - e->mlx->height / 2;
	e->b->z = (e->mlx->width / (2 * tan(30/2)));//30 : distance focale focale
	ft_vector_normalize(e->b);
	e->ray_D->x = e->b->x - e->ray_O->x;
	e->ray_D->y = e->b->y - e->ray_O->y;
	e->ray_D->z = e->b->z - e->ray_O->z;
	dist = DIST_MAX;
	//faire une boucle pour gerer une mutitude d'object
	printf("%f, %f, %f\n", e->ray_O->x, e->ray_O->y, e->ray_O->z);
	printf("%f, %f, %f\n", e->ray_D->x, e->ray_D->y, e->ray_D->z);
	intersection = ft_intersection(e->object, e->ray_O, e->ray_D, &dist);
	if (intersection > 0)
		printf("on a trouver une intersection\n");
	if (intersection > 0 && dist < DIST_MAX)
	{
		//on lance le calcul pour la lumiere
		//on met le bon pixel
		ft_print_pixel(e, x, y);
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
	e->mlx->data = (int *)mlx_get_data_addr(e->mlx->img, &(e->mlx->bpp),
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