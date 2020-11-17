/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: November 17th
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/**
 * The purpose of this project is to
 * - Write a Make utility simulation
 * - Use custom data structure
 * - Use pipes/forking
*/


/* Files */
#include <stdio.h>
#include "forkfile.h"
#include "split.h"
#include "safe-fork.h"
#include "make-target.h"

Forkfile read_forkfile(const char filename[]) {
  struct Forkfile *f = NULL;

  return f;
}

int lookup_target(Forkfile forkfile, const char target_name[]) {
  return 0;
}

void print_action(Forkfile forkfile, int rule_num) {
  return;
}

void print_forkfile(Forkfile forkfile) {
  return;
}

int num_dependencies(Forkfile forkfile, int rule_num) {
  return 0;
}

char *get_dependency(Forkfile forkfile, int rule_num, int dependency_num) {
  return NULL;
}

int exists(const char filename[]) {
  return 0;
}

int is_older(const char filename1[], const char filename2[]) {
  return 0;
}

int do_action(Forkfile forkfile, int rule_num) {
  return 0;
}
