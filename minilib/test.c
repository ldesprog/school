
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		get_next_line(int const fd, char **line);

int main(void)
{
	char *line;
	int fd;

	fd = open("../fdf/test_maps/100-6.fdf", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		free(line);
		line = NULL;
	}
	sleep(200);
	return (0);
}
