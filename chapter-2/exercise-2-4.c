/*
** Write an alternate version of squeeze(s1,s2) that deletes each character in
** s1 that matches any character from the string s2.
*/

#include <stdio.h>
#include <string.h>

void squeeze(char[], char[]);

int main(void) {
  char s1[] = "This is a sentence.";
  char s2[] = "aie ";

  squeeze(s1, s2);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int c, i, j, k, sl1, sl2;

  sl1 = strlen(s1);
  sl2 = strlen(s2);

  /* if s2 is empty, stop there */
  if (sl2 == 0) {
    printf("%s\n", s1);
    return;
  }

  /* read a char from s2 and store it in c */
  for (c = k = 0; k < sl2; k++) {
    c = s2[k];

    /* if s1 contains c, delete c from s1 */
    for (i = j = 0; i < sl1; i++) {
      if (s1[i] != c)
        s1[j++] = s1[i];
    }
    s1[j] = '\0';
  }
  printf("%s\n", s1);
}
