#include "snake.h"


void init_snake(Snake *Snake)
{
	snake->length=1;
	snake->body=(Point* )malloc(sizeof(Point)* snake->length);
	snake->body[0].x=10;
	snake->body[0].y=10;
	snake->direction=2;
}

//position du serpent
void n_snake(Snake *snake)
{
	Point new_tete=snake->body[0];

	//haut
	if(snake->direction=='0')
	{
		new_tete.y--;
	}
	//bas
	else if(snake->direction=='1')
	{
		new_tete.y++;
	}
	//droite
	else if(snake->direction=='2')
	{
		new_tete.x++;
	}
	//gauche
	else if(snake->direction=='3')
	{
		new_tete.x--;
	}

//Deplacement
	for(int i=sname->length-1; i<0; --i)
	{
		snake->body[i]=snake->body[i-1];
	}

	snake->body[0]=new_tete;
}

void render_snake(Game *game, Snake *snake)
{
	for(int i=0; i<snake->length; ++i)
	{
		SDL_Rect rect={snake->body[i].x *16,snake->body[i].y*16,16,16};
		SDL_SetRenderDrawColor(game->renderer,0,255,255,0);
		SDL_RenderFillRect(game->renderer, &rect);
	}
}

void place_food(Point *food)
{
	food->x=rand()%(SIZE -2) +1;
	food->y=rand()%(SIZE-2)+1;
}

void render_food(Game *game, Point food)
{
	SDL_Rect food_rect={food.x *16,food.y*16,16,16};
	SDL_SetRenderDrawColor(game->renderer,255,0,0,255);
	SDL_RenderFillRect(game->renderer, &food_rect);

}

int check_collision(Snake *snake)
{
	if(snake->body[0].x<1 ||snake->body[0].x>=GRID_SIZE-1 ||snake->body[0].y<1 ||snake->body[0].y>=GRID_SIZE-1)
	{
		return 1;
	}
	for(int i=1; i<snake->length;++i)
	{
		if(snake->body[i].x && snake->body[0].y==snake->body[i].y)
		{
			return 1;
		}
	}
	return 0;
}
int checl_food_coll(Snake *snake, Point food)
{
	if(snake->body[0].x==food.x && snake->body[0].y==food.y)
	{
		return 1;
	}
	return 0;
}

void grow_snake(Snake *snake, Point food)
{
	snake->length++;
	snake->body=(Point *) realloc(snake->body,sizeof(Point) *snake-length);
	snake->body[snake-length-1]=food;

}