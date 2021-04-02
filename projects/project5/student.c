/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: -
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Oct 10th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/**
 * The purpose of this project is to
 * - Utilize the Student structure
 * - Make minor changes to Student struct
 * - Implement getters/setters for student struct
 * - Expand upon P4 with memory allocation
*/

/* Files */
#include <string.h>
#include <stdlib.h>
#include "student.h"

/* Generate a new student structure */
Student *new_student(const char name[], unsigned int id, float shoe_size) {
  /* Variables */
  Student *student;
  char *student_name;

  /* Checks */
  if (!name) {
    student_name = malloc(1);
    strcpy(student_name, "");
  } else {
    student_name = malloc(strlen(name) + 1);
    strcpy(student_name, name);
  }

  /* Assign values */
  student = malloc((strlen(student_name) + 1) + sizeof(int) + sizeof(float));
  student->name = student_name;
  student->id = id;
  student->shoe_size = shoe_size;

  /* Return */
  return student;
}

/* Check if a student has a certain ID */
unsigned int has_id(const Student *const student, unsigned int id) {
  /* Checks */
  if (!student)
    return 0;
  if (student->id != id)
    return 0;

  /* Default */
  return 1;
}

/* Check if a student has a certain name */
unsigned int has_name(const Student *const student, const char name[]) {
  /* Checks */
  if (!student)
    return 0;
  if (!student->name)
    return 0;
  if (!name)
    return 0;
  if (strcmp(student->name, name) != 0)
    return 0;

  /* Default */
  return 1;
}

/* Get student structure id */
unsigned int get_id(const Student *const student) {
  /* Checks */
  if (!student)
    return 0;

  /* Return */
  return student->id;
}

/* Get student structure shoe size */
float get_shoe_size(const Student *const student) {
  /* Checks */
  if (!student)
    return 0.0;

  /* Return */
  return student->shoe_size;
}

/* Change student shoe size */
void change_shoe_size(Student *const student, float new_shoe_size) {
  /* Checks */
  if (!student)
    return;

  /* Return */
  student->shoe_size = new_shoe_size;
}

/* Change student name */
void change_name(Student *const student, const char new_name[]) {
  /* Variables */
  char *student_name;

  /* Checks */
  if (!student)
    return;
  if (!new_name) {
    student_name = malloc(1);
    strcpy(student_name, "");
  } else {
    student_name = malloc(strlen(new_name) + 1);
    strcpy(student_name, new_name);
  }

  /* Assign value */
  free(student->name);
  student->name = student_name;
}

/* Reassign student */
void copy_student(Student *const student1, const Student *const student2) {
  /* Variables */
  char *student_name;

  /* Checks */
  if (!student1 || !student2)
    return;
  if (!student2->name) {
    student_name = malloc(1);
    strcpy(student_name, "");
  } else {
    student_name = malloc(strlen(student2->name) + 1);
    strcpy(student_name, student2->name);
  }

  /* Assign values */
  free(student1->name);
  student1->name = student_name;
  student1->id = student2->id;
  student1->shoe_size = student2->shoe_size;
}
