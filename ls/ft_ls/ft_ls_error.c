/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 16:27:13 by ldesprog          #+#    #+#             */
/*   Updated: 2014/12/16 16:27:15 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_illegal_opt(char c)
{
	printf("ls : illegal option -- %c\n", c);
	printf("usage: ls [-Ralrt] [file ...]\n");
	exit(0);
}

void	ft_verif_option(int i, char **av, t_opt *opt)
{
	int	j;

	j = 0;
	while (av[i][++j] != '\0')
	{
		if (av[i][j] == 'a')
			opt->a = 1;
		else if (av[i][j] == 'r')
			opt->r = 1;
		else if (av[i][j] == 't')
			opt->t = 1;
		else if (av[i][j] == 'l')
			opt->l = 1;
		else if (av[i][j] == 'R')
			opt->gr = 1;
		else
			ft_illegal_opt(av[i][j]);
	}
}

void	ft_verif_argv(int ac, char **av, t_opt *opt)
{
	int i;
	struct stat	stat_av;

	opt->a = 0;
	opt->l = 0;
	opt->r = 0;
	opt->t = 0;
	opt->gr = 0;
	i = 1;
	while (av[i][0] == '-' && av[i][1] && i < ac)
		ft_verif_option(i++, av, opt);
	while (i < argc)
	{
		if (!stat(argv[i], &stat_arg))
			printf("ls: %s: NO such file or directory\n", av[i++]);
		i++;
	}
}

void	ft_error_open(char *name)
{
	printf("ls: %s: %s\n", name, errno);
}
