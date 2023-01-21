/*
** In a two's complement system, x &= (x - 1) deletes the rightmost 1-bit in x.
** Explain why. Use this observation to write a faster version of bitcount
*/

/*
** In a two's complement system, -1 is encoded as all ones i.e. 11111111. If x
** is odd, it means the LSB is a 1 so we just need to change it to a 0. If x is
** even, it means the LSB is 0 so we need to flip all 0-bits until we find a
** 1-bit we can flip. For example :
**
** 209    = 11010001
** x - 1  = 11010000
** x - 2  = 11001111
**
** We can see that (x - 1) deletes the righmost 1-bit in x. Now we use the &
** operator, if x contains 1 1-bit, x &= (x - 1) = 0 since we deleted the only
** 1-bit in this number. Oterwise we have to repeat the process of deleting
** another 1-bit until x = 0. So Instead of checking each bit, we can repeat the
** operation until x = 0. For example :
**
** x = 32       = 00100000
** x - 1        = 00011111
** x &= (x - 1) = 00000000 (1)
**
** x = 209         = 11010001
** x - 1           = 11010000
** x &= (x - 1)    = 11010000 (1)
** x - 1           = 11001111
** x &= (x - 1)    = 11000000 (2)
** x - 1           = 10111111
** x &= (x - 1)    = 10000000 (3)
** x - 1           = 01111111
** x &= (x - 1)    = 00000000 (4)
**
** As we can see it took us 1 step to get to 0 in the case where x = 32, so x
** contains 1 1-bit. In the second case, it took us 4 steps so 209 contains 4
** 1-bits.
*/

#include <stdio.h>

int bitcount(unsigned int);

int main(void) {
  int x = 127;

  printf("%d contains %d 1-bit\n", x, bitcount(x));

  return 0;
}

int bitcount(unsigned int x) {
  int b = 0;
  while (x != 0) {
    x &= (x - 1);
    b++;
  }
  return b;
}
