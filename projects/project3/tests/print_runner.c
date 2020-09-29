#include <stdio.h>
#include "machine.h"

int main() {
	int i = 0;
	unsigned int line;

	while (feof(stdin) != 1) {
		scanf("%x", &line);
		print_instruction(line);
		printf("\n");
	}
}
