/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 19:37:14 by ldesprog          #+#    #+#             */
/*   Updated: 2014/11/27 19:37:16 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_binaire(char *str)
{
	char	*new;
	int		i;
	int		nb;

	new = (char *)ft_malloc(sizeof(char) * 10);
	i = 0;
	while (str[i])
	{
		nb = str[i] - '0';
		new[i * 3 + 2] = nb % 2 + '0';
		nb /= 2;
		new[i * 3 + 1] = nb % 2 + '0';
		nb /= 2;
		new[i * 3] = nb % 2 + '0';
		nb /= 2;
		i++;
	}
	new[9] = '\0';
	return (new);
}

int		ft_octal(int nb_o)
{
	int		nb_i;

	nb_i = 1;
	while (nb_o > 0)
	{
		nb_i *= 10;
		nb_i += nb_o % 8;
		nb_o /= 8;
	}
	while (nb_i > 1)
	{
		nb_o *= 10;
		nb_o += nb_i % 10;
		nb_i /= 10;
	}
	return (nb_o);
}

void	ft_droit2(char *perm, char *perm2, int nb, struct stat stat_file)
{
	if (perm2[nb] == '4' && strlen(perm2) - nb == 4)
		perm[3] = 's';
	if (perm2[nb] == '2' && strlen(perm2) - nb == 4)
		perm[6] = 's';
	if (perm2[nb] == '1' && strlen(perm2) - nb == 4)
		perm[9] = 't';
	if (S_ISDIR(stat_file.st_mode))
		perm[0] = 'd';
	else if (S_ISCHR(stat_file.st_mode))
		perm[0] = 'c';
	else if (S_ISLNK(stat_file.st_mode))
		perm[0] = 'l';
	else if (S_ISBLK(stat_file.st_mode))
		perm[0] = 'b';
	else if (S_ISFIFO(stat_file.st_mode))
		perm[0] = 'p';
	else if (S_ISSOCK(stat_file.st_mode))
		perm[0] = 's';
	else if (S_ISREG(stat_file.st_mode))
		perm[0] = '-';
}

char	*ft_droit(struct stat stat_file)
{
	char	*perm;
	char	*perm2;
	int		nb;
	int		i;
	char	*bin;

	perm = (char *)ft_malloc(sizeof(char) * 12);
	perm2 = (char *)ft_malloc(sizeof(char) * 8);
	nb = ft_octal((int)stat_file.st_mode);
	perm2 = ft_itoa(nb);
	nb = strlen(perm2) - 1;
	perm[10] = ' ';
	perm[11] = '\0';
	bin = ft_binaire(&perm2[nb - 2]);
	i = -1;
	while (++i < 3)
	{
		perm[1 + i * 3] = (bin[i * 3] == '1') ? 'r' : '-';
		perm[2 + i * 3] = (bin[i * 3 + 1] == '1') ? 'w' : '-';
		perm[3 + i * 3] = (bin[i * 3 + 2] == '1') ? 'x' : '-';
	}
	nb -= 2;
	ft_droit2(perm, perm2, nb, stat_file);
	return (perm);
}

char	*ft_remalloc_char3(char *line, int nb)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)ft_malloc(sizeof(char) * (nb + 1));
	j = nb - strlen(line);
	i = -1;
	while (line[++i])
		new[i] = line[i];
	j += i;
	while (i < j)
		new[i++] = ' ';
	new[i] = '\0';
	free(line);
	return (new);
}

char	*ft_remalloc_char2(char *line, int nb)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)ft_malloc(sizeof(char) * (nb + 1));
	j = nb - strlen(line);
	i = 0;
	while (i < j)
		new[i++] = ' ';
	j = 0;
	while (line[j])
		new[i++] = line[j++];
	new[i] = '\0';
	free(line);
	return (new);
}

char	***ft_remalloc_3_tab(char ***save_file, int nb)
{
	char	***new;
	int		i;

	new = (char ***)ft_malloc(sizeof(char **) * (nb + 2));
	i = 0;
	while (i < nb)
	{
		new[i] = save_file[i];
		i++;
	}
	new[i] = NULL;
	new[i + 1] = NULL;
	free(save_file);
	return (new);
}

char	***ft_aligner(char ***str)
{
	unsigned int	size_max;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	size_max = 0;
	j = -1;
	while (++j < 9)
	{
		i = -1;
		size_max = 0;
		while (str[++i])
			if (strlen(str[i][j]) > size_max)
				size_max  = strlen(str[i][j]);
		i = -1;
		if (j == 2 || j == 3)
			while (str[++i])
				str[i][j] = ft_remalloc_char3(str[i][j], size_max);
		else
			while (str[++i])
				str[i][j] = ft_remalloc_char2(str[i][j], size_max);
	}
	return (str);
}

char	*ft_verif_time(struct stat stat_file)
{
	char	**year;

	year = (char **)ft_malloc(sizeof(char) * 13);
	year = ft_strsplit(ctime(&stat_file.st_mtime), ' ');
	if (((int)stat_file.st_mtime + 15778463) >= time(NULL)
		&& ((int)stat_file.st_mtime) <= time(NULL))
	{
		year[3][5] = '\0';
		return (year[3]);
	}
	year[4][4] = '\0';
	return (year[4]);
}

int		ft_strlen_l(char ***tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_ls_l_r(char ***out)
{
	int		i;
	int		j;

	i = ft_strlen_l(out) - 1;
	while (i >= 0)
	{
		j = 0;
		while (out[i][j])
		{
			ft_printf("%s ", out[i][j], NULL, NULL);
			j++;
		}
		ft_printf("\n", NULL, NULL, NULL);
		i--;
	}
}

void	ft_ls_l_normal(char ***out)
{
	int		i;
	int		j;

	i = 0;
	while (out[i])
	{
		j = 0;
		while (out[i][j])
		{
			ft_printf("%s ", out[i][j], NULL, NULL);
			j++;
		}
		ft_printf("\n", NULL, NULL, NULL);
		i++;
	}
}

void	ft_ls_space_file(char ***out, dev_t id_perif, int i)
{
	int		major;
	int		minor;
	int		j;
	char	*str;

	major = id_perif / 256;
	minor = id_perif % 256;
	str = ft_itoa(major);
	out[i][5] = ft_itoa(minor);
	j = ft_strlen(str);
	out[i][4] = (char *)ft_malloc(sizeof(char) * (j + 2));
	j = 0;
	while (str[j])
	{
		out[i][4][j] = str[j];
		j++;
	}
	out[i][4][j] = ',';
	out[i][4][j + 1] = '\0';
	free(str);
}

int		ft_ls_l_2(int i, char ***out, struct stat stat_file, char *name)
{
	struct passwd	*uid;
	struct group	*gid;
	char			**file2;

	out[i] = (char **)ft_malloc(sizeof(char *) * 13);
	out[i][0] = ft_droit(stat_file);
	out[i][1] = ft_itoa((long)stat_file.st_nlink);
	uid = getpwuid(stat_file.st_uid);
	out[i][2] = (char *)ft_malloc(sizeof(char) * (strlen(uid->pw_name) + 1));
	gid = getgrgid(stat_file.st_gid);
	out[i][3] = (char *)ft_malloc(sizeof(char) * (strlen(gid->gr_name) + 1));
	out[i][2] = ft_strcpy(out[i][2], uid->pw_name);
	out[i][3] = ft_strcpy(out[i][3], gid->gr_name);
	if (S_ISCHR(stat_file.st_mode) || S_ISBLK(stat_file.st_mode))
		ft_ls_space_file(out, stat_file.st_rdev, i);
	else
	{
		out[i][5] = ft_itoa((int)stat_file.st_size);
		out[i][4] = (char *)ft_malloc(sizeof(char));
		out[i][4][0] = 0;
	}
	file2 = ft_strsplit(ctime(&stat_file.st_mtime), ' ');
	out[i][6] = file2[2];
	out[i][7] = file2[1];
	out[i][8] = ft_verif_time(stat_file);
	out[i][9] = (char *)ft_malloc(sizeof(char) * (strlen(name) + 1));
	ft_strcpy(out[i][9], name);
	out[i][10] = NULL;
	return ((int)stat_file.st_blocks);
}

void	ft_ls_l(DIR *dir, t_lst_dir *finder, t_opt opt)
{
	struct dirent	*file;
	struct stat		stat_file;
	int				nb_blocks;
	char			***out;
	int				i;
	char			*name_full;
	char			*name_link;

	nb_blocks = 0;
	i = -1;
	out = (char***)ft_malloc(sizeof(char**));
	out[0] = NULL;
	name_link = (char *)ft_malloc(sizeof(char) * 1024);
	while ((file = readdir(dir)))
	{
		if ((opt.a == 0 && file->d_name[0] != '.') || opt.a == 1)
		{
			out = ft_remalloc_3_tab(out, ++i);
			name_full = ft_name(finder->name, file->d_name, &stat_file);
			nb_blocks += ft_ls_l_2(i, out, stat_file, file->d_name);
			if (S_ISLNK(stat_file.st_mode))
			{
				(void)readlink(name_full, name_link, 1024);
				out[i][10] = (char *)ft_malloc(sizeof(char) * (strlen(name_link) + 4));
				strcat(strcat(out[i][10], "-> "), (name_link));
				ft_bzero(name_link, 1024);
				out[i][11] = NULL;
			}
		}
	}
	free(name_link);
	ft_ls_l_tri(out);
	if (opt.t == 1)
		ft_ls_l_t(out, finder->name);
	out = ft_aligner(out);
	if (out[0])
		ft_printf("total %i\n", &nb_blocks, NULL, NULL);
	(opt.r == 0) ? ft_ls_l_normal(out) : ft_ls_l_r(out);
}
