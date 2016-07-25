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
	char	***map;
	int		fd;

	if (ac == 1)
	{
		write(1, "usage : ./fdf file1\n", 20);
		return (0);
	}
	if (!(map = (char ***)ft_malloc(sizeof(char **))))
		exit(0);
	map[0] = NULL;
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		write(1, av[1], ft_strlen(av[1]));
		write(1, " : No such file or directory\n", 29);
		return (0);
	}
	main_2(fd, &map);
	ft_begin_map(map);
	close(fd);
	return (0);
}
