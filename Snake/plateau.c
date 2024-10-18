#include "snake.h"

void init_game(Game *game, int width, int height, const char *title)
{

	SDL_Init(SDL_INIT_VIDEO);

	game->window= SDL_CreateWindow("Snake",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width, height,0);
	game->renderer= SDL_CreateRenderer(game->window,-1,SDL_RENDERER_ACCELERATED);
	game->width=width;
	game->height=height;
	game->food_count=0;
}

void quit_game(Game *game)
{
	SDL_DestroyRenderer(game->renderer);
	SDL_DestroyWindow(game->window);
	SDL_Quit();
}