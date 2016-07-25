// `sdl-config --cflags --libs`

#include <SDL/SDL.h>
#include <stdio.h>

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
}				s_ecart;

void ft_event(SDL_Surface *ecran, Uint32 pixel, s_complexe c, s_ecart e, s_pos souris);
void ft_setPixel(SDL_Surface *screen, int x, int y, Uint32 color);
s_complexe	ft_convertion(int x, int y, s_ecart e);
int		ft_si_dans_fractale(s_complexe z, s_complexe c);
void	ft_julia(SDL_Surface *ecran, Uint32 pixel, s_complexe c, s_ecart e);
void	ft_zoom(s_ecart *e, s_pos souris);

int main(void)
{
	SDL_Surface *ecran;
	Uint32 pixel;
	s_complexe c;
	s_ecart e;
	s_pos souris;

	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(800, 800, 32, SDL_HWSURFACE);
	pixel = SDL_MapRGBA(ecran->format, 255, 0, 0, 255);
	c.r = -0.85;
	c.i = 0.2;
	e.xNeg = -2;
	e.xPos = 2;
	e.yNeg = -2;
	e.yPos = 2;
	souris.x = 400;
	souris.y = 400;
	ft_julia(ecran, pixel, c, e);
	ft_event(ecran, pixel, c, e, souris);
	SDL_FreeSurface(ecran);
	SDL_Quit();
	return (0);
}

void	ft_julia(SDL_Surface *ecran, Uint32 pixel, s_complexe c, s_ecart e)
{
	int x;
	int y;
	s_complexe z;
	Uint32 noir;

	noir = SDL_MapRGBA(ecran->format, 0, 0, 0, 255);
	SDL_LockSurface(ecran);
	x = 0;
	while (x < 800)
	{
		y = 0;
		while (y < 800)
		{
			z = ft_convertion(x, y, e);
			if (ft_si_dans_fractale(z, c))
				ft_setPixel(ecran, x, y, pixel);
			else
				ft_setPixel(ecran, x, y, noir);
			y++;
		}
		x++;
	}
	SDL_UnlockSurface(ecran);
	SDL_Flip(ecran);
}

int		ft_si_dans_fractale(s_complexe z, s_complexe c)
{
	int n;
	double tmp;

	n = 0;
	while (n < 50)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		n++;
		if (z.r * z.r + z.i * z.i >= 4)
		{
			return (0);
		}
	}
	return (1);
}

s_complexe	ft_convertion(int x, int y, s_ecart e)
{
	s_complexe z;

	z.r = (double)x / 800 * (e.xPos - e.xNeg) + e.xNeg;
	z.i = (double)y / 800 * (e.yPos - e.yNeg) + e.yNeg;
	return (z);
}

void ft_setPixel(SDL_Surface *screen, int x, int y, Uint32 color)
{
    SDL_Rect pixel;
    pixel.w = 1, pixel.h = 1;
    pixel.x = x, pixel.y = y;
    SDL_FillRect(screen, &pixel, color);
}

void	ft_zoom(s_ecart *e, s_pos souris)
{
	double a;
	double b;

	e->xPos = e->xPos * 0.99;
	e->xNeg = e->xNeg * 0.99;
	e->yPos = e->yPos * 0.99;
	e->yNeg = e->yNeg * 0.99;
	a = ((double)souris.x - 400) / 400 * ((e->xPos - e->xNeg) / 2) * 0.01;
	b = ((double)souris.y - 400) / 400 * ((e->yPos - e->yNeg) / 2) * 0.01;
	e->xPos = e->xPos + a;
	e->xNeg = e->xNeg + a;
	e->yPos = e->yPos + b;
	e->yNeg = e->yNeg + b;
}

void ft_event(SDL_Surface *ecran, Uint32 pixel, s_complexe c, s_ecart e, s_pos souris)
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_MOUSEBUTTONUP:
            	souris.x = event.button.x;
            	souris.y = event.button.y;
            	ft_zoom(&e, souris);
            	ft_julia(ecran, pixel, c, e);
            	break;
        }
    }
}
