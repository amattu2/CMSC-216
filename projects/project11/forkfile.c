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
#include <stdlib.h>
#include <string.h>
#include "forkfile.h"
#include "split.h"
#include "safe-fork.h"
#include "make-target.h"

/* Prototypes */
static Rule *add_rule(Forkfile *ff, char *line);
static int add_action(Forkfile *ff, Rule *rule, char *line);

Forkfile read_forkfile(const char filename[]) {
  /* Variables */
  Forkfile ff = {0, NULL};
  FILE *file = NULL;
  int rule_open = 0;
  char line[1001];
  struct rule *last_rule = NULL;

  /* Checks */
  if (!filename)
    return ff;
  if (!(file = fopen(filename, "r")))
    return ff;

  /* Read Lines */
  while (fgets(line, sizeof(line), file)) {
    /* Checks */
    if (!line[0] || line[0] == '\n' || line[0] == ' ')
      continue;
    if (line[0] == '\t' && rule_open) {
      add_action(&ff, last_rule, line);
      rule_open = 0;
    } else {
      last_rule = add_rule(&ff, line);
      rule_open = 1;
    }
  }

  /* Return */
  fclose(file);
  return ff;
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

/* HELPER: Create a new rule */
static Rule *add_rule(Forkfile *ff, char *line) {
  /* Variables */
  struct rule *r = NULL;
  char *name = NULL;
  int dependency_count = 0;
  char *dependency = NULL;

  /* Checks */
  if (!ff || !(r = malloc(sizeof(Forkfile))))
    return NULL;
  if ((name = strtok(line, " ")) && (r->name = malloc(strlen(name) + 1))) {
    name[strlen(name) - 1] = '\0';
    printf("Name: %s\n", name);
    r->name = name;
  } else return r;
  if ((dependency = strtok(NULL, " "))) {
    while (dependency != NULL) {
      printf("Dependecy: %s\n", dependency);
      dependency = strtok(NULL, " ");
      dependency_count++;
      /* add head using a function.. dont use this function for that */
    }
    printf("DP count: %i\n", dependency_count);
  } else {
    r->dependency_count = 0;
    r->dependency_head = NULL;
  }

  /* Default */
  return r;
}

/* HELPER: Create a new rule action */
static int add_action(Forkfile *ff, Rule *rule, char *line) {
  return 0;
}
