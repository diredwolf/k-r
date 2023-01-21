/*
** Write a program to print a histogram of the lengths of words in its input. It
** is easy to draw the histogram with the bars horizontal; a vertical
** orientation is more challenging.
*/

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 46

int main(void) {
  int c, i, state, characters_in_word, height, width;
  int word_length[MAX_WORD_LENGTH];

  c = characters_in_word = height = width = 0;
  state = OUT;
  for (i = 0; i < MAX_WORD_LENGTH; ++i) {
    word_length[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      ++characters_in_word;
      state = IN;
    } else if (state == IN) {
      ++word_length[characters_in_word];
      characters_in_word = 0;
      state = OUT;
    }
  }
  printf("\n\n");

  /* Determine the height of the histogram */

  for (i = 0; i < MAX_WORD_LENGTH; ++i) {
    if (height <= word_length[i]) {
      height = word_length[i];
    }
  }

  /* Determine the width of the histogram */

  for (i = (MAX_WORD_LENGTH - 1); width == 0; --i) {
    if (word_length[i] != 0) {
      width = i;
    }
  }

  /* Plot the histogram line by line, starting from the top one. */

  while (height > 0) {
    printf("%3d ", height);

    for (i = 1; i <= width; ++i) {
      if (height > word_length[i]) {
        printf("   ");
      } else {
        printf(" # ");
      }
    }
    --height;
    printf("\n");
  }

  /* Print the values along the x axis */

  for (i = 0; i <= width; ++i) {
    printf("%3d", i);
  }

  printf("\n\nx axis : number of characters in a word\ny axis : number of occurences of a word of length x\n\n");

  return 0;
}
