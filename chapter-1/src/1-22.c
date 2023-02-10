/*
** Write a program to "fold" long input lines into two or more shorter lines
** after the last non-blank character that occurs before the n-th column of
** input. Make sure your program does something intelligent with very long
** lines, and if there are no blanks or tabs before the specified column.
*/

#include <stdio.h>

#define MAXLINE 1000
#define LIMIT 80

int get_line(char[], int);
void fold(char[], char[], int);

int main(void)
{
    char s[MAXLINE];
    char s_folded[MAXLINE];

    while (get_line(s, MAXLINE) > 0) {
        fold(s, s_folded, LIMIT);
        printf("%s", s_folded);
    }
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

/* fold the line if it is longer than the limit */
void fold(char from[], char to[], int limit)
{
    int i, j;

    i = j = 0;

    while ((to[i] = from[i]) != '\0') {
        i++;
        if (i % limit == 0) {
            j = i;
            while (i > 0 && from[i] != ' ' && from[i] != '\t') {
                i--;
            }
            if (i != 0) {
                to[i] = '\n';
            }
            i = j;
        }
    }
}
