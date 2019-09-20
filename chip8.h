#ifndef CHIP8_H
#define CHIP8_H

#include <stdio.h>
#include <string.h>
#include <time.h>

// variable declarations
extern const unsigned char chip8_fontset[80];

struct Keypad {
  // keys => 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F
};

// 0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
// 0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
// 0x200-0xFFF - Program ROM and work RAM

struct VirtualMachine {
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

    // 64x32-pixel monochrome display (0,0)	(63,0)
    // (0,31)(63,31)
    // 2048 pixels, monochrome (either black or white, 1 or 0)
    unsigned char display[64 * 32];
};

// function declarations
void vm_init(struct VirtualMachine *);
void fetch_opcode();
void decode_opcode(unsigned short);
void execute_opcode(unsigned short, struct VirtualMachine *);

#endif
