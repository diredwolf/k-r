/*
** Write a function rightrot(x,n) that returns the value of the integer rotated
** to the right by n bit positions.
*/

#include <stdio.h>

int rightrot(int, int);

int main(void)
{
    unsigned int x, n;
    x = 209;
    n = 3;

    printf("%d\n", rightrot(x, n));

    return 0;
}

int rightrot(int x, int n)
{
    unsigned int bitmask, r, v, y, z;
    bitmask = ~((~0) << n);
    r = y = z = 0;
    v = x;

    /* this allows us to determine the number of significant bits i.e. 8, 16, 32, or 64 */
    while (v >>= 1) {
        r++;
    }

    z = (r + 1) - n;
    y = bitmask & x;
    x >>= n;
    y <<= z;

    return (x ^ y);
}
