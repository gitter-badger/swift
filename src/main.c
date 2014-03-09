#include "file_util.c"

int main(int argc, char **argv) {
  FILE *test;
  char *line;
  puts("declared variables");
  test = fopen("lualatexmk.yaml", "r");
  if (test != NULL) {
    puts("opened file");
    line = freadline(test);
    while (line != NULL) {
      puts(line);
      free(line);
      line = freadline(test);
    }
  }
  fclose(test);
  return 0;
}
