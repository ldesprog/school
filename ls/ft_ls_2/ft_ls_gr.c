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
	char	*name2;

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
	t_lst_dir	*new;

	find = finder;
	while (find->next)
		find = find->next;
	new = (t_lst_dir *)ft_malloc(sizeof(t_lst_dir), 1);
	new->name = name;
	new->next = NULL;
	new->prev = find;
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
		if ((file->d_name[1] != '\0' || file->d_name[0] != '.') &&
			(file->d_name[0] != '.' || file->d_name[1] != '.' || file->d_name[2]
				!= '\0') && (file->d_name[0] != '.' || opt.a == 1))
		{
			name = ft_name_gr(find->name, file->d_name);
			dir2 = opendir(name);
			if (dir2 != NULL || errno != ENOTDIR)
			{
				ft_ls_gr_2(find, finder, name);
				if (dir2 != NULL)
				{
					ft_ls_gr(finder, dir2, opt);
					closedir(dir2);
				}
			}
		}
}

int		ft_echange(t_lst_dir *file)
{
	int		i;
	char	*str;

	i = 0;
	while (file->name[i] == file->prev->name[i])
		i++;
	if (file->name[i] == '/' || file->prev->name[i] == '/')
		return (0);
	str = file->name;
	file->name = file->prev->name;
	file->prev->name = str;
	return (1);
}

int 	ft_verif_prev(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i])
		i++;
	if (s1[i] == '/' && s2[i] == 0)
		return 1;
	return 0;
}

int		ft_ls_gr_cmp_2(struct stat s_file, struct stat s_prev, t_lst_dir *file)
{
	if ((int)s_file.st_mtime > (int)s_prev.st_mtime)
	{
		if (ft_echange(file) == 0)
			return 1;
	}
	else
		return 1;
	return 0;
}

int		ft_ls_gr_cmp(char *s1, char *s2, int i)
{
	while (s1[i] && s1[i] != '/')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (i);
}

int		ft_tri_gr_t_2(char *s1, char *s2, t_lst_dir *file)
{
	t_ij			index;
	struct stat		stat_file;
	struct stat		stat_prev;
	char			*sa;
	char			*sb;

	index.i = ft_strlen(s1);
	index.j = ft_strlen(s2);
	sa = (char *)ft_malloc(sizeof(char), index.i);
	sb = (char *)ft_malloc(sizeof(char), index.j);
	index.i = 0;
	while (s1[index.i] == s2[index.i])
	{
		sa[index.i] = s1[index.i];
		sb[index.i] = s1[index.i];
		index.i++;
	}
	index.j = index.i;
	index.i = ft_ls_gr_cmp(s1, sa, index.i);
	index.j = ft_ls_gr_cmp(s2, sb, index.j);
	stat(sa, &stat_file);
	stat(sb, &stat_prev);
	return (ft_ls_gr_cmp_2(stat_file, stat_prev, file));
}

void	ft_tri_gr_t(t_lst_dir *finder)
{
	t_lst_dir		*file;
	t_lst_dir		*find;

	find = finder->next;
	while (find)
	{
		file = find;
		while (file->prev)
		{
			if (ft_tri_gr_t_2(file->name, file->prev->name, file))
				break;
			file = file->prev;
		}
		find = find->next;
	}
}

void	ft_tri_gr_normal(t_lst_dir *finder)
{
	t_lst_dir	*file;

	finder = finder->next;
	while (finder)
	{
		file = finder;
		while (file->prev)
		{
			if (ft_str_ls_cmp(file->name, file->prev->name) < 0)
			{
				if (ft_echange(file) == 0)
					break;
			}
			else
				break;
			file = file->prev;
		}
		finder = finder->next;
	}
}

void	ft_tri_gr_r(t_lst_dir *finder)
{
	t_lst_dir	*file;

	finder = finder->next;
	while (finder)
	{
		file = finder;
		while (file->prev)
		{
			if (ft_verif_prev(file->name, file->prev->name) == 0)
				ft_echange(file);
			else
				break;
			file = file->prev;
		}
		finder = finder->next;
	}
}

void	ft_tri_gr(t_lst_dir *finder, t_opt opt)
{
	ft_tri_gr_normal(finder);
	if (opt.t == 1)
		ft_tri_gr_t(finder);
	else
		ft_tri_gr_normal(finder);
	if (opt.r == 1)
		ft_tri_gr_r(finder);
}
