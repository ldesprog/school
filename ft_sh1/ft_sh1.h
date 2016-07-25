#ifndef FT_SH1_H
# define FT_SH1_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>

typedef struct	s_shell
{
	char **env;
}				t_shell;

char	*ft_pwd(void);
void	ft_cd(char *dir, char **env);
char	**ft_setenv(char **env, char *arg);
char	**ft_unsetenv(char **env, char *arg);

#endif