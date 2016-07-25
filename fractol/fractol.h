// `sdl-config --cflags --libs`

#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct t_complexe
{
	double r;
	double i;
}				s_complexe;

typedef struct t_pos
{
	int x;
	int y;
}				s_pos;

typedef struct t_ecart
{
	double xNeg;
	double xPos;
	double yNeg;
	double yPos;
	double z;
	double decal_x;
	double decal_y;
	int old_x;
	int old_y;
}				s_ecart;

s_ecart	ft_julia(SDL_Surface *ecran, s_complexe c, s_ecart e);
void	ft_print_julia(SDL_Surface *ecran, s_complexe c, s_ecart e);