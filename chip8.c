#include "chip8.h"

/*
    // unsigned char - 8 bits, [0,255]
    // unsigned short/int - 16 bits, [0, 65535]

    // member variables
    unsigned short idx; // index register
    unsigned short stack[16]; // the stack - up to 48 bytes
    unsigned short pc; // program counter
    unsigned short opcode; // current opcode

    unsigned char v[16]; // general purpose 8-bit registers - vf (v[15]) should be avoided as it also doubles as a flag for some instructions
    unsigned char delay_t; // delay timer
    unsigned char sound_t; // sound timer
    unsigned char sp; // stack pointer
    unsigned char memory[4096];
 *
 */

const unsigned char chip8_fontset[80] =
{
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

void vm_init(struct VirtualMachine* vm) {
    printf("Entering vm_init()...\n");

    vm->idx = 0;
    vm->sp = 0;
    vm->opcode = 0;
    vm->pc = 0x200; // CHIP-8 expects application to be loaded at 0x200, so initialize to memory location 0x200

    // Clear display
    memset(vm->display, 0 , sizeof vm->display);

    // Clear stack
    memset(vm->stack, 0, sizeof vm->stack);

    // Clear registers V0-VF
    memset(vm->v, 0, sizeof vm->v);

    // Clear memory
    memset(vm->memory, 0, sizeof vm->memory);

    // Load fontset
    for(int i = 0; i < 80; ++i)
        vm->memory[i] = chip8_fontset[i];

    // Reset timers
    vm->delay_t = 60;
    vm->sound_t = 60;
}

void display_register_contents(struct VirtualMachine * vm) {
    /*
    unsigned short idx; // index register
    unsigned short stack[16]; // the stack - up to 48 bytes
    unsigned short pc; // program counter
    unsigned short opcode; // current opcode

    unsigned char v[16]; // general purpose 8-bit registers - vf (v[15]) should be avoided as it also doubles as a flag for some instructions
    unsigned char delay_t; // delay timer
    unsigned char sound_t; // sound timer
    unsigned char sp; // stack pointer
    unsigned char memory[4096];
    */

    printf("Entering display_register_contents()\n");

    printf("register contents: ");
    printf("idx=%x, ", vm->idx);
    printf("pc=%x, ", vm->pc);
    printf("sp=%x, ", vm->sp);
    printf("delay_t=%x, ", vm->delay_t);
    printf("sound_t=%x, ", vm->sound_t);
    printf("\n");
}


bool load_game(const char* filename, struct VirtualMachine* vm) {

    printf("Entering load_game()...\n");

    FILE* game_file = fopen(filename, "rb");
    int size;

    if(game_file != NULL) {

        // load game_file into vm->memory
        fseek(game_file, 0, SEEK_END);
        size = ftell(game_file);
        rewind(game_file);

        unsigned char buffer[size+1];

        size_t result = fread(&buffer, 1, size, game_file);

        if ((int)result != size) {
            fprintf(stderr, "Error returned from fread()");
            exit(3);
        }

        for(int i = 0; i < size; i++) {
            vm->memory[i+512] = buffer[i];
        }

        printf("Game file loaded into memory.\n");

        fclose(game_file);
        return true;
    }

    return false;
}

void emulate_cycle(struct VirtualMachine* vm) {
    // emulate one cycle
        // Fetch Opcode (each opcode is 2 bytes long)
        // Assume the following for opcode 0xA2F0
        // memory[pc]     == 0xA2
        // memory[pc + 1] == 0xF0
        // opcode = memory[pc] << 8 | memory[pc + 1];
        // shift A2 8 bits which becomes A200, then OR with F0 to become A2F0
    unsigned short opcode = vm->memory[vm->pc] << 8 | vm->memory[vm->pc + 1];
    printf("opcode fetched = %x\n", opcode);

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
}
