/*
 * CMSC 216 (Fall 2020)
 * Section: 0303 (M/W 8am)
 * University ID: 117568813
 * Directory ID: amattu
 *
 * Author: Alec M.
 * Date: Nov 17th, 2020
 *
 * I pledge on my honor that I have not given or received
 * any unauthorized assistance on this assignment.
*/

/* Forkfile data structure */
#ifndef STRUCT_DEF
  /* Define preprocessor variable */
  #define STRUCT_DEF

  /* Forkfile Generic Node */
  typedef struct node {
    char *name;
    struct node *next;
  } Node;

  /* Forkfile Target Structure */
  typedef struct rule {
    /* Item Index */
    int index;
    /* Rule (Target) Name */
    char *name;
    /* Dependency Count */
    int dependency_count;
    /* Dependancies (Linked List) */
    struct node *dependency_head;
    /* Command Line */
    char *action;
  } Rule;

  /* Forkfile Encompassing Structure */
  typedef struct forkfile {
    int rule_count;
    struct rule *rule_head;
  } Forkfile;
#endif
