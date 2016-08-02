/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 21:52:58 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/02 21:53:06 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_clear(char *map, int c, int pos_map)
{
	while (map[pos_map])
	{
		if (map[pos_map] == c)
			map[pos_map] = '.';
		pos_map++;
	}
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
			if (file[i + j] == '#')
				n++;
			j++;
		}
		if (n != 4)
			return (0);
		i += 21;
	}
	return (1);
}

int		ft_verif_file(char *f)
{
	int i;
	int j;
	int x;

	i = 0;
	j = 0;
	x = 0;
	while (f[i + j * 5 + x * 21])
	{
		if (f[i + j * 5 + x * 21] == '#' || f[i + j * 5 + x * 21] == '.')
			i++;
		else if (f[i + j * 5 + x * 21] == '\n' && i == 4 && ++j)
			i = 0;
		else if (f[i + j * 5 + x * 21] == '\n' && i == 0 && j == 4 \
			&& (f[i + 1 + j * 5 + x * 21] == '#' \
				|| f[i + 1 + j * 5 + x * 21] == '.') && ++x)
			j = 0;
		else
			return (0);
		if (x >= 26)
			return (0);
	}
	if (f[i - 1 + j * 5 + x * 21] != '\n' || f[i - 2 + j * 5 + x * 21] == '\n')
		return (0);
	return (x * ft_verif_file_2(f));
}
