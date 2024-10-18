#include "snake.h"

int main()
{
	Game game;
	Snake snake;
	Point food;
	SDL_Event event,

	srand(time(NULL));
	init_game(&game);
	init_snake(&snake);
	place_food(&food);

	while(1)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_Quit())
			{
				return 0;
			}
			else if(event.type==SDL_Keydown)
			{
				if (event.key.keysym.sym == SDLK_UP) 
				{
						
				}
				else if (event.key.keysym.sym == SDLK_DOWN) 
				{
					
				}
				else if (event.key.keysym.sym == SDLK_LEFT) 
				{
					
				}
				else if (event.key.keysym.sym == SDLK_RIGTH) 
				{
					
				}
			}
		}
	}

	return 0;
}