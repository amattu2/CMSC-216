#include <stdio.h>
#include "machine.h"
#include "machine.c"

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
		unsigned short opcode, r1, r2, r3, addr;
		unsigned int hw;

		/* Read Opcode (0-14) */
		scanf("Opcode: %d\n", &opcode);

		/* Read Register 1 */
		scanf("Register 1 (Or -1): %d\n", &r1);

		/* Read Register 2 */
		scanf("Register 2 (Or -1): %d\n", &r2);

		/* Read Register 3 */
		scanf("Register 1 (Or -1): %d\n", &r3);

		/* Read Addr / Const */
		scanf("Address / Const: %d\n", &addr)

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
