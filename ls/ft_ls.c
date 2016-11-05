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
	DIR		*dir;

	finder->next = NULL;
	finder->name = directory;
	if (opt.gr == 1)
	{
		dir = opendir(finder->name);
		if (dir == NULL)
			ft_printf("%s\n", "FUCK", NULL, NULL);
		finder->prev = NULL;
		ft_ls_gr(finder, dir, opt);
		ft_tri_gr(finder, opt);
		closedir(dir);
	}
	return (1);
}

int		ft_ls_3(int i, t_opt opt, t_lst_dir *finder, char *name)
{
	DIR		*dir;

	if (i++ != 0)
		ft_printf("\n", NULL, NULL, NULL);
	if (opt.gr == 1 && i != 1)
		ft_printf("%s:\n", finder->name, NULL, NULL);
	dir = opendir(finder->name);
	if (dir)
	{
		if (opt.l)
			ft_ls_l(dir, finder, opt);
		else
			ft_ls_normal(dir, opt, finder);
		closedir(dir);
	}
	else
		ft_printf("ls: %s: %s\n", name, strerror(errno), NULL);
	return (i);
}

char	*ft_sep_name(char *rep)
{
	int		i;
	int		j;
	char	*name;

	i = 0;
	while (rep[i])
		i++;
	j = 0;
	while (rep[i] != '/' && i > 0)
	{
		i--;
		j++;
	}
	name = (char *)ft_malloc(sizeof(char) * j);
	i++;
	j = 0;
	while (rep[i])
		name[j++] = rep[i++];
	return (name);
}

int		ft_ls(char *directory, t_opt opt)
{
	DIR			*dir;
	t_lst_dir	*finder;
	int			i;
	char		*name;

	finder = (t_lst_dir *)ft_malloc(sizeof(t_lst_dir));
	find = finder;
	ft_ls_2(finder, opt, directory);
	sleep(10);
	i = 0;
	while (finder)
	{
		name = ft_sep_name(finder->name);
		if (opt.a == 0 && name[0] == '.' && name[1] != '\0'
			&& (name[1] != '.' || name[2] != '\0'))
		{
			if ((dir = opendir(finder->name)) == NULL)
				ft_printf("ls: %s: %s\n", ft_sep_name(finder->name), strerror(errno), NULL);
		}
		else if ((opt.a == 0 && name[0] != '.') || opt.a == 1)
			i = ft_ls_3(i, opt, finder, name);
		finder = finder->next;
	}
	sleep(10);
	return (0);
}
