#include <stdbool.h>
#include <SDL2/SDL.h> // include SDL graphics and input

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern SDL_Window* window;
extern SDL_Surface* screenSurface;

bool initDisplay();
bool closeDisplay();
