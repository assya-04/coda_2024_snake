#include <stdio.h>
#include <stdlib.h>
#include "snake.h"

void initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL error: %s\n", SDL_GetError());
        exit(1);
    }
}

void clean() {
    SDL_Quit();
}

void drawSnake(Snake *serpent, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for (int i = 0; i < serpent->length; i++) {
        SDL_Rect rect = {serpent->snake[i].x, serpent->snake[i].y, SNAKE_SIZE, SNAKE_SIZE};
        SDL_RenderFillRect(renderer, &rect);
    }
}

void drawFood(Food *food, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect = {food->position.x, food->position.y, SNAKE_SIZE, SNAKE_SIZE};
    SDL_RenderFillRect(renderer, &rect);
}

void drawMur(Wall *mur, int numWalls, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 127, 125, 120, 255);
    for (int i = 0; i < numWalls; i++) {
        SDL_RenderFillRect(renderer, &mur[i].rect);
    }
}

void generateFood(Food *food) {
    food->position.x = (rand() % (WINDOW_WIDTH / SNAKE_SIZE)) * SNAKE_SIZE;
    food->position.y = (rand() % (WINDOW_HEIGHT / SNAKE_SIZE)) * SNAKE_SIZE;
}

void updateSnake(Snake *serpent) {
    moveSnake(serpent);
}

void moveSnake(Snake *serpent) {
    for (int i = serpent->length - 1; i > 0; i--) {
        serpent->snake[i] = serpent->snake[i - 1];
    }

    switch (serpent->direction) {
        case 0: serpent->snake[0].x += SNAKE_SIZE; break; // Droite
        case 1: serpent->snake[0].y += SNAKE_SIZE; break; // Bas
        case 2: serpent->snake[0].x -= SNAKE_SIZE; break; // Gauche
        case 3: serpent->snake[0].y -= SNAKE_SIZE; break; // Haut
    }
}

int checkCollision(Snake *serpent, Wall *walls, int numWalls) {
    // Vérifier les collisions avec les murs
    for (int i = 0; i < numWalls; i++) {
        if (serpent->snake[0].x < walls[i].rect.x + walls[i].rect.w &&
            serpent->snake[0].x + SNAKE_SIZE > walls[i].rect.x &&
            serpent->snake[0].y < walls[i].rect.y + walls[i].rect.h &&
            serpent->snake[0].y + SNAKE_SIZE > walls[i].rect.y) {
            return 1; // Collision avec le mur
        }
    }
    return 0;
}

int checkSelfCollision(Snake *serpent) {
    // Vérifier les collisions avec soi-même
    for (int i = 1; i < serpent->length; i++) {
        if (serpent->snake[0].x == serpent->snake[i].x && serpent->snake[0].y == serpent->snake[i].y) {
            return 1; // Collision avec soi-même
        }
    }
    return 0;
}
void growSnake(Snake *serpent)
{
     Food *food;
     if (serpent->length < MAX_LENGTH) {
        serpent->length++; // Augmente la longueur

        // Réallocation de la mémoire pour le serpent
        serpent->snake[serpent->length - 1] = serpent->snake[serpent->length - 2]; // Ajouter une nouvelle partie du corps
    }
}
