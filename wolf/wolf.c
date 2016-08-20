/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:07:02 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/17 15:07:07 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_init_map(t_env *e, char *file)
{
	int		i;
	int		fd;
	char	**tab;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		free(e->player);
		free(e->player->pos);
		exit(0);
	}
	i = 0;
	tab = (char **)malloc(sizeof(char *));
	while (get_next_line(fd, &tab[i]) > 0)
	{
		tab = ft_remalloc_tab(tab, ++i);
		tab[i] = NULL;
	}
	e->map_hight = i * e->size;
	e->map = ft_split_to_int(tab, i, &e->map_weight);
	e->map_weight *= e->size;
	close(fd);
	fd = 0;
	while (fd <= i)
		free(tab[fd++]);
	free(tab);
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
	env->player->pos->x = 1500;
	env->player->pos->y = 1500;
	env->player->dir = 135;
}

int		ft_verif_map(int **map, int len, int high)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		if (map[0][i] == 0)
			return (0);
		if (map[high - 1][i++] == 0)
			return (0);
	}
	j = 0;
	while (j < high)
	{
		if (map[j][0] == 0)
			return (0);
		if (map[j++][len - 1] == 0)
			return (0);
	}
	if (len < 3 || high < 3 || map[1][1] != 0)
	{
		write(1, "error : player can't spawn\n", 27);
		return (0);
	}
	return (1);
}

int		main(void)
{
	t_env *e;

	e = (t_env *)malloc(sizeof(t_env));
	ft_init_env(e);
	ft_init_map(e, "map.wolf");
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->weight, e->hight, "WOLF 3D");
	ft_wolf(e);
	mlx_hook(e->win, 2, 0, &ft_key_down, e);
	mlx_hook(e->win, 3, 0, &ft_key_up, e);
	mlx_hook(e->win, 17, 0, &ft_red_cross, e);
	mlx_loop_hook(e->mlx, &ft_wolf, e);
	mlx_loop(e->mlx);
	ft_free(e);
	return (0);
}
