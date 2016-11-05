/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_tri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 18:22:59 by ldesprog          #+#    #+#             */
/*   Updated: 2014/12/03 18:23:02 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// possible retrait des tiret et des point */

int		ft_verif_case(char *s1, char *s2)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		a = 0;
		b = 0;
		if ((unsigned char)s1[i] >= 'A' && (unsigned char)s1[i] <= 'Z')
			a = 1;
		if ((unsigned char)s2[i] >= 'A' && (unsigned char)s2[i] <= 'Z')
			b = 1;
		i++;
		if (a != b)
		{
			if (a == 1)
				return (1);
			else
				return (-1);
		}
	}
	return (0);
}

int		ft_str_ls_cmp(char *s1, char *s2)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		a = (unsigned char)s1[i];
		b = (unsigned char)s2[i];
	/*	if (a >= 'A' && a <= 'Z')
			a += 32;
		if (b >= 'A' && b <= 'Z')
			b += 32;*/
		if (a != b)
			return (a - b);
		i++;
	}
	a = (unsigned char)s1[i];
	b = (unsigned char)s2[i];
	if (a || b)
		return (a - b);
	return (ft_verif_case(s1, s2));
}

void	ft_ls_l_tri(char ***out)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	if (out[i] == NULL)
		return ;
	while (out[++i])
	{
		str = out[i];
		j = i - 1;
		while (j >= 0 && ft_str_ls_cmp(out[j][9], str[9]) > 0)
		{
			out[j + 1] = out[j];
			j--;
		}
		out[j + 1] = str;
	}
}

void	ft_ls_tri(char **out)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!(out[i]))
		return ;
	while (out[++i])
	{
		str = out[i];
		j = i - 1;
		while (j >= 0 && ft_str_ls_cmp(out[j], str) > 0)
		{
			out[j + 1] = out[j];
			j--;
		}
		out[j + 1] = str;
	}
}
