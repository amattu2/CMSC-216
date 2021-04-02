/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: -
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
  int word_count;

  pipe(pipefd);
  pid = safe_fork();

  /* Checks */
  if (pid < 0) {
    printf("Unable to establish a fork.\n");
    exit(1);
  }
  if (pid > 0) {
    /* Setup Pipe */
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);

    /* Read Data */
    if (scanf("%i", &word_count) < 0) {
      printf("Unable to read data from pipe.\n");
      exit(1);
    }
    if (word_count >= 200) {
      printf("Long enough!\n");
      exit(0);
    } else {
      printf("Too short!\n");
      exit(1);
    }
  }
  if (pid == 0) {
    /* Setup Pipe */
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
    execlp("/usr/bin/wc", "wc", "-w", NULL);

    /* Failed */
    printf("Unable to execute or establish pipe.\n");
    exit(1);
  }

  /* Default */
  return 0;
}
