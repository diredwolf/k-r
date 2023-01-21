/*
** Write a function htoi(s), which converts a string of hexadecimal digits
** (including an optional 0x or 0X) into its equivalent integer value. The
** allowable digits are 0 through 9, a through f, and A through F.
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define ISDIGIT (s[i] >= '0' && s[i] <= '9')
#define ISLETTERLOW (s[i] >= 'a' && s[i] <= 'f')
#define ISLETTERUP (s[i] >= 'A' && s[i] <= 'F')
#define ISX (s[i] == 'x' || s[i] == 'X')

int htoi(char[]);

int main(void) {
  char hex[] = "0x7f54";
  printf("%s = %d\n", hex, htoi(hex));
  return 0;
}

int htoi(char s[]) {

  int i, n, p, x;
  unsigned char len;
  n = x = 0;

  /* get the length of string with strlen() */
  len = strlen(s);

  /* check for allowable digits, if not return error */
  for (i = 0; i < len; ++i) {
    if (ISDIGIT || ISLETTERUP || ISLETTERLOW || ISX) {
      ;
    } else {
      printf("%s is not an hexadecimal number.\n", s);
      return 1;
    }
  }

  /* check if the first characters are either 0x or 0X or x or X. If
    true skip them, if not start at i[0] */
  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    i = 2;
    p = len - 3;
  } else if (s[0] == 'x' || s[0] == 'X') {
    i = 1;
    p = len - 2;
  } else {
    i = 0;
    p = len - 1;
  }

  /* conversion : read char; convert to decimal value; multiply by 16^p; add */
  for (; i <= len; ++i, --p) {
    x = s[i];
    if (ISDIGIT)
      x = x - '0';
    if (ISLETTERUP)
      x = 10 + (x - 'A');
    if (ISLETTERLOW)
      x = 10 + (x - 'a');
    x = x * pow(16, p);
    n = n + x;
  }
  return n;
}
