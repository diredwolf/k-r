/*
** Write a program to print a histogram of the lengths of words in its input. It is
** easy to draw the histogram with the bars horizontal; a vertical orientation is
** more challenging.
*/

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 46

int main(void)
{
    int c, i, j, characters_in_word, state;
    int word_length[MAX_WORD_LENGTH];

    c = characters_in_word = 0;
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

    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        if (word_length[i] != 0) {
            printf("\n%2d |", i);
            for (j = 0; j < word_length[i]; ++j) {
                printf("=");
            }
            printf(" %d", j);
        }
    }
    printf("\n");
    return 0;
}
