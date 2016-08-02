
#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	int fd;
	int i;
	char c;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &c, 1))
	{
		write(1, &c, 1);
		i++;
	}
	printf("%i\n", i);
	return 0;
}