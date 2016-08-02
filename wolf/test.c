#include <math.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <unistd.h>

int main(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf("quit\n");
		return (0);
	}
	SDL_Quit();
	return 0;
}