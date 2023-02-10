/*
** Rewrite the function lower, which converts upper case letters to lower case,
** with a conditional expression instead of if-else.
*/

#include <stdio.h>

int lower(int);

int main(void)
{

    printf("%c\n", lower('B'));

    return 0;
}

int lower(int c)
{
    int a;

    a = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;

    return a;
}
