#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//recupere le repertoire courant : getcwd
//par exemple pour "pwd"
/*
int main(void)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 50);
	if (getcwd(str, 50) == NULL)
		printf("%s\n", "trop petit");
	else
		printf("%s %i\n", str, (int)strlen(str));
	return (0);
}
*/

//change le repertoire de travail courant : chdir

int main(void)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 50);
	getcwd(str, 50);
	printf("%s\n", str);
	str[17] = '\0';
	printf("%i, %s\n", chdir(str), str);
	getcwd(str, 50);
	printf("%s\n", str);
	return (0);
}

/*
int main(void)
{
	char *newargv[] = {"coin.c", NULL };
    char *newenviron[] = {"coin.c", NULL };
	execve("/usr/bin/vim", newargv, newenviron);
	perror("execve");
	return (0);
}*/