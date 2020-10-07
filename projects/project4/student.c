/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Oct 8th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/**
 * The purpose of this project is to
 * -
 * -
 * -
*/

/*************************************/
/**** REMOVE AFTER TABS -> SPACES ****/
/*************************************/

/* Files */
#include <string.h>
#include "student.h"

/* Create a new student structure */
Student new_student(const char name[], unsigned int id, float shoe_size) {
	/* Variables */
	Student student;
	char student_name[40];

	/* Checks */
	if (!name) {
		strcpy(student_name, "");
	} else if (strlen(name) > 40) {
		strncpy(student_name, name, 40);
	} else {
		strcpy(student_name, name);
	}

	/* Assign Values */
	strcpy(student.name, student_name);
	student.id = id;
	student.shoe_size = shoe_size;

	/* Return */
	return student;
}
