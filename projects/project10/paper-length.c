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

/* Variables */
extern char **environ;

int main(void) {
  pid_t pid;
  int pipefd[2];

  pipe(pipefd);
  pid = fork(); /* TBD safe_fork */

  if (pid > 0) {  /* parent */
    char buf[BUFSIZ];

    close(pipefd[1]);
    if (read(pipefd[0], buf, BUFSIZ) == -1) {
      err(EX_OSERR, "pipe error");
    } else {
      close(pipefd[0]);

      printf("Child process sent: %s\n", buf);
    }
  } else {
    if (pid == 0) {  /* child */
      char message[] = "You must write your own tests of your project code!!!";

      execlp("/usr/bin/wc", "wc", "-w", NULL);
      
      close(pipefd[0]);
      printf("Child is sending crucial message to parent.\n");
      if (write(pipefd[1], message, sizeof(message)) == -1)
        err(EX_OSERR, "pipe error");

      close(pipefd[1]);

    } else err(EX_OSERR, "fork error");
  }
  return 0;
}
