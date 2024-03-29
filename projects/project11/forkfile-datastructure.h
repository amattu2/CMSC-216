/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: -
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Nov 25th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/* Forkfile data structure */
#ifndef FORKFILE_STRUCT
  /* Define preprocessor variable */
  #define FORKFILE_STRUCT

  /* Forkfile Generic Node */
  typedef struct dependency {
    int index;
    char *word;
    struct dependency *next;
  } Dependency;

  /* Forkfile Target Structure */
  typedef struct rule {
    /* Item Index */
    int index;
    /* Rule (Target) Name */
    char *name;
    /* Dependency Count */
    int dependency_count;
    /* Dependancies (Linked List) */
    struct dependency *dependency_head;
    /* Command Line */
    char *action;
    /* Next Rule */
    struct rule *next;
  } Rule;

  /* Forkfile Encompassing Structure */
  typedef struct forkfile {
    int rule_count;
    struct rule *rule_head;
  } Forkfile;
#endif
