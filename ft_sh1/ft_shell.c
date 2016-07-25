#include "ft_sh1.h"
#include "../../ldesprog/project/libft/libft.h"
#include "../../ldesprog/project/get_next_line/get_next_line.h"

char *ft_join_add(char *path, char *prog, char add);

char	*ft_pwd(void)
{
	int i;
	char *dir;

	i = 0;
	dir = (char *)malloc(sizeof(char) * (i + 1));
	while (!getcwd(dir, i))
	{
		i += 1;
		free(dir);
		dir = (char *)malloc(sizeof(char) * (i + 1));
	}
	return (dir);
}

char	*ft_find_user(char **env)
{
	char *str;
	int i;
	int j;

	i = 0;
	str = "USER=";
	while (env[i])
	{
		j = 0;
		while (str[j] == env[i][j])
			j++;
		if (!str[j])
			return (&(env[i][j]));
		i++;
	}
	return NULL;
}

void	ft_cd(char *dir, char **env)
{
	char *loc;
	char **str;
	int i;
	int j;

	loc = ft_pwd();
	i = ft_strlen(loc) - 1;
	if (!dir)
	{
		loc = ft_join_add("/home", ft_find_user(env), '/');
		chdir(loc);
	}
	else if (*dir == '/')
	{
		if (chdir(dir) == -1)
			printf("%s: %s\n", dir, "dossier inconnu");
	}
	else
	{
		str = ft_strsplit(dir, '/');
		if (!ft_strcmp(".", *str))
		{
			str++;
			free(*(str - 1));
		}
		while (*str)
		{
			if (!ft_strcmp(*str, ".."))
			{
				while (i > 0 && loc[i] != '/')
					loc[i--] = '\0';
				loc[i] = '\0';
				j++;
			}
			else
			{
				loc = ft_join_add(loc, *str, '/');
				j++;
			}
			if (j)
			{
				j = 0;
				str++;
				free(*(str - 1));
			}
		}
		if (chdir(loc) == -1)
			printf("%s: %s\n", dir, "dossier inconnu");
	}
	loc = ft_pwd();
}
