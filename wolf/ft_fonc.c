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

int		ft_split_2(char *str, int *i, int *a, t_env *e)
{
	int b;

	*a = 0;
	b = 0;
	if (str[*i] < '0' || str[*i] > '9')
		ft_error_map(e, 3);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*a += str[*i] - '0';
		if (str[*i] >= '1' || b > 0)
			b++;
		(*i)++;
	}
	return (b);
}

int		*ft_split(char *str, int j, int *n, t_env *e)
{
	int i;
	int *map;
	int a;
	int b;

	map = (int *)malloc(sizeof(int) * j);
	i = 0;
	*n = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		b = ft_split_2(str, &i, &a, e);
		if (b > 1)
			map[*n] = 1;
		else if (a > 5)
			map[*n] = 1;
		else
			map[*n] = a;
		while (str[i] == ' ')
			i++;
		*n += 1;
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
		map[n] = ft_split(tab[n], *j, &y, e);
		n++;
		if (y != *j)
		{
			ft_error_map(e, 3);
		}
	}
	if (!ft_verif_map(map, *j, i, e))
	{
		ft_error_map(e, 3);
	}
	return (map);
}
