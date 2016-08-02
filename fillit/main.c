
#include "fillit.h"

int		main(int ac, char **av)
{
	char *tetriminos;
	int i;

	if (ac != 2)
	{
		write(1, "usage : ./fillit fichier.fillit\n", 32);
		exit(0);
	}
	tetriminos = ft_read_file(av[1]);
	if (!ft_verif_file(tetriminos) || !ft_is_tetri(tetriminos))
	{
		free(tetriminos);
		write(1, "error\n", 6);
		exit(0);
	}
	i = -1;
	while (tetriminos[++i])
	{
		if (tetriminos[i] == '1')
			tetriminos[i] = '#';
	}
	ft_solve(tetriminos);
	free(tetriminos);
	return (0);
}

int		ft_is_tetri_3(char *file, int i, int *j, int move)
{
	file[i + *j] = '1';
	*j += move;
	return (1);
}

void	ft_is_tetri_2(char *file, int i, int *j, int *n)
{
	if (*j > 0 && file[i + *j - 1] == '#')
		 *n += ft_is_tetri_3(file, i, j, -1);
	else if (*j < 14 && file[i + *j + 5] == '#')
		 *n += ft_is_tetri_3(file, i, j, 5);
	else if (*j < 18 && file[i + *j + 1] == '#')
		 *n += ft_is_tetri_3(file, i, j, 1);
	else if (*j > 4 && file[i + *j - 5] == '#')
		 *n += ft_is_tetri_3(file, i, j, -5);
	else if (*j > 4 && file[i + *j - 5] == '1')
		 ft_is_tetri_3(file, i, j, -5);
	else if (*j < 18 && file[i + *j + 1] == '1')
		 ft_is_tetri_3(file, i, j, 1);
	else if (*j < 14 && file[i + *j + 5] == '1')
		 ft_is_tetri_3(file, i, j, 5);
	else if (*j > 0 && file[i + *j - 1] == '1')
		 ft_is_tetri_3(file, i, j, -1);
}

int		ft_is_tetri(char *file)
{
	int i;
	int j;
	int n;
	int x;

	i = 0;
	while (file[i])
	{
		j = 0;
		x = 0;
		while (file[i + j] != '#' && j < 21)
			j++;
		n = 1;
		file[i + j] = '1';
		while (n < 4)
		{
			x++;
			if (x > 15)
				return (0);
			ft_is_tetri_2(file, i, &j, &n);
		}
		i += 21;
	}
	return (1);
}

int		ft_verif_file_2(char *file)
{
	int i;
	int j;
	int n;

	i = 0;
	while (file[i])
	{
		n = 0;
		j = 0;
		while (j < 21)
		{
			if (file [i + j] == '#')
				n++;
			j++;
		}
		if (n != 4)
			return (0);
		i += 21;
	}
	return (1);
}

int		ft_verif_file(char *file)
{
	int i;
	int j;
	int x;

	i = 0;
	j = 0;
	x = 0;
	while (file[i + j * 5 + x * 21])
	{
		if (file[i + j * 5 + x * 21] == '#' || file[i + j * 5 + x * 21] == '.')
			i++;
		else if (file[i + j * 5 + x * 21] == '\n' && i == 4 && ++j)
			i = 0;
		else if (file[i + j * 5 + x * 21] == '\n' && i == 0 && j == 4\
			 && (file[i + 1 + j * 5 + x * 21] == '#' \
				|| file[i + 1 + j * 5 + x * 21] == '.') && ++x)
			j = 0;
		else
			return (0);
		if (x >= 26)
			return (0);
	}
	if (file[i -1 + j * 5 + x * 21] != '\n' || file[i - 2 + j * 5 + x * 21] == '\n')
		return (0);
	return (x * ft_verif_file_2(file));
}

char	*ft_read_file(char *file)
{
	int fd;
	char *tetriminos;
	int i;
	char c;

	fd = open(file, O_RDONLY);
	i = 0;
	while (read(fd, &c, 1))
		i++;
	close(fd);
	tetriminos = (char *)malloc(sizeof(char) * (i + 5));
	fd = open(file, O_RDONLY);
	i = 0;
	while (read(fd, &c, 1))
		tetriminos[i++] = c;
	return (tetriminos);
}