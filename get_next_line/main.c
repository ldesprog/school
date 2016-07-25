#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int						get_next_line(int fd, char **line);
/*
int main()
{
	char *line;
	
	while(get_next_line(1, &line))
		printf("%s\n", line);
	return (0);
}
*/
int main(int ac, char **av)
{
	char *str;
	int fd;
	int fd2;
	int i;

	//str = (char*)malloc(sizeof(char));
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	i = 0;
	while (i < 5 && get_next_line(fd, &str))
	{
		printf("1 : %i |%s|\n", i, str);
		str[0] = '\0';
		i++;
	}
	while (i < 10 && get_next_line(fd2, &str))
	{
		printf("2 : %i |%s|\n", i, str);
		str[0] = '\0';
		i++;
	}
	while (i < 15 && get_next_line(fd, &str))
	{
		printf("1 : %i |%s|\n", i, str);
		str[0] = '\0';
		i++;
	}
	close(fd);
	(void)ac;
	return (0);
}