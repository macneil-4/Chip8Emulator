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
