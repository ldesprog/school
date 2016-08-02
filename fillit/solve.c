
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

int		ft_verif(char *map, char *tetriminos, int i_tetri, int pos_map, int size_map, int c)
{
	int i;
	int x;
	int y;
	int z;

	while (tetriminos[i_tetri] != '#')
		i_tetri++;
	i = i_tetri - 1;
	z = 0;
	while (++i < 19 + i_tetri && z < 4)
	{
		if (tetriminos[i] == '#')
		{
			z++;
			x = (i - i_tetri) % 5;
			y = (i - i_tetri) / 5;
			if (map[pos_map + x + y * (size_map + 1)] != '.')
				return (0);
		}
	}
	i = i_tetri - 1;
	z = 0;
	while (++i < 19 + i_tetri && z < 4)
	{
		if (tetriminos[i] == '#')
		{
			z++;
			x = (i - i_tetri) % 5;
			y = (i - i_tetri) / 5;
			map[pos_map + x + y * (size_map + 1)] = c;
		}
	}
	return (1);
}

int		ft_search(int size_map, int nb_tetriminos, char *tetriminos, char *map, int i_tetri)
{
	int pos_map;
	char c;

	pos_map = 0;
	c = (i_tetri + 1) / 21 + 97;
	while (pos_map < (size_map + 1) * size_map)
	{
		if (map[pos_map] == '.' && ft_verif(map, tetriminos, i_tetri, pos_map, size_map, c) == 1)
		{
			if (nb_tetriminos * 21 > i_tetri + 21 && \
				ft_search(size_map, nb_tetriminos, tetriminos, map, i_tetri + 21) == 0)
				ft_clear(map, c, pos_map);
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

void	ft_solve(char *tetriminos)
{
	char *map;
	int size_map;
	int nb_tetriminos;

	size_map = ft_size_map(tetriminos, &nb_tetriminos);
	map = (char *)malloc(sizeof(char) * (size_map + 1) * (size_map + 1));
	map[(size_map + 1) * (size_map + 1)] = 0;
	ft_init_map(map, size_map);
	while (!ft_search(size_map, nb_tetriminos, tetriminos, map, 0))
	{
		size_map++;
		free(map);
		map = (char *)malloc(sizeof(char) * (size_map + 1) * size_map);
		map[(size_map + 1) * (size_map + 1)] = 0;
		ft_init_map(map, size_map);
	}
	write(1, map, ft_strlen(map));
}