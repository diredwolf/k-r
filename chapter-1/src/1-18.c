/*
** Write a program to remove trailing blanks and tabs from each line of input,
** and to delete entirely blank lines.
*/

#include <stdio.h>

#define MAXLINE 1000

int get_line(char[], int);
void rm_blank(char[], char[]);

int main(void)
{
    char s[MAXLINE];
    char s_no_blank[MAXLINE];

    while (get_line(s, MAXLINE) > 0) {
        rm_blank(s, s_no_blank);
        printf("%s", s_no_blank);
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

/* remove trailing blanks and tabs from a character string and return length */
void rm_blank(char from[], char to[])
{
    int i, j, k;

    i = j = k = 0;

    /* remove empty lines */
    if (from[0] == '\n') {
        to[0] = '\0';
        return;
    }

    for (i = 0; from[i] != '\n'; i++) {
        ;
    }

    /* back off from '\n' */
    while (i >= 0 && (from[i] == ' ' || from[i] == '\t')) {
        i--;
    }

    k = i;

    for (i = 0, j = 0; j != k; i++, j++) {
        to[j] = from[i];
    }

    to[j] = '\n';
    to[j + 1] = '\0';
}
