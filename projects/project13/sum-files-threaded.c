/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: December 9th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/**
 * The purpose of this project is to
 * - Convert sum-files.c to multi-threaded
 * - Spawn a new thread for each file
 * - Not implement global variables
*/

/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
*/

/* Files */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Prototypes */
static void *sum_file_contents(void *filename);

/* Main function */
int main(int argc, char *argv[]) {
  /* Variables */
  pthread_t *threads = NULL;
  void **thread_results = NULL;
  long file_sum = 0;
  int i = 0;
  int argument_count = argc - 1;

  /* Checks */
  if (!(threads = malloc(sizeof(pthread_t) * argument_count)))
    exit(-1);
  /*if (!(thread_results = malloc(sizeof(long*) * argument_count)))
    exit(-1);
    */
  if (argc > 1) {
    /* Initialize Threads */
    for (i = 1; i < argc; i++) {
      pthread_create(&threads[i], NULL, sum_file_contents, argv[i]);
    }

    /* Close Threads */
    for (i = 1; i < argc; i++) {
      pthread_join(threads[i], &thread_results[i]);
      printf("%ld\n", *(long *) thread_results[i]);
    }
  }

  /* Print Results */
  printf("%ld\n", file_sum);

  /* Default */
  return 0;
}

/* Sum the integer contents of a file */
static void *sum_file_contents(void *filename) {
  /* Variables */
  FILE *file = NULL;
  long *sum = NULL;
  int number = 0;

  /* Checks */
  if ((sum = malloc(sizeof(long*))))
    sum = 0;
  else return 0;
  if (!filename)
    return sum;
  if (!(file = fopen(filename, "r")))
    return sum;

  /* Read File */
  fscanf(file, "%d", &number);
  while (!feof(file)) {
    sum += number;
    fscanf(file, "%d", &number);
  }

  /* Return */
  fclose(file);
  return sum;
}
