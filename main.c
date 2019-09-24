#include "chip8.h"
// "chip8.h" cpu core implementation
#include <SDL2/SDL.h>
// include SDL graphics and input

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    // setup graphics Setup the graphics (window size, display mode, etc) and input system (bind callbacks)

    // setting up SDL
    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("Chip8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            screenSurface = SDL_GetWindowSurface(window);

            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

            SDL_UpdateWindowSurface(window);

            SDL_Delay(2000);
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    // setup input

    // initialize VM - Clear the memory, registers and screen
        // Initialize registers and memory once
    struct VirtualMachine vm;
    vm_init(&vm);



    display_register_contents(&vm);

    // load game from file - Copy the program into the memory
    if (load_game("roms/Pong (1 player).ch8", &vm) == false) {
        fprintf(stderr, "An error occurred  loading game file into memory, exiting...\n");
        exit(3);
    } // TODO make generic load function for program startup instead of hardcoded

    // emulation loop
    printf("Now starting emulation loop...\n");
    printf("Skipping emulation loop"); // temporary
    return 0;
    while (1) {
        emulate_cycle(&vm);

        // draw_screen (if required)

        // if draw flag set, update the screen Because the system does not draw every cycle, we should set a draw flag when we need to update our screen. Only two opcodes should set this flag:
        // 0x00E0 – Clears the screen
        // 0xDXYN – Draws a sprite on the screen


        // handle_keypress (if required)

        // store key press state (press and release) - If we press or release a key, we should store this state in the part that emulates the keypad-
    }

    return 0;
}
