#include <stdio.h>
#include <stdlib.h>

#include "SwiftYAML.h"

Swift_Rule *swift_rule_new_from_file(char *path) {
  FILE *file;
  file = fopen(path, "r");
  if (file == NULL) {
    return NULL;
  }

  Swift_Rule *rule = (Swift_Rule *) malloc(sizeof(Swift_Rule));
  char *line;
  
  

  fclose(file);
}
