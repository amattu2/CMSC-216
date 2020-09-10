/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date:
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/* Files */
#include <stdio.h>

/*
 * Determine if given year has 365/366 days
 *
 * @param int year
 * @return int -1 (invalid) / 0 (365d) / 1 (366d)
*/
int has366(int year) {
	/* Checks */
	if (year <= 1752) { return -1; }
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return 1;
	} else {
		return 0;
	}
}

/*
 * Calculate the sum of positive divisors
 *
 * @param int -1 (invalid) / sum
*/
long sopd(int num, int n) {
	/* Checks */
	if (num < 1 || n < 0) { return -1; }

	/* Variables */
	long sum = 0;

	/* Return */
	return sum;
}

/*
 * Calculate the power of a variable
 *
 * @param long base
 * @param int exponent
 *
 * printf("%zu", power(2, 2));
*/
long power(long base, int exponent) {
	/* Variables */
	long sum = base;

	/* Loops */
	for (int i = 0; i < exponent; i++) {
		printf("%1d\n", sum);
		sum *= base;
	}

	/* Return */
	printf("Result %1d\n", sum);
	return sum;
}
