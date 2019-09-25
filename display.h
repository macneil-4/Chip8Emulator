#include <stdbool.h>
#include <SDL2/SDL.h> // include SDL graphics and input

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

SDL_Window* window;
SDL_Surface* screenSurface;
SDL_Renderer* renderer;

bool initDisplay();
bool closeDisplay();

void clearDisplay(); // opcode 00E0
