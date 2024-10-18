#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define GRID_SIZE 25

typedef struct s_point Point ;

struct s_point
{
	int x;
	int y;
};

typedef struct s_snake Snake;
struct s_snake
{
	Point *body;
	int length;
	int direction;

};

typedef struct s_game Game;
struct s_game
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	int width;
	int height;
	int food_count;

};

void init_game(Game *game, int width, int height, const char *title);
void quit_game(Game *game);
void init_snake(Snake *snake);
void n_snake(Snake *snake);
void render_snake(Game *game, Snake *snake);
void place_food(Point *food);
void render_food(Game *game, Point food);
int check_collision(Snake *snake);
int checl_food_coll(Snake *snake, Point food);
void grow_snake(Snake *snake, Point food);

#endif
