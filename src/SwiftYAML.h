#include <stdio.h>
#include <stdlib.h>

#include "file_util.c"

/* Creates a Swift rule from a filepath */
Swift_Rule *swift_rule_new_from_file(char *);

/* This structure represents an entire Swift-style rule.  Swift rules
   are based heavily on vanilla `arara` rules, with the addition of
   optional meta-data. */
typedef struct Structure__Swift_Rule {
  char *author;			/* NULL if null */
  char *description;		/* NULL if null */
  int minimum_major_version;	/* -1   if null */
  int minimum_minor_version;	/* -1   if null */

  /* the identifier */
  char *identifier;

  /* the human name */
  char *name;

  /* the actual command */
  char *command;

  /* a NULL-terminated list of arguments */
  Swift_Argument *arguments;
} Swift_Rule;


typedef struct Structure__Swift_Argument {
  /* the identifier for the argument, e.g. 'synctex' */
  char *identifier;

  /* the flag addition */
  char *flag;
} Swift_Argument;
