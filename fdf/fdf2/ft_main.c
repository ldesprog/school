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
/*
void	ft_free(t_env *e)
{
	int i;
	int j;

	i = 0;
	printf("free ft_free\n");
	while (e->map[i])
	{
		j = 0;
		while (e->map[i][j])
		{
			free(e->map[i][j]);
			j++;
		}
		free(e->map[i][j]);
		free(e->map[i]);
		i++;
	}
	free(e->map[i]);
	free(e->map);
	i = 0;
	while (e->high > i)
	{
		free(e->map_3d[i]);
		i++;
	}
	free(e->map_3d);
	i = 0;
	while (e->imap[i])
	{
		free(e->imap[i]);
		i++;
	}
	free(e->imap);
	free(e->len);
	close(e->fd);
	
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}*/

void	main_2(int fd, char ****map)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		*map = remaloc_map(*map);
		(*map)[i] = (char **)ft_strsplit_fdf(line);
		ft_clean(line);
		i++;
	}
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
	main_2(fd, &(e->map));
	ft_begin_map(e->map, e, fd);
	//ft_free(e);
	return (0);
}
