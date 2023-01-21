/*
** Write a program to print all input lines that are longer than 80
** characters.
*/

#include <stdio.h>

#define MAXLINE 1000
#define CHARLIMIT 80

int get_line(char[], int);

int main(void) {
  int line_length;
  char line[MAXLINE];

  while ((line_length = get_line(line, MAXLINE)) > 0) {
    if (line_length > CHARLIMIT) {
      printf("%s\n", line);
    }
  }
  return 0;
}

/* read a line into s, return length */
int get_line(char s[], int limit) {
  int c, i;

  for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
