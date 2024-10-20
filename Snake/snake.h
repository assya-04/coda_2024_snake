#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define SNAKE_SIZE 20
#define INITIAL_LENGTH 5
#define MAX_LENGTH 100
#define NUM_WALLS 4

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point snake[MAX_LENGTH];
    int length;
    int direction; // 0: droite, 1: bas, 2: gauche, 3: haut
} Snake;

typedef struct {
    Point position;
} Food;

typedef struct {
    SDL_Rect rect;
} Wall;

// Function prototypes
void initSDL();
void clean();
void drawSnake(Snake *serpent, SDL_Renderer *renderer);
void drawFood(Food *food, SDL_Renderer *renderer);
void drawMur(Wall *mur, int numWalls, SDL_Renderer *renderer);
void updateSnake(Snake *serpent);
int checkCollision(Snake *serpent, Wall *walls, int numWalls);
int checkSelfCollision(Snake *serpent);
void generateFood(Food *food);
void moveSnake(Snake *serpent);
void growSnake(Snake *serpent);

#endif // SNAKE_H
