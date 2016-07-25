#include "ft_sh1.h"
#include "../../ldesprog/project/libft/libft.h"
#include "../../ldesprog/project/get_next_line/get_next_line.h"

void	ft_env(char **arg, char **env);

int		ft_len_arg(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

char	**ft_put_arg(char **arg, char *line)
{
	int i;
	int j;
	int cmp;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	cmp = 0;
	while (line[i])
	{
		j = 0;
		if (line[i] != ' ' && line[i] != '\t')
		{
			arg[cmp] = (char *)malloc(sizeof(char) * (ft_len_arg(&line[i]) + 1));
			while (line[i] != ' ' && line[i] != '\t' && line[i])
				arg[cmp][j++] = line[i++];
			arg[cmp][j++] = '\0';
			cmp++;
		}
		i++;
	}
	arg[cmp] = NULL;
	return arg;
}

char	**ft_sep_line(char *line)
{
	int i;
	int cmp;
	char **arg;

	i = 0;
	cmp = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			cmp++;
			while (line[i] != ' ' && line[i] != '\t' && line[i])
				i++;
		}
		i++;
	}
	arg = (char **)malloc(sizeof(char *) * (cmp + 1));
	arg = ft_put_arg(arg, line);
	return (arg);
}

void	ft_sh_build(char **arg, char ***env)
{
	if (!ft_strcmp("cd", *arg))
			ft_cd(arg[1], *env);
	else if (!ft_strcmp("pwd", *arg))
		printf("%s\n", ft_pwd());
	else if (!ft_strcmp("exit", *arg))
		exit(0);
//	else if (!ft_strcmp("env", *arg))
//		printf("je n'ai pas encore code cette fonction\n");
	else if (!ft_strcmp("setenv", *arg))
		*env = ft_setenv(*env, arg[1]);
	else if (!ft_strcmp("unsetenv", *arg))
		*env = ft_unsetenv(*env, arg[1]);
	else
		ft_env(arg, *env);
}

void	ft_shell(t_shell shell)
{
	char **line;

	(void)shell;
	line = (char **)malloc(sizeof(char *));
	*line = NULL;
	while (*line == NULL)
	{
		*line = (char *)malloc(sizeof(char));
		write(1, "$> ", 3);
		**line = 0;
		get_next_line(0, line);
		line = ft_sep_line(*line);
		if (*line)
			ft_sh_build(line, &shell.env);
		free(*line);
		*line = NULL;
	}
}

int		main(int ac, char **av, char **env)
{
	t_shell shell;
	char **new_env;
	int i;

	i = 0;
	while (env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		new_env[i] = env[i];
		i++;
	}
	(void)ac;
	(void)av;
	shell.env = new_env;
	ft_shell(shell);
	return (0);
}