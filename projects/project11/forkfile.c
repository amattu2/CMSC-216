/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Nov 18th, 2020
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
static Rule *lookup_rule(Forkfile *ff, int rule_index);

/* Initialize a Forkfile structure */
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

/* Find a makefile target ID */
int lookup_target(Forkfile forkfile, const char target_name[]) {
  /* Variables */
  struct rule *current;

  /* Checks */
  if (!target_name)
    return -1;
  if (!forkfile.rule_head)
    return -1;
  else current = forkfile.rule_head;

  /* Loops */
  while (current && current->next) {
    /* Checks */
    if (current->name && strcmp(current->name, target_name) == 0)
      return current->index;

    /* Assign Values */
    current = current->next;
  }

  /* Default */
  return -1;
}

/* Print a rule action */
void print_action(Forkfile forkfile, int rule_num) {
  /* Variables */
  struct rule *r = lookup_rule(&forkfile, rule_num);

  /* Checks */
  if (!r || rule_num < 0)
    return;

  /* Default */
  printf("%s\n", r->action);
}

/* Print the forkfile contents */
void print_forkfile(Forkfile forkfile) {
  /* Variables */
  struct rule *current = NULL;

  /* Checks */
  if (!forkfile.rule_head)
    return;
  else current = forkfile.rule_head;

  /* Loops */
  while (current) {
    /* Variables */
    struct node *d = current->dependency_head;

    /* Print Rule Name */
    printf("%s:", current->name);
    if (d)
      while (d) {
        printf(" %s", d->name);
        d = d->next;
      }
    else printf("\n");

    /* Print Action */
    printf("%s\n", current->action);

    /* Checks */
    if (current->next)
      printf("\n");

    /* Assign values */
    current = current->next;
  }
}

/* Get the dependency count of a rule */
int num_dependencies(Forkfile forkfile, int rule_num) {
  /* Variables */
  struct rule *r = lookup_rule(&forkfile, rule_num);

  /* Checks */
  if (!r || rule_num < 0)
    return -1;

  /* Default */
  return r->dependency_count;
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
  if (ff->rule_head) {
    /* Variables */
    struct rule *current = ff->rule_head;

    /* Loops */
    while (current && current->next)
      current = current->next;

    /* Assign Values */
    current->next = r;
  } else ff->rule_head = r;
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
  r->action = NULL;
  ff->rule_count++;

  /* Default */
  return r;
}

/* HELPER: Create a new rule action */
static int add_action(Forkfile *ff, Rule *rule, char *line) {
  /* Variables */
  char *action = NULL;
  char *pos;

  /* Checks */
  if (!ff || !rule || !line)
    return 0;
  if ((action = malloc(strlen(line) + 1)))
    strcpy(action, line);
  else return 0;
  if ((pos = strchr(action, '\n')) != NULL)
    *pos = '\0';

  /* Assign Values */
  rule->action = action;

  /* Default */
  return 1;
}

/* HELPER: Create a new rule dependency */
static int add_dependecy(Forkfile *ff, Rule *rule, char *dependency) {
  /* Variables */
  struct node *n;
  char *pos = NULL;

  /* Checks */
  if (!ff || !rule)
    return 0;
  if (!(n = malloc(sizeof(struct node))))
    return 0;
  else n->next = NULL;
  if ((n->name = malloc(strlen(dependency) + 1)))
    n->name = dependency;
  if ((pos = strchr(n->name, '\n')) != NULL)
    *pos = '\0';
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

/* HELPER: Look up a rule by index */
static Rule *lookup_rule(Forkfile *ff, int rule_index) {
  /* Variables */
  struct rule *current;

  /* Checks */
  if (!ff)
    return NULL;
  if (!ff->rule_head)
    return NULL;
  else current = ff->rule_head;

  /* Loops */
  while (current && current->next) {
    /* Checks */
    if (current->index == rule_index)
      return current;

    /* Assign Values */
    current = current->next;
  }

  /* Default */
  return NULL;
}
