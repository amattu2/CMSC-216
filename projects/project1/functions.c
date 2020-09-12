/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Sept 12th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/* Files */
#include "functions.h"

/* Prototypes */
long power(long base, int exponent);

/*
 * Determine if given year has 365/366 days
 *
 * @param int year
 * @return int -1 (invalid) / 0 (365d) / 1 (366d)
 * @author Alec M.
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
 * @return long sum
 * @author Alec M.
*/
long sopd(int num, int n) {
	/* Variables */
	long sum = 0;
	int i;

	/* Checks */
	if (num < 1 || n < 0) { return -1; }

	/* Loops */
	for (i = 1; i <= num; i++) {
		/* Checks */
		if (num % i != 0) { continue; }

		/* Variables */
		sum += power(i, n);
	}

	/* Return */
	return sum;
}

/*
 * Calculate the power of a variable
 *
 * @param long base
 * @param int exponent
 * @return long sum
 * @author Alec M.
*/
long power(long base, int exponent) {
	/* Variables */
	long sum = base;
	int i;

	/* Checks */
	if (exponent == 0) {
		return 1;
	}

	/* Loops */
	for (i = 0; i < (exponent-1); i++) {
		sum *= base;
	}

	/* Return */
	return sum;
}
