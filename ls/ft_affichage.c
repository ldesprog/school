/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affichage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:34:19 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/27 19:34:21 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_remalloc_char(char *line, int nb)
{
	char	*new;
	int		i;

	new = (char *)ft_malloc(sizeof(char) * (nb + 1));
	i = 0;
	while (line[i])
	{
		new[i] = line[i];
		i++;
	}
	while (i < nb)
		new[i++] = ' ';
	new[i] = '\0';
	free(line);
	line = NULL;
	return (new);
}

int		ft_strstrlen(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_affichage(char **save_file, unsigned int size_max)
{
	struct winsize	ws;
	int				nb_col;
	int				nb_row;
	int				nb_all_row;
	t_ij			n;

	ioctl(1, TIOCGWINSZ, &ws);
	nb_col = ws.ws_col / size_max;
	nb_all_row = ft_strstrlen(save_file);
	nb_row = nb_all_row / nb_col;
	if (nb_row == 0 || nb_all_row % nb_col != 0)
		nb_row++;
	n.i = 0;
	while (n.i < nb_row)
	{
		n.j = 0;
		while (n.j < nb_col && (n.i + (nb_row * n.j)) < nb_all_row)
			ft_printf("%s", save_file[n.i + (nb_row * n.j++)], NULL, NULL);
		ft_printf("\n", NULL, NULL, NULL);
		n.i++;
	}
}

void	ft_affichage_r(char **save_file, unsigned int size_max)
{
	struct winsize	ws;
	int				nb_col;
	int				nb_row;
	int				nb_all_row;
	t_ij			n;

	ioctl(1, TIOCGWINSZ, &ws);
	nb_col = ws.ws_col / size_max;
	nb_all_row = ft_strstrlen(save_file);
	nb_row = nb_all_row / nb_col;
	if (nb_row == 0 || nb_all_row % nb_col != 0)
		nb_row++;
	n.i = nb_row - 1;
	while (n.i >= 0)
	{
		n.j = nb_all_row - nb_row + n.i;
		while (n.j >= 0)
		{
			ft_printf("%s", save_file[n.j], NULL, NULL);
			n.j -= nb_row;
		}
		ft_printf("\n", NULL, NULL, NULL);
		n.i--;
	}
}

void	ft_ls_normal(DIR *dir, t_opt opt, t_lst_dir *finder)
{
	struct dirent	*file;
	char			**save_file;
	int				size_max;
	int				i;
	int				j;

	save_file = (char **)ft_malloc(sizeof(char *));
	save_file[0] = NULL;
	i = 0;
	size_max = 8;
	while ((file = readdir(dir)))
		if ((opt.a == 0 && file->d_name[0] != '.') || opt.a == 1)
		{
			save_file = ft_remalloc_tab(save_file, i + 1);
			save_file[i] = (char *)ft_malloc(sizeof(char) * 
				(strlen(file->d_name) + 1));
			j = -1;
			while (file->d_name[++j])
				save_file[i][j] = file->d_name[j];
			save_file[i][j] = '\0';
			while (j >= size_max)
				size_max += 1;
			i++;
		}
	ft_ls_normal_2(opt, finder, save_file, size_max);
	i = 0;
	while (save_file[i])
	{
		free(save_file[i]);
		save_file[i] = NULL;
		i++;
	}
	free(save_file);
	save_file = NULL;
}
























