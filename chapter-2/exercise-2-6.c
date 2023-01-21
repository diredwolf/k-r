/*
** Write a function setbits(x,p,n,y) that returns x with the n bits that begin
** at position p set to the rightmost n bits of y, leaving the other bits
** unchanged
*/

#include <stdio.h>

int setbits(int, int, int, int);

int main(void) {
  long int n, p, x, y;
  p = 2;
  n = 2;
  x = 0;
  y = 1;

  printf("%d\n", setbits(x, p, n, y));

  return 0;
}

int setbits(int x, int p, int n, int y) {
  int bitmask = ~((~0) << n);
  return ((bitmask & y) << p) | (~(bitmask << p) & x);
}
