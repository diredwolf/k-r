/*
** Write a version of itoa that accepts three arguments instead of two. The
** third argument is a minimum fiel width; the converted integer must be padded
** with blanks on the left if necessary to make it wide enough.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char[]);
void itoa(int, char[], int);

int main(void)
{
    int n = 189;
    char s[15];

    itoa(n, s, 10);

    printf("%s\n", s);

    return 0;
}

/* reverse string s in place */
void reverse(char s[])
{

    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* convert n to characters in s */
void itoa(int n, char s[], int width)
{
    int i, sign;

    i = 0;
    sign = n;
    do {
        s[i++] = abs(n % 10) + '0';
    } while (abs((n /= 10)) > 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < width) /*  Only addition to original function  */
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}
