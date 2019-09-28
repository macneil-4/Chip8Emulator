#include "display.h"

bool initDisplay() {

    SCREEN_WIDTH = 640;
    SCREEN_HEIGHT = 320;



    bool success = true;

    // setting up SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("Chip8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // SDL_RENDERER_ACCELERATED => the rendered uses hardware acceleration

            if (renderer == NULL) {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            } else {
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
            }
        }
    }

    return success;
}

bool closeDisplay() {

    SDL_DestroyWindow(window);

    SDL_Quit();

    return true;
}

void drawDisplay() {}

void clearDisplay() {}
