#include "defs.h"

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

extern SDL_Window* window;
extern SDL_Surface* screenSurface;
extern SDL_Renderer* renderer;

bool initDisplay();
bool closeDisplay();

void drawDisplay();
void clearDisplay(); // opcode 00E0
