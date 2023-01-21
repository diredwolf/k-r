/*
** Write the function any(s1,s2), which returns the first location in the string
** s1 where any character from the string s2 occurs, or -1 if s1 contains no
** characters from s2. (The standard library function strpbrk does the same job
** but returns a pointer to the location.)
*/

#include <stdio.h>
#include <string.h>

int any(char[], char[]);

int main(void) {
  char s1[] = "This is a sentence.";
  char s2[] = "aie ";

  printf("return value: %d\n", any(s1, s2));

  return 0;
}

int any(char s1[], char s2[]) {
  int c, found, i, j, sl1, sl2;

  sl1 = strlen(s1);
  sl2 = strlen(s2);
  found = 0;

  /* if s2 is empty, stop there */
  if (sl2 == 0) {
    return -1;
  }

  for (i = 0; i < sl2; i++) {
    c = s2[i];
    for (j = 0; j < sl1; j++) {
      if (s1[j] == c) {
        printf("Found \"%c\" at column %d\n", c, j);
        found++;
        break;
      }
    }
  }
  if (found == 0)
    return -1;
  else
    return 0;
}
