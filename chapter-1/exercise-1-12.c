/* Write a program that prints its input one word per line. */

#include <stdio.h>

#define NONBLANK '0'
#define NEWLINE '\n'

int main(void) {
  int c, state;

  state = NONBLANK;

  while ((c = getchar()) != EOF) {

    if (c == ' ' || c == '\t' || c == '\n') {
      if (state != NEWLINE) {
        putchar('\n');
        state = NEWLINE;
      }
    }

    if (c != ' ' && c != '\t' && c != '\n') {
      putchar(c);
      state = NONBLANK;
    }
  }

  return 0;
}
