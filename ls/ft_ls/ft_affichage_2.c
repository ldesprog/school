/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 18:03:05 by ldesprog          #+#    #+#             */
/*   Updated: 2014/12/07 18:03:07 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_remalloc(char **save_file, int nb)
{
	char	**new;
	int		i;

	new = (char **)ft_malloc(sizeof(char *), (nb + 1));
	i = 0;
	while (i < nb)
	{
		new[i] = save_file[i];
		i++;
	}
	new[i] = NULL;
	free(save_file);
	return (new);
}

void	ft_ls_2(t_opt opt, t_lst_dir *finder, char **save_file, int size_max)
{
	int i;

	if (opt.t == 1)
		ft_ls_t(save_file, finder->name);
	i = 0;
	while (save_file[i])
	{
		save_file[i] = ft_remalloc_char(save_file[i], size_max);
		i++;
	}
	if (opt.r == 1)
		ft_affichage_r(save_file, size_max);
	else
		ft_affichage(save_file, size_max);
}
