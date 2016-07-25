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
}						t_lst_dir;

typedef struct			s_ij
{
	int					i;
	int					j;
}						t_ij;

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
char					**ft_remalloc(char **save_file, int nb);
void					ft_ls_2(t_opt opt, t_lst_dir *finder,\
						char **save_file, int size_max);
char					*ft_remalloc_char(char *line, int nb);
void					ft_affichage(char **save_file, unsigned int size_max);
void					ft_affichage_r(char **save_file, unsigned int size_max);
void					*ft_malloc(int type, size_t len);

#endif
