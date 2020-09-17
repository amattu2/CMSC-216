/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Sept 17th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/* Files */
#include <stdio.h>

/* Prototypes */
void parseLine(char line[], int size);
int parseWhitespace(char line[], int size);
void reset(char *array, int size);

/**
 * Main program function
 *
 * @param char argument count
 * @param char argument vector
 * @return int status code
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-17T12:54:12-040
 */
int main(int argc, char *argv[])  {
	/* Variables */
	char line[999];
	int i = 0;

	/* Iterate Through Input */
	while (feof(stdin) != 1) {
		/* Read Character */
		scanf("%c", &line[i]);

		/* Checks for EOL */
		if (line[i] == '\n') {
			/* Variables */
			int index = i;
			i = 0;

			/* Handle Line */
			parseLine(line, index+1);
			reset(line, 999);
			continue;
		}

		/* Increment index */
		i++;
	}

	/* Return */
	return 0;
}

/**
 * Parse a file line
 *
 * @param char[] line array
 * @param int array size
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-17T12:55:38-040
 */
void parseLine(char l[], int size) {
	/* Variables */
	int length = parseWhitespace(l, size);
	int i;

	/* Output */
	printf("%c %4d> ", (length > 80 ? *"X" : *" "), size-1);
	for (i = 0; i < size; i++) {
		/* Output */
		printf("%c", l[i]);
	}
}

/**
 * Calculate the total printable length in char array
 *
 * @param char[] line array
 * @param int array size
 * @return int calculated length
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-17T12:56:36-040
 */
int parseWhitespace(char l[], int size) {
	return 0;
}

/**
 * Reset given character array
 * @param char[] array
 * @param int array size
 * @throws None
 * @author Alec M. <https://amattu.com>
 * @date 2020-09-17T13:04:53-040
 */
void reset(char *array, int size) {
	/* Variables */
	int i;

	/* Loops */
	for (i = 0; i < size; i++) {
		array[i] = '\0';
	}
}
