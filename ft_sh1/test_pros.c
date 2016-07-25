#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_sh1.h"
#include "../../ldesprog/project/libft/libft.h"
#include "../../ldesprog/project/get_next_line/get_next_line.h"

char	**ft_split_path(char *path);
char	**ft_strsplit(const char *s, char c);

char	**ft_find_path(char **env)
{
	char *str;
	int i;
	int j;

	i = 0;
	str = "PATH=";
	while (env[i])
	{
		j = 0;
		while (str[j] == env[i][j])
			j++;
		if (!str[j])
			return (ft_split_path(env[i] + 5));
		i++;
	}
	return NULL;
}

char **ft_split_path(char *path)
{
	char **res;

	res = ft_strsplit(path, ':');
	return (res);
}

char *ft_join_add(char *path, char *prog, char add)
{
	int len;
	char *res;
	int i;
	int j;

	len = 1;
	len += ft_strlen(path);
	len += ft_strlen(prog);
	res = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	while (path[i])
		res[j++] = path[i++];
	res[j++] = add;
	i = 0;
	while (prog[i])
		res[j++] = prog[i++];
	return (res);
}

void	ft_env(char **arg, char **env)
{
	pid_t child_pid;
	int child_statut;
	char **path;
	int i;
	int exec;
	char *name;
	char *fonc;

	path = ft_find_path(env);
	child_pid = fork();
	if (!child_pid)
	{
		i = 0;
		exec = -1;
		fonc = *arg;
		while (exec == -1 && path[i])
		{
			*arg = fonc;
			name = ft_join_add(path[i], fonc, '/');
			*arg = name;
			exec = execve(name, arg, env);
			i++;
		}
		if (exec == -1)
			printf("command not found: %s\n", fonc);
		*arg = fonc;
		exit(0);
	}
	else
		wait(&child_statut);
}

char	**ft_remalloc_env(char **env, int n)
{
	char **new;
	int i;

	new = (char **)malloc(sizeof(char *) * n + 1);
	i = 0;
	while (env[i])
	{
		new[i] = env[i];
		i++;
	}
	while (i <= n)
		new[i++] = NULL;
	free(env);
	return new;
}

int		ft_len_arg_env(char *str, int *i, int *j)
{
	*i = 0;
	*j = 0;
	if (str == NULL)
	{
		printf("argument non valable\nuse: setenv NAME=value\n");
		return -1;
	}
	while(str[*i] && str[*i] != '=')
		(*i)++;
	while (str[*i + 1 + *j])
		(*j)++;
	return 0;
}

char	**ft_setenv(char **env, char *arg)
{
	int i;
	int j;
	int n;

	if (ft_len_arg_env(arg, &i, &j) == -1)
		return env;
	if (i == 0 || j == 0)
	{
		printf("argument non valable\nuse: setenv NAME=value\n");
		return env;
	}
	n = 0;
	while (env[n])
	{
		if (ft_strncmp(arg, env[n], i + 1) == 0)
			break;
		n++;
	}
	if (!env[n])
		env = ft_remalloc_env(env, n + 1);
	free(env[n]);
	env[n] = (char *)malloc(sizeof(char) * ft_strlen(arg) + 1);
	j = 0;
	while (arg[j])
	{
		env[n][j] = arg[j];
		j++;
	}
	env[n][j] = 0;
	return env;
}

char	**ft_unsetenv(char **env, char *arg)
{
	int i;
	int len;
	char *arg2;

	arg2 = ft_strjoin(arg, "=");
	if (!arg2)
		return (env);
	len = ft_strlen(arg2);
	i = 0;
	while (env[i])
	{
		if (strncmp(arg2, env[i], len) == 0)
		{
			free(env[i]);
			while (env[i + 1])
			{
				env[i] = env[i + 1];
				i++;
			}
			env[i] = NULL;
		}
		i++;
	}
	free(arg2);
	return env;
}
