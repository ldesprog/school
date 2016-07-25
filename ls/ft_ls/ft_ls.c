/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 15:26:48 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/26 15:26:50 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_2(t_lst_dir *finder, t_opt opt, char *directory)
{
	DIR *dir;

	finder->next = NULL;
	finder->name = directory;
	if (opt->gr == 1)
	{
		dir = opendir(finder->name);
		ft_ls_gr(finder, dir, opt);
		closedir(dir);
	}
	return (1);
}

int		ft_ls(char *directory, t_opt opt)
{
	DIR			*dir;
	t_lst_dir	*finder;
	int			i;

	finder = (t_lst_dir *)ft_malloc(sizeof(t_lst_dir), 1);
	ft_ls_2(finder, opt, directory)
	i = 0;
	while (finder)
	{
		if (opt.gr == 1 && i++ != 0)
			printf("%s:\n", finder->name);
		dir = opendir(finder->name);
		if (opt.l)
			ft_ls_l(dir, finder, opt);
		else
			ft_ls_normal(dir, opt, finder);
		closedir(dir);
		finder = finder->next;
		if (finder)
			printf("\n");
	}
	return (0);
}
