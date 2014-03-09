#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* You must free what this returns. */
char *freadline(FILE *fp) {
  if (fp == NULL) return NULL;

  const char NEWLINE = '\n';
  const char NULTERM = '\0';

  char this_char;
  char *line;
  unsigned int buf_len;
  unsigned int length;

  buf_len = 80;
  line = (char *) malloc(buf_len * sizeof(char));

  /* Initialize the current length of the string to zero and get the
   * first character of the file.  While we haven't hit a NEWLINE or
   * the end of the file, add the character onto the line and
   * increment its length.
   *
   * If we have reached the end of our buffer, double the buffer's
   * size, reallocate, copy, and free.
   */
  length = 0;
  this_char = fgetc(fp);
  if (this_char == EOF)
    return NULL;
  while (this_char != NEWLINE &&
	 this_char != EOF) {
    line[length++] = this_char;
    this_char = fgetc(fp);

    if (length == buf_len) {
      buf_len *= 2;
      char *temp = (char *) malloc(buf_len * sizeof(char));
      memcpy((void *)temp, (void *)line, length);
      free(line);
      line = temp;
    }
  }

  line[length] = NULTERM;
  return line;
}
