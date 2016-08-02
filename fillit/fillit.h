
#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_fillit
{
	char	*map;
}				t_fillit;

char	*ft_read_file(char *file);
int		ft_verif_file(char *file);
void	ft_solve(char *terminos);
int		ft_is_tetri(char *file);