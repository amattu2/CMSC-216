/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Sept 25th, 2020
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

/*** REMOVE AFTER CONVERTING TABS->SPACES ***/
/*** REMOVE AFTER FORMATTING LONG PARAMETER DESIGN ***/

/* Files */
#include <stdio.h>
#include "machine.h"

/* Prototypes */
void print_opcode(Opcode opcode);
void print_register(unsigned int bits);
void print_memaddr(Opcode opcode, unsigned int bits);
unsigned int read_bit(unsigned int byte, int msb, int lsb);
Opcode determine_opcode(unsigned int opcode);
int opcode_uses_register(unsigned int opcode, int register_index);
int opcode_uses_memory_addr(unsigned int opcode);

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
	Opcode opcode = determine_opcode(read_bit(instruction, 32, 28)); /* opcode (32-28) */
	unsigned int register1 = read_bit(instruction, 27, 23); /* Reg 1 (27-23) */
	unsigned int register2 = read_bit(instruction, 22, 18); /* Reg 2 (22-18) */
	unsigned int register3 = read_bit(instruction, 17, 13); /* Reg 3 (17-13) */
	unsigned int addr_or_const = read_bit(instruction, 12, 0); /* Address/Constant (12-0) */

	/* Print Opcode */
	print_opcode(opcode);
	if (opcode == HALT) {
		return;
	}

	/* Print Register 1 (Unless HALT, no checks needed) */
	printf(" ");
	print_register(register1);

	/* Print Register 2 */
	if (opcode != LI && opcode != LOAD && opcode != STORE) {
		printf(" ");
		print_register(register2);
	}

	/* Print Register 3 */
	if (opcode != INV && opcode != NOT && opcode != MV && opcode != LI && opcode != LOAD && opcode != STORE) {
		printf(" ");
		print_register(register3);
	}

	/* Print Address/Constant */
	if (opcode == CMP || opcode == LI || opcode == LOAD || opcode == STORE) {
		printf(" ");
		print_memaddr(opcode, addr_or_const);
	}
}

unsigned int encode_instruction(unsigned short opcode, unsigned short reg1, unsigned short reg2, unsigned short reg3, unsigned int addr_or_constant, Hardware_word *const hw_word) {
	/* Check Opcode */
	if (opcode < 0 || opcode > 14) {
		return 0;
	}

	/* Check Register 1 */
	if (opcode_uses_register(opcode, 1) == 1 && (reg1 < 0 || reg1 > 19)) {
		return 0;
	}

	/* Check Register 2 */
	if (opcode_uses_register(opcode, 2) == 1 && (reg2 < 0 || reg2 > 19)) {
		return 0;
	}

	/* Check Register 3 */
	if (opcode_uses_register(opcode, 3) == 1 && (reg3 < 0 || reg3 > 19)) {
		return 0;
	}

	/* Check Memory Address */
	if (opcode_uses_memory_addr(opcode) == 1 && (addr_or_constant < 0 || addr_or_constant > 2047)) {
		return 0;
	}

	/*
	Take the 4 provided parameters and store it in Hardware_word

	if parameters are invalid, return 0 before modifying Hardware_word otherwise 1
	- if opcode is invalid (only 0-15 opcodes)
	- if opcode is HALT, just stop
	- if a register operand (reg1, reg2, reg3) are outside of the 0-19 (R0-R19) range
	- if the instruction uses a memory address, and the addr_or_constant is not a valid mem addr (0-2047)
	- if it uses a memory addr and the mem addr is not divisible by 4 (addr % 4 == 0)
	- if it uses a LI instruction, and not between 0-8191 (inclusive), it's invalid
	- if instruction is to modify and reg1 is unmodifier or R0/R1, its invalid

	A li instruction is only 11 bits, a immediate value is 13
	 */

	return 0;
}

unsigned int diassemble(const Hardware_word memory[], unsigned int memory_size, unsigned int num_instrs) {
	/*
	See 3.3
	 */

	return 0;
}

unsigned int compare_instructions(Hardware_word instr1, Hardware_word instr2) {
	/*
	See 3.4
	 */

	return 0;
}

/**
 * Determine and return the bit in specified position
 *
 * @param unsigned int
 * @param int msb (Include from lsb to here)
 * @param int lsb (Move TOWARDS left this amount)
 * @return unsigned bit(s) at position
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-27T10:11:09-040
 */
unsigned int read_bit(unsigned int byte, int msb, int lsb) {
	/* Find Bit Position */
	unsigned int result = (byte >> lsb) & ~(~0 << (msb-lsb+1));

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

Opcode determine_opcode(unsigned int opcode) {
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

	return HALT;
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
	if (register_index == 2 && opcode != LI && opcode != LOAD && opcode != STORE) {
		return 1;
	}
	if (register_index == 3 && opcode != INV && opcode != NOT && opcode != MV && opcode != LI && opcode != LOAD && opcode != STORE) {
		return 1;
	}

	/* Default */
	return 0;
}

/**
 * Check if specified Opcode uses a memory address
 *
 * @param unsigned int opcode
 * @return int uses memory address (0/1)
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-27T12:29:31-040
 */
int opcode_uses_memory_addr(unsigned int opcode) {
	/* Check Provided Opcode against project guideline table */
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
