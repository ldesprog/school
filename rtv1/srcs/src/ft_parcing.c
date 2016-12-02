#include <rtv1.h>

int		ft_is_int(char *str)
{
	int i;
	int neg;

	i = 0;
	neg = 0;
	if (str[0] == '-')
	{
		neg = 1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 8)
	{
		printf("Map error\n");
		exit(0);
	}
	else if (i == 8)
	{
		if (neg && strcmp(str, "2147483648"))
		{
			printf("Map error\n");
			exit(0);
		}
		else if (strcmp(str, "2147483647"))
		{
			printf("Map error\n");
			exit(0);
		}
	}
	if (neg)
		return (ft_atoi(--str));
	return (ft_atoi(str));
}

char	*get_word(char *line, int nb)
{
	int i;
	int n;
	int j;
	char *word;

	i = 0;
	n = 0;
	word = NULL;
	while (line[i] && (line[i] == ' ' && line[i] == '\t'))
			i++;
	while (line[i] && n < nb)
	{
		n++;
		while (line[i] && line[i] != ' ' && line[i] != '\t')
			i++;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
	}
	j = i;
	while (line[j] && line[j] != ' ' && line[j] != '\t')
		j++;
	
	word = ft_strsub(&line[i], 0, j - i);
	
	return (word);
}

void	ft_fill_vector_from_file(t_vector *v, char *line, int pos)
{
	char *word;

	word = get_word(line, pos);
	v->x = ft_is_int(word);
	free(word);
	word = get_word(line, pos + 1);
	v->y = ft_is_int(word);
	free(word);
	word = get_word(line, pos + 2);
	v->z = ft_is_int(word);
	free(word);
}

void	ft_fill_obj(t_env *e, char *line)
{
	char *type;
	int i;

	type = get_word(line, 0);
	if (strcmp(type, "light") == 0)
		ft_fill_light(e, line);
	else if (strcmp(type, "sphere") == 0)
		ft_fill_sphere(e, line);
	else if (strcmp(type, "plane") == 0)
		ft_fill_plane(e, line);
	else if (strcmp(type, "cylinder") == 0)
		ft_fill_cylinder(e, line);
	else if (strcmp(type, "cone") == 0)
		ft_fill_cone(e, line);
	else
	{
		// printf("else\n");
		i = 0;
		while (line[i] || line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i])
		{
			printf("Map error\n");
			exit(0);
		}
	}
	free(type);
}

void	ft_parcing(t_env *e, char *file)
{
	int fd;
	char *line;
	int nb_cam;
	t_obj *tmp_o;
	t_light *tmp_l;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		printf("Unable to open file\n");
		exit(0);
	}
	nb_cam = 0;
	while (get_next_line(fd, &line))
	{
		// printf("%s\n", line);

		if (strncmp(line, "camera", 6) == 0)
		{
			ft_fill_cam(e, line);
			if (nb_cam > 0)
			{
				printf("Map error\nMultiple camera\n");
				exit(0);
			}
			nb_cam++;
		}
		else if (line[0] == '#')
			;
		else
			ft_fill_obj(e, line);
		free(line);
	}
	free(line);
	tmp_o = e->obj->next;
	tmp_l = e->light->next;
	free(e->obj);
	free(e->light);
	e->obj = tmp_o;
	e->light = tmp_l;
	// faudrai free les 2 con
	// bon faut verifier que c free propre
	close(fd);

}
