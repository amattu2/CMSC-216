/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: November 14th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/**
 * The purpose of this project is to
 * - Write a "wrapper" for the WC unix utility
 * - Be a short program
 * - That's it.
*/


/* Files */
#include <stdio.h>
#include <unistd.h>
#include "safe-fork.h"

/* Variables */
extern char **environ;

int main(void) {
  execle("/usr/bin/wc)", "wc", "-w", NULL, environ);
  return 0;
}
