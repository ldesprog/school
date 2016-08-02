
#include "fillit.h"

///////////////////////////////////////////////////////////////////////////////

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

////////////////////////////////////////////////////////////////////////////////

void	ft_clear(char *map, int c, int pos_map)
{
	while (map[pos_map])
	{
		if (map[pos_map] == c)
			map[pos_map] = '.';
		pos_map++;
	}
}

void	ft_verif_2(t_fillit *map, int pos_map, int i_tetri, int c)
{
	int i;
	int x;
	int y;
	int z;

	i = -1;
	z = 0;
	while (++i < 19 && z < 4)
	{
		if (map->tetriminos[i + i_tetri] == '#')
		{
			z++;
			x = (i - map->n) % 5;
			y = (i - map->n) / 5;
			map->map[pos_map + x + y * (map->s_map + 1)] = c;
		}
	}
}

int		ft_verif(t_fillit *map, int pos_map, int i_tetri, int c)
{
	int i;
	int x;
	int y;
	int z;

	i = 0;
	while (map->tetriminos[i_tetri + i] != '#')
		i++;
	map->n = i;
	i--;
	z = 0;
	while (++i < 19 && z < 4)
	{
		if (map->tetriminos[i + i_tetri] == '#')
		{
			z++;
			x = (i - map->n) % 5;
			y = (i - map->n) / 5;
			if (map->map[pos_map + x + y * (map->s_map + 1)] != '.')
				return (0);
		}
	}
	ft_verif_2(map, pos_map, i_tetri, c);
	return (1);
}

int		ft_search(t_fillit *map, int nb_tetriminos, int i_tetri, int pos_map)
{
	char c;

	pos_map = 0;
	c = (i_tetri + 1) / 21 + 97;
	while (pos_map < (map->s_map + 1) * map->s_map)
	{
		if (map->map[pos_map] == '.' \
			&& ft_verif(map, pos_map, i_tetri, c) == 1)
		{
			if (nb_tetriminos * 21 > i_tetri + 21 && \
				ft_search(map, nb_tetriminos, i_tetri + 21, pos_map) == 0)
				ft_clear(map->map, c, pos_map);
			else
				return (1);
		}
		pos_map++;
	}
	return (0);
}

int		ft_size_map(char *tetriminos, int *nb_tetriminos)
{
	int i;
	int n;
	int len;

	len = ft_strlen(tetriminos);
	i = 0;
	n = 0;
	while (i < len)
	{
		n++;
		i += 21;
	}
	*nb_tetriminos = n;
	i = 0;
	while (i * i < n * 4)
		i++;
	return (i);
}

void	ft_init_map(char *map, int size_map)
{
	int i;
	int j;

	i = 0;
	while (i < size_map)
	{
		j = 0;
		while (j < size_map)
		{
			map[i * (size_map + 1) + j] = '.';
			j++;
		}
		map[i * (size_map + 1) + j] = '\n';
		i++;
	}
	j = 0;
	while (j < size_map)
	{
		map[i * (size_map + 1) + j] = '\0';
		j++;
	}
}

void	ft_solve(t_fillit *map)
{
	int 		nb_tetriminos;

	map->s_map = ft_size_map(map->tetriminos, &nb_tetriminos);
	map->map = (char *)malloc(1 * (map->s_map + 1) * (map->s_map + 1));
	map->map[(map->s_map + 1) * (map->s_map + 1)] = 0;
	ft_init_map(map->map, map->s_map);
	while (!ft_search(map, nb_tetriminos, 0, 0))
	{
		map->s_map++;
		free(map->map);
		map->map = (char *)malloc(1 * (map->s_map + 1) * map->s_map);
		map->map[(map->s_map + 1) * (map->s_map + 1)] = 0;
		ft_init_map(map->map, map->s_map);
	}
	write(1, map->map, ft_strlen(map->map));
	free(map->tetriminos);
	free(map);
}
