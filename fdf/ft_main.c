/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 15:04:38 by ldesprog          #+#    #+#             */
/*   Updated: 2015/01/27 15:04:40 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(t_env *e)
{
	int i;
	int j;

	i = -1;
	while (e->map[++i])
	{
		j = -1;
		while (e->map[i][++j])
			free(e->map[i][j]);
		free(e->map[i][j]);
		free(e->map[i]);
	}
	free(e->map_3d);
	free(e->map[i]);
	free(e->map);
	i = -1;
	while (e->imap[++i])
		free(e->imap[i]);
	free(e->imap[i]);
	free(e->imap);
	free(e->len);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

void	main_2(int fd, t_env *e)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		e->map = remaloc_map(e->map);
		e->map[i] = (char **)ft_strsplit_fdf(line);
		free(line);
		line = NULL;
		i++;
	}
	free(line);
	close(fd);
}

int		main(int ac, char **av)
{
	t_env	*e;
	int		fd;

	if (ac == 1)
	{
		write(1, "usage : ./fdf file1\n", 20);
		return (0);
	}
	e = (t_env *)malloc(sizeof(t_env));
	if (!(e->map = (char ***)ft_malloc(sizeof(char **))))
	{
		free(e);
		return (0);
	}
	e->map[0] = NULL;
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		write(1, av[1], ft_strlen(av[1]));
		write(1, " : No such file or directory\n", 29);
		return (0);
	}
	main_2(fd, e);
	ft_begin_map(e->map, e);
	ft_free(e);
	return (0);
}

void	ft_init(t_env *e)
{
	e->move_x = 500;
	e->move_y = 250;
	e->zoom = 10;
	e->up = 0;
	e->down = 0;
	e->right = 0;
	e->left = 0;
	e->c1 = 0;
	e->c2 = 0;
	e->c3 = 255;
	e->r = 0;
	e->p = 0;
	e->z = 0;
	e->dz = 0;
}
