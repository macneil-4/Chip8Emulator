#include <stdio.h>
// include SDL graphics and input
// "chip8.h" cpu core implementation

struct Keypad {
  // keys => 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F
};

// 64x32-pixel monochrome display (0,0)	(63,0)
// (0,31)(63,31)
unsigned char display[64 * 32]; // 2048 pixels, monochrome (either black or white, 1 or 0)

// 0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
// 0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
// 0x200-0xFFF - Program ROM and work RAM

struct VirtualMachine {
    // unsigned char - 8 bits, [0,255]
    // unsigned short/int - 16 bits, [0, 65535]

    // member variables
    unsigned short idx_R; // index register
    unsigned short stack[16]; // the stack - up to 48 bytes
    unsigned short pc_r; // program counter

    unsigned char v[16]; // general purpose 8-bit registers - vf (v[15]) should be avoided as it also doubles as a flag for some instructions
    unsigned char delay_t; // delay timer
    unsigned char sound_t; // sound timer
    unsigned char sp_r; // stack pointer
    unsigned char memory[4096];
};

unsigned short opcode;

int main()
{
    // setup graphics Setup the graphics (window size, display mode, etc) and input system (bind callbacks)

    // setup input

    // initialize VM - Clear the memory, registers and screen

    // load game from file - Copy the program into the memory

    // emulation loop
        // emulate one cycle

        // if draw flag set, update the screen Because the system does not draw every cycle, we should set a draw flag when we need to update our screen. Only two opcodes should set this flag:
        // 0x00E0 – Clears the screen
        // 0xDXYN – Draws a sprite on the screen


        // store key press state (press and release) - If we press or release a key, we should store this state in the part that emulates the keypad

    return 0;
}
