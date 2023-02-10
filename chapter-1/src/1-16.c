/*
** Revise the main routine of the longest line program so it will correctly
** print the lenght of arbitrarily long input lines, and as much as possible of
** the text.
*/

#include <stdio.h>

/* maximum input line size */
#define MAXLINE 1000

int get_line(char[], int);
void copy(char[], char[]);

/* print longest input line */
int main(void)
{
    int i;
    int current_line_length; /* current line length */
    int max_line_length; /* maximum length seen so far */
    char current_line[MAXLINE]; /* current line input */
    char longest_line[MAXLINE]; /* longest line saved here */

    max_line_length = 0;
    while ((current_line_length = get_line(current_line, MAXLINE)) > 0) {
        if (current_line_length > max_line_length) {
            max_line_length = current_line_length;
            copy(longest_line, current_line);
        }
    }
    if (max_line_length > 0) {
        for (i = 0; longest_line[i] != '\0'; i++) {
            ;
        }
        printf("\n\n%d | %s", i - 1, longest_line);
    }
    return 0;
}

/* read a line into s, return length */
int get_line(char s[], int limit)
{
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

/* copy 'from' into 'to'; assume to is big enough */
void copy(char from[], char to[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
