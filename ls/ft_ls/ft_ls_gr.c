/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_R.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 22:14:30 by ldesprog          #+#    #+#             */
/*   Updated: 2014/12/02 22:14:32 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_name_gr(char *arbo, char *name)
{
	char *name2;

	name2 = (char *)ft_malloc(sizeof(char), (strlen(name) + strlen(arbo) + 2));
	name2[0] = '\0';
	strcat(name2, arbo);
	if (name2[strlen(name2) - 1] != '/')
		strcat(name2, "/");
	strcat(name2, name);
	return (name2);
}

void	ft_ls_gr_2(t_lst_dir *find, t_lst_dir *finder, char *name)
{
	t_lst_dir *new;

	find = finder;
	while (find->next)
		find = find->next;
	new = (t_lst_dir *)ft_malloc(sizeof(t_lst_dir), 1);
	new->name = name;
	new->next = NULL;
	find->next = new;
}

void	ft_ls_gr(t_lst_dir *finder, DIR *dir, t_opt opt)
{
	char			*name;
	struct dirent	*file;
	DIR				*dir2;
	t_lst_dir		*find;

	find = finder;
	while (find->next)
		find = find->next;
	while ((file = readdir(dir)))
		if ((opt.a == 0 && file->d_name[0] != '.') || opt.a == 1)
			if ((file->d_name[1] != '\0' || file->d_name[0] != '.')
				&& (file->d_name[0] != '.' || file->d_name[1] != '.'
					|| file->d_name[2] != '\0'))
			{
				name = ft_name_gr(find->name, file->d_name);
				dir2 = opendir(name);
				if (dir2 != NULL)
				{
					ft_ls_gr_2(find, finder, name);
					ft_ls_gr(finder, dir2, opt);
					closedir(dir2);
				}
			}
}
