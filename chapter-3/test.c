/*
** In a two's complement number representation, our version of itoa does not
** handle the largest negative number, that is, the value of n equal to
** -(2^(wordsize - 1)). Explain why not. Modify it to print that value
** correctly, regardless of the machine on which it runs.
*/

/* In a two-s complement number representation, a signed integer can range from
** -(2^(wordsize - 1)) to 2^(wordsize - 1) - 1. So for an 8 bit signed integer,
** it value can range from -128 and 127. Nowadays an int is 4 bytes which means
** its value can range from -2,147,483,648 to 2,147,483,647. Since abs(-n) is
** bigger than the maximum positive value a signed integer can hold, when we do
** n = -n, n stays negative so we cannot proceed with the rest of our computations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN -2147483648
#define MAX 2147483647

void reverse(char[]);
void itoav1(int, char[]);
void itoav2(int, char[]);
void itoav3(int, char[], int);

int main(void) {
  int n = 189;
  char s[15];

  itoav3(n, s, 10);

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

/* convert n to characters in s */
void itoav1(int n, char s[]) {
  int i, sign;

  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

/* convert n to characters in s */
void itoav2(int n, char s[]) {
  int i, sign;

  sign = n;
  i = 0;

  if ((n % 10) < 0) {
    do {
      s[i++] = -(n % 10) + '0';
    } while ((n /= 10) < 0);
  } else {
    do {
      s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
  }
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

/* convert n to characters in s */
void itoav3(int n, char s[], int width) {
  int i, sign;

  sign = n;
  i = 0;

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
