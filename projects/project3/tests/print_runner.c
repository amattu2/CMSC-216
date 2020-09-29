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
		unsigned int line;

		/* Read Hex */
		scanf("Input a 32-bit hex: %x", &line);

		/* Output Instruction */
		print_instruction(line);
		printf("\n");
	}

	/* Default */
	return 0;
}
