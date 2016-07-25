/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 15:11:43 by ldesprog          #+#    #+#             */
/*   Updated: 2015/01/27 15:11:44 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_change_map(char ***map, int *len, int high)
{
	int i;
	int j;
	int **new;

	new = (int **)ft_malloc(sizeof(int *) * (high + 1));
	i = 0;
	while (map[i])
	{
		new[i] = (int *)ft_malloc(sizeof(int) * (len[i] + 1));
		j = 0;
		while (map[i][j])
		{
			new[i][j] = ft_atoi(map[i][j]);
			j++;
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	ft_compte_taille(int **len, int *high, char ***map)
{
	*high = 0;
	while (map[*high])
		(*high)++;
	*len = (int *)ft_malloc(sizeof(int) * *high);
	*high = 0;
	while (map[*high])
	{
		(*len)[*high] = 0;
		while (map[*high][(*len)[*high]])
			((*len)[*high])++;
		(*high)++;
	}
}

int		ft_taille(int **map, int *len)
{
	int i;
	int j;
	int h;

	i = -1;
	h = 0;
	while (map[++i])
	{
		j = -1;
		while (++j < len[i])
		{
			if (h == 0 || (map[i][j] < h && map[i][j]))
			{
				if (map[i][j] < 0)
				{
					if (h == 0 || (map[i][j] * -1 < h && map[i][j]))
						h = map[i][j] * -1;
				}
				else
					h = map[i][j];
			}
		}
	}
	return (h);
}

char	***remaloc_map(char ***map)
{
	char	***new;
	int		i;

	i = 0;
	while (map[i])
		i++;
	new = (char ***)ft_malloc(sizeof(char**) * (i + 2));
	if (!new)
		exit(0);
	i = -1;
	while (map[++i])
		new[i] = map[i];
	new[i + 1] = NULL;
	free(map);
	return (new);
}

void	ft_clean(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		str[i++] = 0;
}
