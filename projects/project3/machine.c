/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Oct 2st, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/**
 * The purpose of this project is to
 * - Emulate a CPU environment (Mathlon, 32-bit--4b)
 * - Process commands
 * - Translate machine instructions
*/

/********************************************/
/********************************************/
/*** REMOVE AFTER CONVERTING TABS->SPACES ***/
/*** REMOVE AFTER REWRITING LONG LINE DESIGN ***/
/*** REMOVE AFTER ADDING NEWLINE TO FILE ***/
/********************************************/
/********************************************/

/*
    Still waiting to finish dissessemble
    and compare
 */

/* question for TAs
    - how to write to hw_word
    - whats the deal with CMP instruction and priority
*/

/* Files */
#include <stdio.h>
#include "machine.h"

/* Prototypes */
void print_opcode(Opcode opcode);
void print_register(unsigned int bits);
void print_memaddr(Opcode opcode, unsigned int bits);
unsigned int read_bit(unsigned int byte, int msb, int lsb);
Opcode find_opcode(unsigned int opcode);
int opcode_uses_register(unsigned int opcode, int register_index);
int opcode_uses_memory_addr(unsigned int opcode);
int opcode_modifies_register1(unsigned int opcode);

/**
 * Print a CPU instruction set
 *
 * @param unsigned int instruction
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-27T11:15:39-040
 */
void print_instruction(Hardware_word instruction) {
    /* Variables */
    Opcode opcode = find_opcode(read_bit(instruction, 32, 28));
    unsigned int register1 = read_bit(instruction, 27, 23);
    unsigned int register2 = read_bit(instruction, 22, 18);
    unsigned int register3 = read_bit(instruction, 17, 13);
    unsigned int addr_or_const = read_bit(instruction, 12, 0);

    /* Validate Opcode */
    if (opcode == -1) {
        return;
    }

    /* Print Opcode */
    print_opcode(opcode);
    if (opcode == HALT) {
        return;
    }

    /* Print Register 1 */
    if (opcode_uses_register(opcode, 1) == 1 &&
        (register1 < 0 || register1 > 19)) {
        return;
    }
    printf(" ");
    print_register(register1);

    /* Print Register 2 */
    if (opcode_uses_register(opcode, 2) == 1 &&
        (register2 < 0 || register2 > 19)) {
        return;
    }
    if (opcode_uses_register(opcode, 2)) {
        printf(" ");
        print_register(register2);
    }

    /* Print Register 3 */
    if (opcode_uses_register(opcode, 3) == 1 &&
        (register3 < 0 || register3 > 19)) {
        return;
    }
    if (opcode_uses_register(opcode, 3)) {
        printf(" ");
        print_register(register3);
    }

    /* Print Address/Constant */
    if (opcode == CMP || opcode == LI || opcode == LOAD || opcode == STORE) {
        printf(" ");
        print_memaddr(opcode, addr_or_const);
    }
}

/**
 * Convert the parameters into a hardware instruction
 *
 * @param unsigned short opcode
 * @param unsigned short reg1
 * @param unsigned short reg2
 * @param unsigned short reg3
 * @param unsigned int mem_address/constant
 * @param Hardware_word const hw_word
 * @return int 0/1
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-29T15:31:28-040
 */
unsigned int encode_instruction(unsigned short opcode, unsigned short reg1,
    unsigned short reg2, unsigned short reg3, unsigned int addr_or_constant,
    Hardware_word *const hw_word) {
    /* Check Opcode */
    if (opcode < 0 || opcode > 14) {
        return 0;
    }

    /* Check Registers */
    if (opcode_uses_register(opcode, 1) == 1 && (reg1 < 0 || reg1 > 19)) {
        return 0;
    }
    if (opcode_uses_register(opcode, 2) == 1 && (reg2 < 0 || reg2 > 19)) {
        return 0;
    }
    if (opcode_uses_register(opcode, 3) == 1 && (reg3 < 0 || reg3 > 19)) {
        return 0;
    }

    /* Check Memory Address */
    if (opcode_uses_memory_addr(opcode) == 1 &&
    (addr_or_constant < 0 || addr_or_constant > 2047)) {
        return 0;
    }
    if (opcode_uses_memory_addr(opcode) == 1 &&
    (addr_or_constant % 4 != 0)) {
        return 0;
    }

    /* Check Immediate Value */
    if (opcode == LI && (reg1 < 0 || reg1 > 8191)) {
        return 0;
    }

    /* Check Register 1 */
    if (opcode_modifies_register1(opcode) == 1 &&
        (reg1 == R0 || reg1 == R1)) {
        return 0;
    }

    /* Check Pointer */
    if (!hw_word) {
        return 0;
    }

    /* Assign CMP Priority */
    if (opcode == CMP && reg3 != R0 && reg3 != R1 && reg3 != R2
        && reg3 != R3 && reg3 != R4 && reg3 != R5) {
        /* TODO */
    }

    /* TODO */
    /*
    - how do we write to hw_word
    */

    /* Default */
    return 1;
}

/**
 * Convert memory array into instruction set
 *
 * @param Hardware_word memory[]
 * @param unsigned int memory_size
 * @param unsigned int num_instrs
 * @return int valid/invalid
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-29T14:36:31-040
 */
unsigned int disassemble(const Hardware_word memory[],
    unsigned int memory_size, unsigned int num_instrs) {
    /* Variables */
    int array_index;

    /* Check memory[] */
    if (!memory) {
        return 0;
    }

    /* Check memory_size */
    if (memory_size < 1 || memory_size > 512) {
        return 0;
    }

    /* Check num_instrs */
    if (num_instrs < 1 || num_instrs > memory_size) {
        return 0;
    }

    /* Loop through memory */
    for (array_index = 0; array_index < memory_size; array_index++) {
        /* Checks */
        if (array_index < num_instrs) {
            /* Variables */
            unsigned int opcode, reg1, reg2, reg3;
            opcode = find_opcode(read_bit(memory[array_index], 32, 28));
            reg1 = read_bit(memory[array_index], 27, 23);
            reg2 = read_bit(memory[array_index], 22, 18);
            reg3 = read_bit(memory[array_index], 17, 13);

            /* Check Opcode */
            if (opcode == -1) {
                return 0;
            }

            /* Check Register 1 */
            if (opcode_uses_register(opcode, 1) == 1 &&
                (reg1 < 0 || reg1 > 19)) {
                return 0;
            }

            /* Check Register 2 */
            if (opcode_uses_register(opcode, 2) == 1 &&
                (reg2 < 0 || reg2 > 19)) {
                return 0;
            }

            /* Check Register 3 */
            if (opcode_uses_register(opcode, 3) == 1 &&
                (reg3 < 0 || reg3 > 19)) {
                return 0;
            }

            /* Print Address */
            printf("%03x: ", (array_index * 4));

            /* Print Instruction */
            print_instruction(memory[array_index]);
        } else {
            /* Print Address */
            printf("%03x: ", (array_index * 4));

            /* Print Memory */
            printf("%08x", memory[array_index]);
        }

        /* Print Newline */
        printf("\n");
    }

    /* Default */
    return 1;
}

/**
 * Compare two different Mathlon instructions
 *
 * @param Hardware_word instruction1
 * @param Hardware_word instruction2
 * @return int 0/1
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-29T15:37:40-040
 */
unsigned int compare_instructions(Hardware_word instr1, Hardware_word instr2) {
    /* Variables */
    unsigned int i1_opcode, i1_register1, i1_register2, i1_register3, i1_addr_or_const,
    i2_opcode, i2_register1, i2_register2, i2_register3, i2_addr_or_const;
    i1_opcode = find_opcode(read_bit(instr1, 32, 28));
    i2_opcode = find_opcode(read_bit(instr2, 32, 28));
    i1_register1 = read_bit(instr1, 27, 23);
    i2_register1 = read_bit(instr2, 27, 23);
    i1_register2 = read_bit(instr1, 22, 18);
    i2_register2 = read_bit(instr2, 22, 18);
    i1_register3 = read_bit(instr1, 17, 13);
    i2_register3 = read_bit(instr2, 17, 13);
    i1_addr_or_const = read_bit(instr1, 12, 0);
    i2_addr_or_const = read_bit(instr2, 12, 0);

    /* Compare Hardware_words */
    if (instr1 == instr2) {
        return 1;
    }

    /* Check Opcodes */
    if (i1_opcode == -1 || i2_opcode == -1) {
        return 0;
    }
    if (i1_opcode != i2_opcode) {
        return 0;
    }

    /* Check Register 1 */
    if (opcode_uses_register(i1_opcode, 1) && i1_register1 != i2_register1) {
        return 0;
    }

    /* Check Register 2 */
    if (opcode_uses_register(i1_opcode, 2) && i1_register2 != i2_register2) {
        return 0;
    }

    /* Check Register 3 */
    if (opcode_uses_register(i1_opcode, 3) && i1_register3 != i2_register3) {
        return 0;
    }

    /* Check Memory / Constant */
    if (i1_addr_or_const != i2_addr_or_const) {
        return 0;
    }

    /* Default */
    return 1;
}

/**
 * Find and return the bit in a specified position
 *
 * @param unsigned int
 * @param int right_index (Include from lsb to here)
 * @param int left_index (Move TOWARDS left this amount)
 * @return unsigned bit(s) at position
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-27T10:11:09-040
 */
unsigned int read_bit(unsigned int byte, int right_index, int left_index) {
    /* Variables */
    unsigned int result;

    /* Find Position */
    result = (byte >> left_index) & ~(~0 << (right_index - left_index + 1));

    /* Return Result */
    return result;
}

/**
 * Print opcode descripton
 *
 * @param Opcode opcode
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-26T13:50:29-040
 */
void print_opcode(Opcode opcode) {
    switch (opcode) {
        case HALT:
            printf("halt");
            break;
        case ADD:
            printf("add");
            break;
        case SUB:
            printf("sub");
            break;
        case MUL:
            printf("mul");
            break;
        case DIV:
            printf("div");
            break;
        case REM:
            printf("rem");
            break;
        case INV:
            printf("inv");
            break;
        case AND:
            printf("and");
            break;
        case OR:
            printf("or");
            break;
        case NOT:
            printf("not");
            break;
        case CMP:
            printf("cmp");
            break;
        case MV:
            printf("mv");
            break;
        case LI:
            printf("li");
            break;
        case LOAD:
            printf("load");
            break;
        case STORE:
            printf("store");
            break;
        default:
            break;
    }
}

/**
 * Determine register at position and print
 *
 * @param unsigned int register bits
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-27T10:47:35-040
 */
void print_register(unsigned int bits) {
    switch (bits) {
        case R0:
            printf("R0");
            break;
        case R1:
            printf("R1");
            break;
        case R2:
            printf("R2");
            break;
        case R3:
            printf("R3");
            break;
        case R4:
            printf("R4");
            break;
        case R5:
            printf("R5");
            break;
        case R6:
            printf("R6");
            break;
        case R7:
            printf("R7");
            break;
        case R8:
            printf("R8");
            break;
        case R9:
            printf("R9");
            break;
        case R10:
            printf("R10");
            break;
        case R11:
            printf("R11");
            break;
        case R12:
            printf("R12");
            break;
        case R13:
            printf("R13");
            break;
        case R14:
            printf("R14");
            break;
        case R15:
            printf("R15");
            break;
        case R16:
            printf("R16");
            break;
        case R17:
            printf("R17");
            break;
        case R18:
            printf("R18");
            break;
        case R19:
            printf("R19");
            break;
        default:
            break;
    }
}

/**
 * Convert Opcode to const
 * (This function is somewhat redundant)
 * (The default value of -1 is important for invalid opcodes)
 *
 * @param unsigned int opcode
 * @return Opcode constant
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-27T12:39:33-040
 */
Opcode find_opcode(unsigned int opcode) {
    /* Find Opcode */
    switch (opcode) {
        case 0:
            return HALT;
        case 1:
            return ADD;
        case 2:
            return SUB;
        case 3:
            return MUL;
        case 4:
            return DIV;
        case 5:
            return REM;
        case 6:
            return INV;
        case 7:
            return AND;
        case 8:
            return OR;
        case 9:
            return NOT;
        case 10:
            return CMP;
        case 11:
            return MV;
        case 12:
            return LI;
        case 13:
            return LOAD;
        case 14:
            return STORE;
    }

    /* Default */
    return -1;
}

/**
 * Print a memory address or constant value
 *
 * @param Opcode opcode
 * @param unsigned int bits
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-27T12:07:15-040
 */
void print_memaddr(Opcode opcode, unsigned int bits) {
    /* Find Opcode Association */
    switch (opcode) {
        case CMP:
        case LOAD:
        case STORE:
            printf("%04d", bits);
            break;
        case LI:
            printf("%d", bits);
            break;
        default:
            break;
    }
}

/**
 * Check if specified register (index) is used by a instruction
 *
 * @param unsigned int opcode
 * @param int register number (1-3)
 * @return int uses specified register (0/1)
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-27T12:37:43-040
 */
int opcode_uses_register(unsigned int opcode, int register_index) {
    /* Check Opcodes/Registers against project table */
    if (opcode == HALT) {
        return 0;
    }
    if (register_index == 1) {
        return 1;
    }
    if (register_index == 2 && opcode != LI && opcode != LOAD &&
        opcode != STORE) {
        return 1;
    }
    if (register_index == 3 && opcode != INV && opcode != NOT &&
        opcode != MV && opcode != LI && opcode != LOAD && opcode != STORE) {
        return 1;
    }

    /* Default */
    return 0;
}

/**
 * Check if specified Opcode uses a memory address
 *
 * @param unsigned int opcode
 * @return int (true/false)
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-27T12:29:31-040
 */
int opcode_uses_memory_addr(unsigned int opcode) {
    /* Check provided Opcode against project guideline table */
    switch (opcode) {
        case CMP:
        case LOAD:
        case STORE:
            return 1;
        case LI:
            return 0;
        default:
            return 0;
    }
}

/**
 * Check if specified opcode modifies register 1
 *
 * @param unsigned int opcode
 * @return int (true/false)
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-10-01T17:32:04-040
 */
int opcode_modifies_register1(unsigned int opcode) {
    /* Check use of register 1 in opcode table */
    switch (opcode) {
        case HALT:
        case CMP:
        case STORE:
            return 0;
        default:
            return 1;
    }
}
