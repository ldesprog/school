/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 13:01:28 by ldesprog          #+#    #+#             */
/*   Updated: 2014/12/17 13:01:31 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	main_file2(char *argv, struct stat stat_arg, t_opt opt)
{
	char	***out;

	out = (char ***)malloc(sizeof(char **) * 2);
	out[1] = NULL;
	if (opt.l)
	{
		(void)ft_ls_l_2(0, out, stat_arg, argv);
		ft_ls_l_normal(out);
	}
	else
		ft_printf("%s\n", argv, NULL, NULL);
}

void	main_file1(char **argv, t_opt opt, int nb)
{
	struct stat	stat_arg;
	int			i;

	i = 0;
	while (i < nb)
	{
		if (nb > 1)
			printf("%s:\n", argv[i]);
		if (lstat(argv[i], &stat_arg) == 0)
		{
			if (S_ISDIR(stat_arg.st_mode))
				ft_ls(argv[i], opt);
			else
				main_file2(argv[i], stat_arg, opt);
		}
		i++;
		if (i < nb)
			ft_printf("\n", NULL, NULL, NULL);
	}
}

void	ft_tri_file(char **arg, t_opt opt)
{
	int		i;
	int		j;
	char	*str;

	ft_ls_tri(arg);
	if (opt.t == 1)
		ft_ls_t(arg, "./");
	if (opt.r == 1)
	{
		i = 0;
		while (arg[++i])
		{
			str = arg[i];
			j = i - 1;
			while (j >= 0)
			{
				arg[j + 1] = arg[j];
				j--;
			}
			arg[j + 1] = str;
		}
	}
}

int		main(int argc, char **argv)
{
	t_opt		opt;
	int			i;
	char		**arg;
	int			j;

	ft_verif_argv(argc, argv, &opt);
	i = 1;
	while (i < argc && argv[i][0] == '-')
		i++;
	if (i == argc)
	{
		ft_ls(".", opt);
		return (0);
	}
	arg = (char **)ft_malloc(sizeof(char *), argc - i + 1);
	arg[argc - i] = NULL;
	j = i;
	while (i < argc)
	{
		arg[i - j] = argv[i];
		i++;
	}
	ft_tri_file(arg, opt);
	main_file1(arg, opt, i - j);
	return (0);
}

void	*ft_malloc(int type, size_t len)
{
	void	*new;

	new = malloc(type * len);
	if (!new)
		exit(0);
	return (new);
}

char	*ft_name(char *arbo, char *nom, struct stat *file)
{
	char	*name;

	name = (char *)ft_malloc(sizeof(char), (strlen(arbo) + strlen(nom) + 2));
	name[0] = '\0';
	strcat(name, arbo);
	if (name[strlen(name) - 1] != '/')
		strcat(name, "/");
	strcat(name, nom);
	(void)lstat(name, file);
	return (name);
}

void	ft_printf(char *str, void *par1, void *par2, void *par3)
{
	int		i;
	void	*actual;
	int		x;

	i = -1;
	x = 1;
	while (str[++i])
	{
		if (x == 1)
			actual = par1;
		else if (x == 2)
			actual = par2;
		else if (x == 3)
			actual = par3;
		if (str[i] == '%' && x++)
		{
			i++;
			if (str[i] == 's')
				ft_putstr((char *)actual);
			else if (str[i] == 'i')
				ft_putnbr(*(int *)actual);
			else
				printf("bug printf\n");
		}
		else
			ft_putchar(str[i]);
	}
}
