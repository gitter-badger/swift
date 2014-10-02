typedef struct Structure__Swift_Rule {
  char *author;
  char *description;
  int minimum_major_version;
  int minimum_minor_version;

  /* the identifier */
  char *identifier;

  /* the human name */
  char *name;

  /* the actual command */
  char *command;

  /* a NULL-terminated list of arguments */
  Swift_Argument *arguments;
} Swift_Configuration;

typedef struct Structure__Swift_Argument {
  /* the identifier for the argument, e.g. 'synctex' */
  char *identifier;

  /* the flag addition */
  char *flag;
} Swift_Argument;
