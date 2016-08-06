#include "wolf.h"

char	**ft_remalloc_tab(char **tab, int n)
{
	int i;
	char **new;

	new = (char **)malloc(sizeof(char *) * (n + 1));
	i = 0;
	while (i < n)
	{
		new[i] = tab[i];
		i++;
	}
	free(tab);
	return (new);
}

int		ft_len_str(char *str)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		n++;
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] == ' ')
			i++;
	}
	return n;
}

int *ft_split(char *str, int j)
{
	int i;
	int n;
	int *map;

	map = (int *)malloc(sizeof(int) * j);
	i = 0;
	n = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == 48 && str[i + 1] == ' ')
			map[n] = 0;
		else
			map[n] = 1;
		n++;
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] == ' ')
			i++;
	}
	return map;
}

int **ft_split_to_int(char **tab, int i, int *j)
{
	int **map;
	int n;

	map = (int **)malloc(sizeof(int *) * i);
	*j = ft_len_str(tab[0]);
	n = 0;
	while (n < i)
	{
		map[n] = ft_split(tab[n], *j);
		n++;
	}
	return map;
}

void	ft_init_map(t_env *e, char *file)
{
	int i;
	int fd;
	char **tab;

	if ((fd = open(file, O_RDONLY)) < 0)
		exit(0);
	i = 0;
	tab = (char **)malloc(sizeof(char *));
	while (get_next_line(fd, &tab[i]) > 0)
	{
		i++;
		tab = ft_remalloc_tab(tab, i);
		tab[i] = NULL;
	}
	e->map_hight = i * e->size;
	e->map = ft_split_to_int(tab, i, &e->map_weight);
	e->map_weight *= e->size;
}

void	ft_free(t_env *env)
{
	int i;

	i = 0;
	while (i < env->map_hight / env->size)
		free(env->map[i++]);
	free(env->map);
	free(env->player->pos);
	free(env->player);
	free(env);
}

void	ft_init_env(t_env *env)
{
	env->hight = 800;
	env->weight = 1200;
	env->angle = 60;
	env->dist_ecran = 500;
	env->size = 1000;
	env->player = (t_player *)malloc(sizeof(t_player));
	env->player->pos = (t_pos *)malloc(sizeof(t_pos));
	env->player->pos->x = 2509;
	env->player->pos->y = 2869;
	env->player->dir = 135;
}

int main(void)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	ft_init_env(e);
	ft_init_map(e, "map.wolf");
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1920, 1080, "WOLF 3D");
	e->img = mlx_new_image(e->mlx, 1920, 1080);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian));
	ft_wolf(e);
	mlx_loop(e->mlx);
	ft_free(e);
	return 0;
}