#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "snake.h"

int main() 
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    // Initialiser SDL et créer la fenêtre
    initSDL();
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Initialiser le serpent et la nourriture
    Snake snake = { .length = INITIAL_LENGTH, .direction = 0 };
    for (int i = 0; i < snake.length; i++) {
        snake.snake[i].x = INITIAL_LENGTH * SNAKE_SIZE - i * SNAKE_SIZE; // Initialisation du serpent
        snake.snake[i].y = 0; // Initialisation du serpent
    }

    Food food;
    generateFood(&food); // Générer la nourriture à une position aléatoire

    // Définir les murs
    Wall walls[NUM_WALLS] = {
        {{600, 400, 300, 20}}, // Mur horizontal
        {{500, 200, 20, 300}}, // Mur vertical
        {{800, 200, 20, 400}}, // Mur vertical (corrigé : position différente)
        {{600, 600, 300, 20}}  // Mur horizontal (corrigé : position différente)
    };

    int run = 1; // Indicateur pour la boucle de jeu
    SDL_Event event;

    while (run) 
    {
        // Gestion des événements
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) 
            {
                run = 0; 
            } 
            else if (event.type == SDL_KEYDOWN) 
            {
                // Changer la direction du serpent
                switch (event.key.keysym.sym) 
                {
                    case SDLK_UP: if (snake.direction != 1) snake.direction = 3; break; // Haut
                    case SDLK_DOWN: if (snake.direction != 3) snake.direction = 1; break; // Bas
                    case SDLK_LEFT: if (snake.direction != 0) snake.direction = 2; break; // Gauche
                    case SDLK_RIGHT: if (snake.direction != 2) snake.direction = 0; break; // Droite
                }
            }
        }

        // Mettre à jour la position du serpent
        updateSnake(&snake);

        // Vérifier les collisions
        if (checkCollision(&snake, walls, NUM_WALLS) || checkSelfCollision(&snake)) 
        {
            printf("Vous avez perdu!\n");
            run = 0; // Terminer le jeu en cas de collision
        }

        // Vérifier si le serpent mange la nourriture
        if (snake.snake[0].x == food.position.x && snake.snake[0].y == food.position.y) 
        {
            growSnake(&snake); // Faire grandir le serpent
            generateFood(&food); // Générer une nouvelle nourriture
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Dessiner les murs
        drawMur(walls, NUM_WALLS, renderer);

        // Dessiner le serpent et la nourriture
        drawSnake(&snake, renderer);
        drawFood(&food, renderer);

        // Afficher le rendu
        SDL_RenderPresent(renderer);
        SDL_Delay(100); // Attendre 100 ms
    }

    // Nettoyer et quitter
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    clean();
    return 0;
}
