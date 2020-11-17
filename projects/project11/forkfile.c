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
static int add_dependecy(Forkfile *ff, Rule *rule, char *dependency);

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
  char *pos;

  /* Checks */
  if (!ff || !(r = malloc(sizeof(struct rule))))
    return NULL;
  if (!(r->dependency_head = malloc(sizeof(struct node*))))
    return NULL;
  else r->dependency_head = NULL;
  if ((name = strtok(line, " ")) && (r->name = malloc(strlen(name) + 1))) {
    /* Remove Colon */
    if ((pos = strchr(name, ':')) != NULL)
      *pos = '\0';

    /* Variables */
    r->name = name;
  } else return NULL;
  if ((dependency = strtok(NULL, " "))) {
    while (dependency != NULL) {
      /* Remove Newline */
      if ((pos = strchr(dependency, '\n')) != NULL)
        *pos = '\0';

      /* Add Dependency */
      add_dependecy(ff, r, dependency);

      /* Variables */
      dependency = strtok(NULL, " ");
      dependency_count++;
    }
  }

  /* Assign Values */
  r->index = ff->rule_count; /* Naturally zero-indexed */
  r->dependency_count = dependency_count;
  r->action = "";
  ff->rule_count++;

  /* Default */
  return r;
}

/* HELPER: Create a new rule action */
static int add_action(Forkfile *ff, Rule *rule, char *line) {
  return 0;
}

/* HELPER: Create a new rule dependency */
static int add_dependecy(Forkfile *ff, Rule *rule, char *dependency) {
  /* Variables */
  struct node *n;
  char *name = NULL;

  /* Checks */
  if (!ff || !rule)
    return 0;
  if (!(n = malloc(sizeof(struct node))))
    return 0;
  else n->next = NULL;
  if ((name = malloc(strlen(dependency) + 1)))
    n->name = name;
  if (rule->dependency_head) {
    /* Variables */
    struct node *current = rule->dependency_head;

    /* Loops */
    while (current && current->next)
      current = current->next;

    /* Assign Next */
    current->next = n;
  } else rule->dependency_head = n;

  /* Return */
  return 1;
}
