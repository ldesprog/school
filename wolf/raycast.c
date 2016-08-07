#include "wolf.h"

void	ft_put_img_to_win(t_env *e)
{

}

void	ft_init_pos(t_pos *pos, float x, float y)
{
	pos->x = x;
	pos->y = y;
}

float	ft_abs(float n)
{
	if (n < 0)
		n *= -1;
	return n;
}

void	ft_init_wall_hori(t_env *e, float dir, t_pos *a, t_pos *t)
{
	if (dir < 180)
	{
		t->y = - 1 * e->size;
		t->x = e->size / tan(M_PI * dir / 180);
		a->y = (int)(e->player->pos->y / e->size) * e->size - 1;
		a->x = e->player->pos->x + (e->player->pos->y - a->y - 1)
			/ tan(M_PI * dir / 180);
	}
	else
	{
		t->y = e->size;
		t->x = e->size / tan(M_PI * dir / 180) * -1;
		a->y = (int)(e->player->pos->y / e->size) * e->size + e->size;
		a->x = e->player->pos->x + (e->player->pos->y - a->y)
			/ tan(M_PI * dir / 180);
	}
}

float	ft_wall_hori(t_env *e, float dir)
{
	t_pos a;
	t_pos t;

	ft_init_wall_hori(e, dir, &a, &t);
	while (a.y >= 0 && a.y  < e->map_hight && a.x >= 0 && a.x < e->map_weight
		&& !e->map[(int)a.y / e->size][(int)a.x / e->size])
		ft_init_pos(&a, a.x + t.x, a.y + t.y);
	if (a.y < 0 || a.y  >= e->map_hight || a.x < 0 || a.x >= e->map_weight)
		return -1;
	if (dir < 180)
		return (sqrt(ft_abs(pow((e->player->pos->y - a.y - 1), 2))
			+ ft_abs(pow((e->player->pos->x - a.x), 2))));
	return (sqrt(ft_abs(pow((e->player->pos->y - a.y), 2))
		+ ft_abs(pow((e->player->pos->x - a.x), 2))));
}

void	ft_init_wall_verti(t_env *e, float dir, t_pos *b, t_pos *t)
{
	if (dir > 90 && dir < 270)
	{
		t->x = -1 * e->size;
		t->y = e->size * tan(M_PI * dir / 180);
		b->x = (int)(e->player->pos->x / e->size) * e->size - 1;
		b->y = e->player->pos->y + (e->player->pos->x - b->x - 1)
			* tan(M_PI * dir / 180);
	}
	else
	{
		t->x = e->size;
		t->y = e->size * tan(M_PI * dir / 180) * -1;
		b->x = (int)(e->player->pos->x / e->size) * e->size + e->size;
		b->y = e->player->pos->y + (e->player->pos->x - b->x)
			* tan(M_PI * dir / 180);
	}
}

float	ft_wall_verti(t_env *e, float dir)
{
	t_pos b;
	t_pos t;

	ft_init_wall_verti(e, dir, &b, &t);
	while (b.y >= 0 && b.y  < e->map_hight && b.x >= 0 && b.x < e->map_weight
		&& !e->map[(int)b.y / e->size][(int)b.x / e->size])
		ft_init_pos(&b, b.x + t.x, b.y + t.y);
	if (b.y < 0 || b.y  >= e->map_hight || b.x < 0 || b.x >= e->map_weight)
		return -1;
	if (dir > 90 && dir < 270)
		return (sqrt(ft_abs(pow((e->player->pos->y - b.y), 2))
			+ ft_abs(pow((e->player->pos->x - b.x - 1), 2))));
	return (sqrt(ft_abs(pow((e->player->pos->y - b.y), 2))
		+ ft_abs(pow((e->player->pos->x - b.x), 2))));
}

void	ft_color(int c, int *c1, int *c2, int *c3)
{
	if (c == 1)
	{
		*c1 = 0xff;
		*c2 = 0x00;
		*c3 = 0x00;
	}
	else if (c == 2)
	{
		*c1 = 0x00;
		*c2 = 0xff;
		*c3 = 0x00;
	}
	else if (c == 3)
	{
		*c1 = 0xff;
		*c2 = 0x00;
		*c3 = 0xff;
	}
	else
	{
		*c1 = 0x00;
		*c2 = 0x00;
		*c3 = 0xff;
	}
}

void	ft_paint(t_env e, int c1, int c2, int c3)
{
	*(e.data + e.y * e.sizeline + e.bpp / 8 * e.x) = c1;
	*(e.data + e.y * e.sizeline + e.bpp / 8 * e.x + 1) = c2;
	*(e.data + e.y * e.sizeline + e.bpp / 8 * e.x + 2) = c3;
}

//pour la sdl ......
void	ft_ray(t_env *e, float dist, int x, int color)
{
	int c1;
	int c2;
	int c3;

	e->x = x;
	e->c = color;
	ft_color(e->c, &c1, &c2, &c3);
	e->mur = (int)((float)e->size / dist * e->hight);
	e->plafond = e->hight / 2 - e->mur / 2;
	e->y = -1;
	while (++(e->y) < e->plafond)
		ft_paint(*e, 0x00, 0x00, 0x00);
	e->mur += e->y;
	(e->y)--;
	while (++(e->y) < e->mur && e->y < e->hight)
		ft_paint(*e, c1, c2, c3);
	(e->y)--;
	while (++(e->y) < e->hight)
		ft_paint(*e, 0x00, 0x00, 0x00);
}

void	ft_avance(int i, t_env *e)
{
	int x;
	int y;

	x = 80 * i * cos(M_PI * e->player->dir / 180);
	y = 80 * -1 * i * sin(M_PI * e->player->dir / 180);
	if (e->map[(int)(e->player->pos->y + y) / e->size]
		[(int)(e->player->pos->x + x) / e->size] == 0)
	{
		x = 20 * i * cos(M_PI * e->player->dir / 180);
		y = 20 * -1 * i * sin(M_PI * e->player->dir / 180);
		e->player->pos->x += x;
		e->player->pos->y += y;
		ft_raycast(e);
	}
}

void	ft_tourne(int i, t_env *e)
{
	e->player->dir += i;
	if (e->player->dir >= 360)
		e->player->dir -= 360;
	else if (e->player->dir < 0)
		e->player->dir += 360;
	ft_raycast(e);
}

int 	ft_key(int keycode, void *param)
{
	if (keycode == 53)
		ft_free((t_env *)param);
	else if (keycode == 123)
		ft_tourne(1, param);
	else if (keycode == 124)
		ft_tourne(-1, param);
	else if (keycode == 125)
		ft_avance(-1, param);
	else if (keycode == 126)
		ft_avance(1, param);
	return (0);
}

void	ft_raycast_2(t_env *e, int x, float dir_x, float dir_p)
{
	if (e->b == -1 || (e->a != -1 && e->a < e->b))
	{
		e->a = e->a * cos(M_PI * dir_x / 180);
		if (dir_x + dir_p > 180)
			ft_ray(e, e->a, x, 1);
		else
			ft_ray(e, e->a, x, 2);
	}
	else if (e->a == -1 || (e->b != -1 && e->a > e->b))
	{
		e->b = e->b * cos(M_PI * dir_x / 180);
		if (dir_x + dir_p > 90 && dir_x + dir_p < 270)
			ft_ray(e, e->b, x, 3);
		else
			ft_ray(e, e->b, x, 4);
	}
	else if (e->a == e->b)
	{
		e->b = e->b * cos(M_PI * dir_x / 180);
		ft_ray(e, e->b, x, e->c);
	}
}

void	ft_raycast_1(t_env *e, int x, float dir_p, float dir_x)
{
	if (dir_x + dir_p != 0 && dir_x + dir_p != 180)
		e->a = ft_wall_hori(e, dir_x + dir_p);
	else
		e->a = -1;
	if (dir_x + dir_p != 90 && dir_x + dir_p != 270)
		e->b = ft_wall_verti(e, dir_x + dir_p);
	else
		e->b = -1;
	ft_raycast_2(e, x, dir_x, dir_p);
}

void	ft_raycast(t_env *e)
{
	int x;
	float add_angle;

	e->img = mlx_new_image(e->mlx, e->weight, e->hight);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian));
	e->dir_p = e->player->dir;
	e->dir_x = e->angle / 2;
	add_angle = (float)e->angle / e->weight;
	x = 0;
	while (x < e->weight)
	{
		if (e->dir_x + e->dir_p >= 360)
			e->dir_p -= 360;
		if (e->dir_x + e->dir_p < 0)
			e->dir_p += 360;
		ft_raycast_1(e, x, e->dir_p, e->dir_x);
		x++;
		e->dir_x -= add_angle;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
}

int	ft_wolf(t_env *env)
{
	ft_raycast(env);
	return (0);
}