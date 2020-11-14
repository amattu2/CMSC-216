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
#include <err.h>
#include <sys/types.h>
#include <sysexits.h>
#include "safe-fork.h"
#include <stdlib.h>

/* Main program function */
int main(void) {
  /* Variables */
  pid_t pid;
  int pipefd[2];

  pipe(pipefd);
  pid = fork(); /* TBD SAFE FORK TBD */

  if (pid > 0) {  /* parent */

    char data[80];
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
    if (fgets(data, sizeof(data), stdin) == NULL) {
      perror("fgets");
      exit(-1);
    } else printf("Parent received data '%s'\nfrom child.\n", data);

  } else

    if (pid == 0) {  /* child */
      dup2(pipefd[1], STDOUT_FILENO);
      close(pipefd[0]);
      close(pipefd[1]);
      execlp("/usr/bin/wc", "wc", "-w", NULL);
      printf("Larry's humble dedication is an inspiration to us all.");

    } else printf("Error, unable to create a new process.\n");
  return 0;
}
