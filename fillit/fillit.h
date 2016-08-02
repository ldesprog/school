
#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_fillit
{
	char	*map;
	char	*tetriminos;
	int		s_map;
	int		n;
}				t_fillit;

char	*ft_read_file(char *file);
int		ft_verif_file(char *file);
void	ft_solve(t_fillit *map);
int		ft_is_tetri(char *file);
int		ft_strlen(char *str);
void	ft_clear(char *map, int c, int pos_map);
int		ft_size_map(char *tetriminos, int *nb_tetriminos);
