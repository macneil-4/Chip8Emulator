#include "chip8.h"
// include SDL graphics and input
#include "chip8.h"
// "chip8.h" cpu core implementation

int main()
{
    // setup graphics Setup the graphics (window size, display mode, etc) and input system (bind callbacks)

    // setup input
    struct VirtualMachine vm;
    init_vm(vm);

    printf("test");

    // initialize VM - Clear the memory, registers and screen
        // Initialize registers and memory once

    // load game from file - Copy the program into the memory

    // emulation loop
    //while (1) {

        // emulate one cycle
            // Fetch Opcode (each opcode is 2 bytes long)
            // Assume the following for opcode 0xA2F0
            // memory[pc]     == 0xA2
            // memory[pc + 1] == 0xF0
            // opcode = memory[pc] << 8 | memory[pc + 1];
            // shift A2 8 bits which becomes A200, then OR with F0 to become A2F0

            // Decode Opcode
                // decode 0xA2F0 // Assembly: mvi 2F0h
                // ANNN: Sets I to the address NNN (only 12 bits so we need to AND operand with 0x0FFF
                /*
                 * 1010001011110000 & // 0xA2F0 (opcode)
                    0000111111111111 = // 0x0FFF
                    ------------------
                    0000001011110000   // 0x02F0 (0x2F0)

                    Resulting code:

                    I = opcode & 0x0FFF;
                    pc += 2;
                 */

            // Execute Opcode

      // Update timers

        // if draw flag set, update the screen Because the system does not draw every cycle, we should set a draw flag when we need to update our screen. Only two opcodes should set this flag:
        // 0x00E0 – Clears the screen
        // 0xDXYN – Draws a sprite on the screen


        // store key press state (press and release) - If we press or release a key, we should store this state in the part that emulates the keypad-
    //}
    return 0;
}
