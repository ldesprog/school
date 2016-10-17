/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:06:25 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/17 15:06:28 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

float	ft_abs(float n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	**ft_remalloc_tab(char **tab, int n)
{
	int		i;
	char	**new;

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
	return (n);
}

int		*ft_split(char *str, int j, int *n)
{
	int i;
	int *map;
	int x;

	map = (int *)malloc(sizeof(int) * j);
	i = 0;
	*n = 0;
	x = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		x = 0;
		if (str[i] == 48 && (str[i + 1] == ' ' || str[i + 1] == '\n'))
			map[*n] = 0;
		while (str[i] >= '1' && str[i] <= '9')
		{
			i++;
			x++;
		}
		if (x > 0)
			i--;
		if (x == 1 && str[i] >= '1' && str[i] <= '9')
			map[*n] = str[i] - '0';
		else if (str[i] != 48)
			map[*n] = 1;
		(*n)++;
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] == ' ')
			i++;
	}
	return (map);
}

int		**ft_split_to_int(char **tab, int i, int *j, t_env *e)
{
	int **map;
	int n;
	int y;

	map = (int **)malloc(sizeof(int *) * i);
	*j = ft_len_str(tab[0]);
	n = 0;
	while (n < i)
	{
		y = 0;
		map[n] = ft_split(tab[n], *j, &y);
		n++;
		if (y != *j)
		{
			write(1, "error : map error\n", 18);
			printf("%i, %i\n", y, *j);
			exit(0);
		}
	}
	if (!ft_verif_map(map, *j, i, e))
	{
		write(1, "error : map error\n", 18);
		exit(0);
	}
	return (map);
}
