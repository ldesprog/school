#include "fractol.h"

s_complexe	ft_convertion(int x, int y, s_ecart e)
{
	s_complexe u;

	u.r = ((double)x / 400 * 3 - 1.5) / e.z + e.decal_x;
	u.i = ((double)y / 400 * 3 - 1.5) / e.z + e.decal_y;
	return (u);
}

void ft_setPixel(SDL_Surface *screen, int x, int y, Uint32 color)
{
    SDL_Rect pixel;
    pixel.w = 1, pixel.h = 1;
    pixel.x = x, pixel.y = y;
    SDL_FillRect(screen, &pixel, color);
}

int		ft_si_dans_fractale(s_complexe z, s_complexe c)
{
	int n;
	double tmp;

	n = 0;
	while (n < 100)
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
	return (n);
}

void	ft_print_julia(SDL_Surface *ecran, s_complexe c, s_ecart e)
{
	int x;
	int y;
	s_complexe u;
	Uint32 noir;
	Uint32 pixel;

	noir = SDL_MapRGBA(ecran->format, 0, 0, 0, 255);
	pixel = SDL_MapRGBA(ecran->format, 255, 0, 0, 255);
	SDL_LockSurface(ecran);
	x = 0;
	while (x < 400)
	{
		y = 0;
		while (y < 400)
		{
			u.r = ((double)x / 400 * 3 - 1.5) / e.z + e.decal_x;
			u.i = ((double)y / 400 * 3 - 1.5) / e.z + e.decal_y;
			pixel = SDL_MapRGBA(ecran->format, 255, 0, 0, 255);
			if (ft_si_dans_fractale(u, c))
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

s_ecart	ft_julia(SDL_Surface *ecran, s_complexe c, s_ecart e)
{
	e.z = 1.0;
	e.decal_x = 0;
	e.decal_y = 0;
	
	ft_print_julia(ecran, c, e);
	return (e);
}