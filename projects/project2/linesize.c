/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Sept 20th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/**
	Current issues:
	- According to the public tests, \n shouldn't be counted... And when it's on it's own line
	it is being counted
	- With the exception of the first line, most of them have differ in length by 1
	- Tabs are miscounted horribly
 */



/* Files */
#include <stdio.h>

/* Prototypes */
int parseLine(char line[], int size);
int parseWhitespace(char line[], int size);
void reset(char *array, int size);

/**
 * Main program function
 *
 * @param char argument count
 * @param char argument vector
 * @return int status code
 * @author Alec M.
 * @date 2020-09-17T12:54:12-040
 */
int main(int argc, char *argv[])  {
	/* Variables */
	char line[999];
	int array_index = 0;
	int lines_exceeding = 0;
	int line_count = 0;

	/* Iterate Through Input */
	while (feof(stdin) != 1) {
		/* Read Character */
		scanf("%c", &line[array_index]);

		/* Checks for EOL */
		if (line[array_index] == '\n') {
			/* Variables */
			int index = array_index;
			array_index = 0;
			line_count++;

			/* Check parseLint result */
			if (parseLine(line, index) > 80) {
				lines_exceeding++;
			}

			/* Reset Array */
			reset(line, 999);
		}

		/* Increment index */
		array_index++;
	}

	/* Output Results */
	printf("%d %d", line_count, lines_exceeding);

	/* Return */
	return 0;
}

/**
 * Parse a file line
 *
 * @param char[] line array
 * @param int array size
 * @throws None
 * @author Alec M.
 * @date 2020-09-17T12:55:38-040
 */
int parseLine(char l[], int size) {
	/* Variables */
	int length = parseWhitespace(l, size);
	int array_index;

	/* Output */
	printf("%c %4d> ", (length > 80 ? *"X" : *" "), size);
	for (array_index = 0; array_index <= size; array_index++) {
		/* Output */
		printf("%c", l[array_index]);
	}

	/* Return */
	return length;
}

/**
 * Calculate the total printable length in char array
 *
 * @param char[] line array
 * @param int array size
 * @return int calculated length
 * @throws None
 * @author Alec M.
 * @date 2020-09-17T12:56:36-040
 */
int parseWhitespace(char l[], int size) {
	/* Variables */
	int array_index;
	int length = 0;

	/* Iterate Through Array */
	for (array_index = 0; array_index <= size; array_index++) {
		if (l[array_index] == '\t') {
			length += 8 - (length % 8);
		} else if (l[array_index] != '\n') {
			length++;
		}
	}

	/* Return */
	return length;
}

/**
 * Reset given character array
 *
 * @param char[] array
 * @param int array size
 * @throws None
 * @author Alec M.
 * @date 2020-09-17T13:04:53-040
 */
void reset(char *array, int size) {
	/* Variables */
	int array_index;

	/* Iterate Through Array */
	for (array_index = 0; array_index < size; array_index++) {
		array[array_index] = '\0';
	}
}
