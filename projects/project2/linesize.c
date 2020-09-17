/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Sept 16th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/* Files */
#include <stdio.h>

/* Prototypes */


int main(int argc, char *argv[])  {
	/* Variables */
	int i = 0;
	char *string = argv[1];

	/* Checks */
	if (argc < 2) {
		printf("You did not provide enough arguments. (Given: %d)\n", argc);
		return 0;
	}

	/* This is the closest thing I can get to work.
		a.out test.123 - Outputs test.123
		a.out < test.txt - Argument 1 (argv[1]) is null
	*/
	while (string[i] != '\0') {
		printf("%c\n", string[i]);
		i++;
	}

	/* Return */
	return 0;
}

void readFile(char *filename) {
	/* Read a file line by line, pass it to parseInput */
}

void parseInput(void) {
	/* Read from input, call readLine */
}

void parseLine(void) {
	/* Parse input, account for tabs, output result for line */

	/* Variables */
	int size = 0; /* Number of characters in the line */
	int length = 0; /* Occupied (tabs, etc) length */

	/* Output */
	printf("%c %04d> ", (length > 80 ? *"X" : *" "), size);

}

void parseTabs(void) {
	/* Replace tabs per requirement and return string */
}
