#include "fractol.h"

s_ecart	ft_zoom(s_ecart e, s_pos souris)
{
	e.z *= 1.1;
	/*if (souris.x > 200)
		e.decal_x += 0.1 / e.z;
	else
		e.decal_x -= 0.1 / e.z;
	if (souris.y > 200)
		e.decal_y += 0.1 / e.z;
	else
		e.decal_y -= 0.1 / e.z;*/

	e.decal_x += 0.15 / (e.z / (((double)souris.x - 200) / 200));
	e.decal_y += 0.15 / (e.z / (((double)souris.y - 200) / 200));

	return (e);
}

void ft_event(SDL_Surface *ecran, s_ecart e, s_pos souris, s_complexe c)
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
            	e = ft_zoom(e, souris);
            	ft_print_julia(ecran, c, e);
            	break;
        }
    }
}

void	ft_gestion_fractal(SDL_Surface *ecran, s_pos souris)
{
	s_ecart e;
	s_complexe c;

	c.r = -0.85;
	c.i = 0.2;
	//gestion de la fractal demander
	e = ft_julia(ecran, c, e);
	ft_event(ecran, e, souris, c);
}

int		main(void)
{
	SDL_Surface *ecran;
	s_pos souris;

	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(400, 400, 32, SDL_HWSURFACE);
	
	souris.x = 200;
	souris.y = 200;
	ft_gestion_fractal(ecran, souris);
	SDL_FreeSurface(ecran);
	SDL_Quit();
	return (0);
}