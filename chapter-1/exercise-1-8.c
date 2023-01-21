/* Write a program to count blanks, tabs and newlines. */

#include <stdio.h>

int main(void) {
  int c, tabs, newlines, blanks;

  tabs = newlines = blanks = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++blanks;
    }
    if (c == '\t') {
      ++tabs;
    }
    if (c == '\n') {
      ++newlines;
    }
  }

  printf("\nTabs: %d\nNewlines: %d\nBlanks: %d\n", tabs, newlines, blanks);

  return 0;
}
