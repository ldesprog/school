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

char	**ft_remalloc_tab(char **save_file, int nb)
{
	char	**new;
	int		i;

	new = (char **)ft_malloc(sizeof(char *) * (nb + 1));
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

void	ft_ls_normal_2(t_opt opt, t_lst_dir *finder, char **sve_file, int s_max)
{
	int		i;

	ft_ls_tri(sve_file);
	if (opt.t == 1)
		ft_ls_t(sve_file, finder->name);
	i = 0;
	while (sve_file[i])
	{
		sve_file[i] = ft_remalloc_char(sve_file[i], s_max);
		i++;
	}
	if (sve_file[0])
	{
		if (opt.r == 1)
			ft_affichage_r(sve_file, s_max);
		else
			ft_affichage(sve_file, s_max);
	}
}
