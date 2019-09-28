#include "chip8.h"
// "chip8.h" cpu core implementation
#include "display.h"
#include "keyboard.h"

int main(int argc, char* args[])
{
    // setup graphics Setup the graphics (window size, display mode, etc) and input system (bind callbacks)
    if (!initDisplay()) {
        printf("Error occurred initializing display...\n");
        exit(3);
    }

    // setup input
    SDL_Event eventHandler;
    bool exitKeyPressed = false;

    // initialize VM - Clear the memory, registers and screen
    struct VirtualMachine vm;
    vmInit(&vm);

    // load game from file - Copy the program into the memory
    if (loadGame("roms/Pong (1 player).ch8", &vm) == false) {
        fprintf(stderr, "An error occurred  loading game file into memory, exiting...\n");
        exit(3);
    } // TODO make generic load function for program startup based on command line arguments instead of hardcoded

    // emulation loop
    printf("Now starting emulation loop...\n");

    while (!exitKeyPressed) {
        emulateCycle(&vm);

        // draw_screen (if required)
        // if draw flag set, update the screen Because the system does not draw every cycle, we should set a draw flag when we need to update our screen. Only two opcodes should set this flag:
        // 0x00E0 – Clears the screen
        // 0xDXYN – Draws a sprite on the screen
        drawDisplay();

        // handle_keypress (if required)
        // store key press state (press and release) - If we press or release a key, we should store this state in the part that emulates the keypad-
        handleEvent(&eventHandler, &exitKeyPressed);
    }

    closeDisplay();

    return 0;
}
