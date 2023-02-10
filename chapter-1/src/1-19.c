/*
** Write a function 'reverse(s)' that reverses the character string s. Use it to
** write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAXLINE 1000

int get_line(char[], int);
void reverse(char[], char[]);

int main(void)
{
    char s[MAXLINE];
    char s_reversed[MAXLINE];

    while (get_line(s, MAXLINE) > 0) {
        reverse(s, s_reversed);
        printf("%s", s_reversed);
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

/* reverse the characters in 'from' into 'to'; assume to is big enough */
void reverse(char from[], char to[])
{
    int i, j;

    i = j = 0;

    if (from[0] == '\n') {
        to[0] = '\n';
        to[1] = '\0';
        return;
    }

    for (i = 0; from[i] != '\0'; i++) {
        ;
    }

    for (i = i - 2; i >= 0; i--, j++) {
        to[j] = from[i];
    }

    to[j] = '\n';
    to[j + 1] = '\0';
}
