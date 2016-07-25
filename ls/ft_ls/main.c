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

#include "get_next_line.h"



int		main(int argc, char **argv)
{
	t_opt		opt;
	int			i;
	struct stat	stat_arg;

	ft_verif_argv(argc, argv, &opt);
	i = 1;
	while (argv[i][0] == '-' && i < argc)
		i++;
	while (i < argc)
	{
		if (stat(argv[i], &stat_arg))
		{
			if (S_ISDIR(stat_arg.st_mode))
				ft_ls(argv[i], opt);
			else if (S_ISREG(stat_arg.st_mode))
				ft_ls_file(argv[i], opt);
		}
		i++;
	}
	return 0;
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
	char *name;

	name = (char *)ft_malloc(sizeof(char), (strlen(arbo) + strlen(nom) + 2));
	name[0] = '\0';
	strcat(name, arbo);
	if (name[strlen(name) - 1] != '/')
		strcat(name, "/");
	strcat(name, nom);
	(void)lstat(name, file);
	return (name);
}
