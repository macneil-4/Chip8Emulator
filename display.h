#include <stdbool.h>
#include <SDL2/SDL.h> // include SDL graphics and input

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

SDL_Window* window;
SDL_Surface* screenSurface;

bool initDisplay();
bool closeDisplay();
