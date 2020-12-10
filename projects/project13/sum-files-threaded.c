/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: December 10th, 2020
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
  int *create_results = NULL;
  long *results = NULL;
  long sum = 0;
  int i = 0;

  /* Checks */
  if (!(threads = malloc(sizeof(pthread_t) * argc)))
    exit(-1);
  if (!(create_results = malloc(sizeof(create_results) * argc)))
    exit(-1);
  if (!(results = malloc(sizeof(results) * argc)))
    exit(-1);
  if (argc > 1) {
    /* Initialize Threads */
    for (i = 1; i < argc; i++) {
      create_results[i] = pthread_create(&threads[i], NULL, sum_file_contents, argv[i]);
      results[i] = 0;
    }

    /* Close Threads */
    for (i = 1; i < argc; i++) {
      /* Variables */
      void *result = NULL;

      /* Checks */
      if (create_results[i] != 0) {
        printf("Skipped thread %d with result %d\n", i, create_results[i]);
        continue;
      }

      /* Join Thread */
      pthread_join(threads[i], &result); /* Causing seg fault */
      results[i] = *(long *) result;
      free(result);
    }

    /* Sum Results */
    for (i = 1; i < argc; i++)
      sum += results[i];
  }

  /* Print Results */
  printf("%ld\n", sum);

  /* Default */
  free(threads);
  free(results);
  return 0;
}

/* Sum the integer contents of a file */
static void *sum_file_contents(void *filename) {
  /* Variables */
  FILE *file = NULL;
  long *sum = NULL;
  int number = 0;

  /* Checks */
  if ((sum = malloc(sizeof(*sum))))
    *sum = 0;
  else exit(-1);
  if (!filename)
    return sum;
  if (!(file = fopen((char *) filename, "r")))
    return sum;

  /* Read File */
  fscanf(file, "%d", &number);
  while (!feof(file)) {
    *sum += number;
    fscanf(file, "%d", &number);
  }

  /* Return */
  fclose(file);
  return sum;
}
