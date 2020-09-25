/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

#define NUM_BYTES 2048
#define BYTES_PER_WORD 4
#define NUM_WORDS (NUM_BYTES / BYTES_PER_WORD)
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8
#define R9 9
#define R10 10
#define R11 11
#define R12 12
#define R13 13
#define R14 14
#define R15 15
#define R16 16
#define R17 17
#define R18 18
#define R19 19

typedef unsigned int Hardware_word;

typedef enum { HALT, ADD, SUB, MUL, DIV, REM, INV, AND, OR, NOT, CMP, MV, LI,
               LOAD, STORE } Opcode;

void print_instruction(Hardware_word instruction);
unsigned int encode_instruction(unsigned short opcode, unsigned short reg1,
                                unsigned short reg2, unsigned short reg3,
                                unsigned int addr_or_constant,
                                Hardware_word *const hw_word);
unsigned int disassemble(const Hardware_word memory[],
                         unsigned int memory_size, unsigned int num_instrs);
unsigned int compare_instructions(Hardware_word instr1, Hardware_word instr2);
