/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:48:55 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/10 13:48:56 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cmptab(const char *s, char c)
{
	int		k;
	int		i;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		k++;
	}
	if (s[i - 1] == c)
		k--;
	return (k);
}

static int		ft_cmplen(const char *s, char c, int index)
{
	int		cmp;

	cmp = 0;
	index--;
	while ((s[++index] && s[index] != c))
		cmp++;
	return (cmp);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_cmptab(s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!(tab[k] = (char *)malloc(sizeof(char) * (ft_cmplen(s, c, i) + 1))))
			return (NULL);
		while (s[i] && s[i] != c)
			tab[k][j++] = s[i++];
		if (j != 0)
			tab[k++][j] = '\0';
	}
	tab[k] = NULL;
	return (tab);
}
