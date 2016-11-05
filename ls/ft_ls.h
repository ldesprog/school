/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 15:32:33 by ldesprog          #+#    #+#             */
/*   Updated: 2014/12/07 15:32:35 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <errno.h>
# include <dirent.h>
# include <sys/types.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "libft/libft.h"

typedef struct			s_opt
{
	int					a;
	int					t;
	int					gr;
	int					r;
	int					l;
}						t_opt;

typedef struct			s_lst_dir
{
	char				*name;
	struct s_lst_dir	*next;
	struct s_lst_dir	*prev;
}						t_lst_dir;

typedef struct			s_ij
{
	int					i;
	int					j;
}						t_ij;

void					ft_printf(char *str, void *par1, void *par2, void *par3);
int						ft_strcmp(const char *s1, const char *s2);
void					ft_ls_tri(char **out);
void					ft_ls_normal_2(t_opt opt, t_lst_dir *finder, char **save_file, int size_max);
void					ft_ls_normal(DIR *dir, t_opt opt, t_lst_dir *finder);
void					ft_ls_l(DIR *dir, t_lst_dir *finder, t_opt opt);
void					ft_ls_gr(t_lst_dir *finder, DIR *dir, t_opt opt);
void					ft_ls_t(char **tab, char *arbo);
int						ft_strlen_l(char ***tab);
char					*ft_itoa(int n);
char					**ft_strsplit(const char *s, char c);
char					*ft_strcpy(char *dst, const char *src);
void					ft_ls_l_t(char ***tab, char *arbo);
char					*ft_name(char *arbo, char *nom, struct stat *file);
char					**ft_remalloc_tab(char **save_file, int nb);
char					*ft_remalloc_char(char *line, int nb);
int						ft_ls_2(t_lst_dir *finder, t_opt opt, char *directory);
void					ft_affichage(char **save_file, unsigned int size_max);
void					ft_affichage_r(char **save_file, unsigned int size_max);
int						ft_ls(char *directory, t_opt opt);
void					ft_verif_argv(int ac, char **av, t_opt *opt);
int						ft_ls_l_2(int i, char ***out, struct stat stat_file, char *name);
void					ft_ls_l_normal(char ***out);
void					ft_ls_l_tri(char ***out);
void					ft_tri_gr(t_lst_dir *finder, t_opt opt);
int						ft_str_ls_cmp(char *s1, char *s2);

#endif
