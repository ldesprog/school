#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

int main()
{
	int i;

	i = 0;
	while (i < 5)
	{
		printf("%i\n", i);
		i++;
	}
	while (i < 10)
	{
		printf("%i\n", i);
		i++;
	}

	i = -1;
	while (++i < 5)
		printf("%i\n", i);
	while (++i - 1 < 10)
		printf("%i\n", i - 1);
	return 0;
}