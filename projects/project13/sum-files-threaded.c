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
*/

/* (c) Larry Herman, 2020.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
  long one_file_sum, all_files_total= 0;
  int i, n;
  FILE *fp;

  if (argc > 1) {
    for (i= 1; i < argc; i++) {
      fp= fopen(argv[i], "r");

      /* silently ignore nonexistent files, or ones that there was an error
         trying to open */
      if (fp != NULL) {
        one_file_sum= 0;
        fscanf(fp, "%d", &n);

        while (!feof(fp)) {
          one_file_sum += n;
          fscanf(fp, "%d", &n);
        }

        all_files_total += one_file_sum;
      }
    }
  }

  printf("%ld\n", all_files_total);

  return 0;
}
