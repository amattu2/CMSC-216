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
 * - Utilize the Student structure
 * - Make minor changes to Student struct
 * - Implement getters/setters for student struct
*/

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
  } else if (strlen(name) > 39) {
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

/* Assign new values to student structure */
void init_student(Student *const student, const char name[], unsigned int id,
                  float shoe_size) {
  /* Variables */
  char student_name[40];

  /* Checks */
  if (!student) {
    return;
  }
  if (!name) {
    strcpy(student_name, "");
  } else if (strlen(name) > 39) {
    strncpy(student_name, name, 40);
  } else {
    strcpy(student_name, name);
  }

  /* Assign Values */
  strcpy(student->name, student_name);
  student->id = id;
  student->shoe_size = shoe_size;
}

/* Check student structure id against given id */
unsigned int has_id(Student student, unsigned int id) {
  /* Checks */
  if (student.id != id) {
    return 0;
  }

  /* Default */
  return 1;
}

/* Check student structure name against given name */
unsigned int has_name(Student student, const char name[]) {
  /* Checks */
  if (!student.name) {
    return 0;
  }
  if (!name) {
    return 0;
  }
  if (strcmp(student.name, name) != 0) {
    return 0;
  }

  /* Default */
  return 1;
}

/* Get student structure id */
unsigned int get_id(Student student) {
  return student.id;
}

/* Get student structure shoe size */
float get_shoe_size(Student student) {
  return student.shoe_size;
}

/* Change student shoe size */
Student change_shoe_size(Student student, float new_shoe_size) {
  /* Variables */
  student.shoe_size = new_shoe_size;

  /* Return */
  return student;
}

/* Change student name */
void change_name(Student *const student, const char new_name[]) {
  /* Variables */
  char student_name[40];

  /* Checks */
  if (!student) {
    return;
  }
  if (!new_name) {
    strcpy(student_name, "");
  } else if (strlen(new_name) > 39) {
    strncpy(student_name, new_name, 40);
  } else {
    strcpy(student_name, new_name);
  }

  /* Assign Values */
  strcpy(student->name, student_name);
}
