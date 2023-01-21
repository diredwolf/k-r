/*
** Write a program to print a histogram of the frequencies of different
** characters in its input.
*/

#include <stdio.h>

/* Number of printable characters in the ASCII character set from 32 to 126 */
#define ASCII_PRINT 94
/* Decimal value of the first printable character in the ASCII character set */
#define FIRST_CHAR 32

int main(void) {
  int c, i, j;
  int char_set[ASCII_PRINT];
  c = i = j = 0;
  for (i = 0; i < ASCII_PRINT; ++i) {
    char_set[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= FIRST_CHAR) {
      ++char_set[c - FIRST_CHAR];
    }
  }

  /* Prints only the characters used in the input, not the entire ASCII table. */
  for (i = 0; i < ASCII_PRINT; ++i) {
    if (char_set[i] != 0) {
      printf("\n%c | ", i + FIRST_CHAR);
      for (j = 0; j < char_set[i]; ++j) {
        printf("=");
      }
      printf(" %d", j);
    }
  }

  printf("\n");

  return 0;
}
