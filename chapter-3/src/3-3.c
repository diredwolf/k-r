/*
** Write a function expand(s1,s2) that expands shorthands notations like a-z in
** the string s1 into the equivalent complete list abc...xyz in s2. Allow for
** letters of either case and digits, and be prepared to handle cases like a-b-c
** and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally
*/

#include <ctype.h>
#include <stdio.h>

void expand(char[], char[], int);

int main(void)
{
    static char g[] = "A-z a-z hello 0-9 world A-Z this 5-0 is f-l a-z0-9 well-read -a-z a-z- a-b-c a-a";
    char f[sizeof(g) * 10];

    expand(g, f, sizeof(f));

    printf("%s\n\n%s\n", g, f);

    return 0;
}

void expand(char s1[], char s2[], int size)
{
    int i, j;
    int low, up; /* lower and upper bound of the range */

    for (i = j = 0; s1[i] != '\0' && (j < size - 1); i++, j++) {
        if (s1[i + 1] == '-') {
            if (isalnum(s1[i]) && isalnum(s1[i + 2]) && (isblank(s1[i - 1]) || isblank(s1[i + 3]))) {
                i += 2;
                low = s1[i - 2];
                up = s1[i];
                if (low < up) {
                    while (low <= up - 1) {
                        s2[j++] = low++;
                    }
                } else {
                    while (low >= up + 1) {
                        s2[j++] = low--;
                    }
                }
            }
        }
        s2[j] = s1[i];
    }
    s2[j] = '\0';
}
