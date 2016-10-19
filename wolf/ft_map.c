#include "wolf.h"

void	ft_error_map(t_env *e, int error)
{
	if (error == 1)
		write(1, "usage : ./wolf3d map1 [map2 ...]", 32);
	else if (error == 2)
	{
		write(1, "open file error : ", 18);
		ft_putstr(e->av[e->nb]);
	}
	else if (error == 3)
	{
		write(1, "map error : ", 12);
		ft_putstr(e->av[e->nb]);
	}
	else if (error == 4)
	{
		write(1, "player can't spawn : ", 21);
		ft_putstr(e->av[e->nb]);
	}
	write(1, "\n", 1);
	exit(0);
}

void	ft_free_map(t_env *e)
{
	int i;

	i = 0;
	while (i < e->map_hight / e->size)
	{
		free(e->map[i]);
		e->map[i++] = NULL;
	}
	free(e->map);
	e->map = NULL;
	free(e->player->pos);
	e->player->pos = NULL;
	free(e->player);
	e->player = NULL;
}

void	ft_multi_map(t_env *e, int ac, char **av)
{
	if (ac == 1)
		ft_error_map(e, 1);
	e->nb = 1;
	e->ac = ac;
	e->av = av;
	while (e->nb < ac)
	{
		e->end = 0;
		ft_init_env(e);
		ft_init_map(e, av[e->nb]);
		ft_free_map(e);
		e->nb++;
	}
	e->nb = 1;
	e->end = 0;
	ft_init_env(e);
	ft_init_key(e);
	ft_init_map(e, av[1]);
}
