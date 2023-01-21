/*
** Write a function invert(x,p,n) that returns x with the n bits that begin at
** position p inverted (i.e., 1 changed into 0 and vice versa), leaving the
** others unchanged
*/

#include <stdio.h>

int invert(int, int, int);

int main(void) {
  unsigned int x, p, n;
  x = 214;
  p = 4;
  n = 4;

  printf("%d\n", invert(x, p, n));
  return 0;
}

int invert(int x, int p, int n) {
  unsigned int bitmask;
  /* bit shifting by a negetive integer is undefined behavior so we have to check */
  if (p < n)
    return 1;

  bitmask = (~((~0) << n)) << (p - n);
  return (x ^ bitmask);
}
