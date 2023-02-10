/*
** Our binary search makes two tests inside the loop, when one would suffice (at
** the price of more tests outside). Write a version with only one test inside
** the loop and measure the difference in run-time
*/

#include <stdio.h>

int binsearchv1(int, int[], int);
int binsearchv2(int, int[], int);

int main(void)
{
    int i, n, v1, v2, x;
    int v[100];

    for (i = 0; i < 100; i++) {
        v[i] = i;
    }

    n = 100;
    x = 99;

    v1 = binsearchv1(x, v, n);
    v2 = binsearchv2(x, v, n);

    if (v1 >= 0 && v2 >= 0) {
        printf("V1 :: %d found at position %d\n", x, v1);
        printf("V2 :: %d found at position %d\n", x, v2);
    } else {
        printf("V1 :: %d not found\n", x);
        printf("V2 :: %d not found\n", x);
    }
    return 0;
}

int binsearchv1(int x, int v[], int n)
{
    int high, low, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binsearchv2(int x, int v[], int n)
{
    int high, low, mid;

    low = 0;
    high = n - 1;
    mid = 0;

    while (low <= high && x != v[mid]) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}
