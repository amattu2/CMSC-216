#include <stdio.h>
#include "machine.h"

/**
 * A testrunner for print_instruction()
 * (Eg. 0x1644c000)
 *
 * @return int status
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-29T15:40:17-040
 */
int main(void) {
	/* Iterate through inputs */
	while (feof(stdin) != 1) {
		/* Variables */
		unsigned int opcode, r1, r2, r3, addr;
		unsigned int hw;

		/* Read Input */
		printf("Enter instructions (op, r1, r2, r3, addr): %u %u %u %u %u", &opcode, &r1, &r2, &r3, &addr);

		/* Output Instruction */
		if (encode_instruction(opcode, r1, r2, r3, addr, &hw)) {
			printf("0X%X\n", hw);
		} else {
			printf("Failed to encode\n");
		}
	}

	/* Default */
	return 0;
}
