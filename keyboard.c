#include "keyboard.h"

void handleEvent(SDL_Event* eventHandler, bool* exitKeyPressed) {
    while (SDL_PollEvent(eventHandler) != 0) {
        if (eventHandler->type == SDL_QUIT) { // window exit button
            *exitKeyPressed = true;
        }
    }
}
