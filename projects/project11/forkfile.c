/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Nov 22nd, 2020
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
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <errno.h>
#include "forkfile.h"
#include "split.h"
#include "safe-fork.h"
#include "make-target.h"

/* Prototypes */
static Rule *add_rule(Forkfile *ff, char *line);
static char *add_action(Forkfile *ff, Rule *rule, char *line);
static int add_dependecy(Forkfile *ff, Rule *rule, char *dependency, int index);
static Rule *lookup_rule(Forkfile *ff, int rule_index);
static char *trim_whitespace(char *str, int allow_leading_tab);
static char *replace_tabs(char *str);
static char *remove_extra_spaces(char *str);

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
  while (current) {
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
    struct dependency *d = current->dependency_head;

    /* Print Rule Name */
    printf("%s:", current->name);

    /* Print Rule Dependencies */
    if (d)
      while (d) {
        printf(" %s", d->word);
        d = d->next;
        if (!d)
          printf("\n");
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

/* Get the dependency at index */
char *get_dependency(Forkfile forkfile, int rule_num, int dependency_num) {
  /* Variables */
  struct rule *r = lookup_rule(&forkfile, rule_num);
  struct dependency *current = NULL;

  /* Checks */
  if (!r || rule_num < 0 || !r->dependency_head)
    return NULL;
  else current = r->dependency_head;

  /* Loops */
  while (current) {
    /* Checks */
    if (current->index == dependency_num)
      return current->word;

    /* Next item */
    current = current->next;
  }

  /* Default */
  return NULL;
}

/* Check if a file exists */
int exists(const char filename[]) {
  /* Variables */
  struct stat *s = NULL;
  errno = 0;

  /* Checks */
  if (!filename)
    return 0;
  if (stat(filename, s) == -1 && errno == ENOENT)
    return 0;

  /* Default */
  return 1;
}

/* Check which file is oldest */
int is_older(const char filename1[], const char filename2[]) {
  /* Variables */
  struct stat *s1 = NULL;
  struct stat *s2 = NULL;

  /* Check Arguments */
  if (!filename1 || !filename2)
    return 0;

  /* Check File 1 */
  errno = 0;
  if (stat(filename1, s1) == -1 && errno == ENOENT)
    return 0;

  /* Check File 2 */
  errno = 0;
  if (stat(filename2, s2) == -1 && errno == ENOENT)
    return 0;

  /* Check Time */
  if (s1->st_mtime > s2->st_mtime)
    return 0;

  /* Default */
  return 1;
}

/* Execute command in rule */
int do_action(Forkfile forkfile, int rule_num) {
  /* Variables */
  struct rule *r = lookup_rule(&forkfile, rule_num);
  char **action = NULL;
  pid_t child_pid;

  /* Checks */
  if (!r)
    return -1;
  else action = split(r->action);

  child_pid = fork();

  if (child_pid > 0) {

    printf("\nI am the parent.  My child was %d.\n", child_pid);

  } else {
    if (child_pid == 0) {

      execlp(action[0], action[1], NULL);

    }
  }

  /* Default */
  return 1;
}

/* HELPER: Create a new rule */
static Rule *add_rule(Forkfile *ff, char *line) {
  /* Variables */
  struct rule *r = NULL;
  char *name = NULL;
  char *dependency = NULL;
  char *pos = NULL;

  /* Checks */
  if (!ff || !(r = malloc(sizeof(struct rule))))
    return NULL;

  /* Find insert spot */
  if (ff->rule_head) {
    /* Variables */
    struct rule *current = ff->rule_head;

    /* Loops */
    while (current && current->next)
      current = current->next;

    /* Assign Values */
    current->next = r;
  } else ff->rule_head = r;

  /* Allocate Dependency List */
  if (!(r->dependency_head = malloc(sizeof(struct dependency*))))
    return NULL;
  else r->dependency_head = NULL;

  /* Allocate Target Name */
  line = replace_tabs(line);
  if ((name = strtok(line, " "))) {
    /* Variables */
    char *temp = NULL;

    /* Remove Colon */
    if ((pos = strchr(name, ':')) != NULL)
      *pos = '\0';
    if ((temp = malloc(strlen(name) + 1)))
      strcpy(temp, name);

    /* Variables */
    r->name = trim_whitespace(temp, 0);
  } else return NULL;

  /* Setup Dependencies */
  if ((dependency = strtok(NULL, " "))) {
    while (dependency != NULL) {
      /* Remove Newline */
      if ((pos = strchr(dependency, '\n')) != NULL)
        *pos = '\0';

      /* Add Dependency */
      add_dependecy(ff, r, dependency, r->dependency_count);

      /* Variables */
      dependency = strtok(NULL, " ");
      r->dependency_count++;
    }
  }

  /* Allocate Target Action */
  if (!(r->action = malloc(1)))
    return NULL;
  else r->action = NULL;

  /* Assign Values */
  r->index = ff->rule_count; /* Naturally zero-indexed */
  ff->rule_count++;

  /* Default */
  return r;
}

/* HELPER: Create a new rule action */
static char *add_action(Forkfile *ff, Rule *rule, char *line) {
  /* Variables */
  char *pos = NULL;
  char *action = NULL;

  /* Checks */
  if (!ff || !rule || !line)
    return 0;
  if ((action = malloc(strlen(line) + 1)))
    strcpy(action, line);
  else return 0;
  if ((pos = strchr(action, '\n')) != NULL)
    *pos = '\0';

  /* Default */
  rule->action = remove_extra_spaces(trim_whitespace(action, 1));
  return rule->action;
}

/* HELPER: Create a new rule dependency */
static int add_dependecy(Forkfile *ff, Rule *rule, char *dependency, int index) {
  /* Variables */
  struct dependency *n = NULL;
  char *word = NULL;
  char *pos = NULL;
  dependency = trim_whitespace(dependency, 0);

  /* Checks */
  if (!ff || !rule)
    return 0;
  if (!(n = malloc(sizeof(struct dependency))))
    return 0;
  else n->next = NULL;
  if ((word = malloc(strlen(dependency) + 1)))
    strcpy(word, dependency);
  if ((pos = strchr(word, '\n')) != NULL)
    *pos = '\0';
  if (rule->dependency_head) {
    /* Variables */
    struct dependency *current = rule->dependency_head;

    /* Loops */
    while (current && current->next) {
      current = current->next;
    }

    /* Assign Next */
    current->next = n;
  } else rule->dependency_head = n;

  /* Assign Values */
  n->index = index;
  n->word = trim_whitespace(word, 0);

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
  while (current) {
    /* Checks */
    if (current->index == rule_index)
      return current;

    /* Assign Values */
    current = current->next;
  }

  /* Default */
  return NULL;
}

/* HELPER: Remove string whitespace */
static char *trim_whitespace(char *str, int action_string) {
  /* Variables */
  char *ns;
  int i = 0;
  int nsi = 0;

  /* Checks */
  if (!(ns = malloc(strlen(str))))
    return NULL;

  /* Loops */
  while (str[i]) {
    if (str[i] == '\t' && action_string == 1 && i == 0)
      ns[nsi++] = str[i];
    else if (str[i] == '\t' && action_string == 1 && i > 0)
      ns[nsi++] = ' ';
    else if (str[i] == ' ' && action_string == 1 && i > 0)
      ns[nsi++] = str[i];
    else if (str[i] != '\t' && str[i] != '\n' && str[i] != ' ')
      ns[nsi++] = str[i];

    i++;
  }

  /* Return */
  return ns;
}

/* HELPER: Replace tabs with spaces */
static char *replace_tabs(char *str) {
  /* Variables */
  char *ns;
  int i = 0;
  int nsi = 0;

  /* Checks */
  if (!(ns = malloc(strlen(str))))
    return NULL;

  /* Loops */
  while (str[i]) {
    if (str[i] == '\t')
      ns[nsi++] = ' ';
    else
      ns[nsi++] = str[i];

    i++;
  }

  /* Return */
  return ns;
}

/* HELPER: Remove multiple spaces */
static char *remove_extra_spaces(char *str) {
  /* Variables */
  char *ns;
  int i = 0;
  int nsi = 0;
  char last_char = '\0';

  /* Checks */
  if (!(ns = malloc(strlen(str))))
    return NULL;

  /* Loops */
  while (str[i]) {
    if (str[i] == ' ' && last_char == ' ') {
      i++;
      continue;
    } else {
      ns[nsi++] = str[i];
      last_char = str[i];
    }

    i++;
  }

  /* Return */
  return ns;
}
