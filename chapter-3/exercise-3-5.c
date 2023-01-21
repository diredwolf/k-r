/*
** Write the function itob(n,s,b) that converts the integer n into a base b
** charatcer representation in the string s. In particular, itob(n,s,16) formats
** n as an hexadecimal integer in s.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NBASE (b <= -2) && (b >= -32)
#define PBASE (b >= 2) && (b <= 32)

void reverse(char[]);
void itob(int, char[], int);

int main(void) {
  int n = 119;
  int b = -3;
  char s[15];

  itob(n, s, b);

  printf("%d in base %d is :: ", n, b);
  printf("%s\n", s);

  return 0;
}

/* reverse string s in place */
void reverse(char s[]) {

  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itob(int n, char s[], int b) {
  int i, sign, x;
  i = 0;
  sign = n;

  /* check if n is 0 */
  if (n == 0) {
    s[i] = '0';
    s[i + 1] = '\0';
    return;
  }

  /* conversion */
  if (PBASE) {
    while (n != 0) {
      x = abs(n % b);
      n = abs(n / b);
      s[i++] = (x <= 9) ? x + '0' : (x - 10) + 'a';
    }
  } else if (NBASE) {
    while (n != 0) {
      x = n % b;
      n = n / b;
      if (x < 0) {
        x += -b;
        n += 1;
      }
      s[i++] = (x <= 9) ? x + '0' : (x - 10) + 'a';
    }
  } else {
    s[i] = '0';
    s[i + 1] = '\0';
    return;
  }

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';

  reverse(s);
}
