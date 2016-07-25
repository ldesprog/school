/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 18:23:09 by ldesprog          #+#    #+#             */
/*   Updated: 2014/12/10 12:26:41 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_strlen_t(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_ls_t(char **tab, char *arbo)
{
	struct stat	file;
	struct stat	file2;
	int			i;
	int			j;
	char		*tab2;

	j = 0;
	tab2 = (char *)ft_malloc(sizeof(char), 1);
	while (tab[++j])
	{
		ft_name(arbo, tab[j], &file);
		i = j;
		tab2 = tab[j];
		while (--i >= 0)
		{
			ft_name(arbo, tab[i], &file2);
			if ((int)file2.st_mtime >= (int)file.st_mtime)
				break ;
			else
				tab[i + 1] = tab[i];
		}
		tab[i + 1] = tab2;
	}
}

void	ft_ls_l_t(char ***tab, char *arbo)
{
	struct stat	file;
	struct stat	file2;
	int			i;
	int			j;
	char		**tab2;

	j = 0;
	tab2 = (char **)ft_malloc(sizeof(char *), 1);
	while (tab[++j])
	{
		ft_name(arbo, tab[j][8], &file);
		i = j;
		tab2 = tab[j];
		while (--i >= 0)
		{
			ft_name(arbo, tab[i][8], &file2);
			if ((int)file2.st_mtime >= (int)file.st_mtime)
				break ;
			else
				tab[i + 1] = tab[i];
		}
		tab[i + 1] = tab2;
	}
}
