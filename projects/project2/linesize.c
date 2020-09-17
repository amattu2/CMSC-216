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
int parseTabs(char l[], int size);

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

			/* Reset Array */
			for (index = 0; index < 999; index++) {
				line[index] = '\0';
			}
		}

		/* Increment index */
		i++;
	}

	/* Return */
	return 0;
}

void parseLine(char l[], int size) {
	/* Variables */
	int length = parseTabs(l, size); /* Occupied (tabs, etc) length */
	int i;

	/* Output */
	printf("%c %4d> ", (length > 80 ? *"X" : *" "), size);
	for (i = 0; i < size; i++) {
		printf("%c", l[i]);
	}
}

int parseTabs(char l[], int size) {
	return 0;
}
