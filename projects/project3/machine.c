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
/*** REMOVE AFTER FORMATTING encode_instruction PARAMETER DESIGN ***/

/* Files */
#include "machine.h"

/* Prototypes */
void print_opcode(unsigned int opcode);

void print_instruction(Hardware_word instruction) {
	/*
	Use bit operators to move throughout the parameter data

	Eg. print_instruction(0x41912000) > div R3 R4 R9
	*/
}

unsigned int encode_instruction(unsigned short opcode, unsigned short reg1, unsigned short reg2, unsigned short reg3, unsigned int addr_or_constant, Hardware_word *const hw_word) {
	/*
	Take the 4 provided parameters and store it in Hardware_word

	if parameters are invalid, return 0 before modifying Hardware_word otherwise 1
	- if opcode is invalid (only 15 opcodes)
	- if opcode is HALT, just stop
	- if a register operand (reg1, reg2, reg3) are outside of the 0-19 (R0-R19) range
	- if the instruction uses a memory address, and the addr_or_constant is not a valid mem addr (0-2047)
	- if it uses a memory addr and the mem addr is not divisible by 4 (addr % 4 == 0)
	- if it uses a LI instruction, and not between 0-8191 (inclusive), it's invalid
	- if instruction is to modify and reg1 is unmodifier or R0/R1, its invalid
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

void print_opcode(unsigned int opcode) {
	
}
