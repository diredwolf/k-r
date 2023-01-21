/*
** Write a function escape(s,t) that converts characters like newline and tab
** into visible escape sequences like \n and \t as it copies the string t to s.
** Write a function for the other direction as well, converting escape sequences
** into the real characters.
*/

#include <stdio.h>

void escapev1(char[], char[]);
void escapev2(char[], char[]);

int main(void) {
  char t1[] = "Hello\tWorld!\nThis is a test\v\nTo see\f if\n the\n\\ \' \" \? program works.";
  char s1[sizeof(t1) * 2];
  char s2[sizeof(t1) * 2];

  escapev1(s1, t1);
  escapev2(s2, s1);

  printf("%s\n\n", t1);
  printf("# ESCAPEV1\n%s\n\n", s1);
  printf("# ESCAPEV2\n%s\n", s2);

  return 0;
}

/* converts characters to visible escape sequences while copying t to s */
void escapev1(char s[], char t[]) {
  int i, j;

  for (i = 0, j = 0; t[i] != '\0'; i++, j++) {
    switch (t[i]) {
    case '\a':
      s[j] = '\\';
      j++;
      s[j] = 'a';
      break;
    case '\b':
      s[j] = '\\';
      j++;
      s[j] = 'b';
      break;
    case '\f':
      s[j] = '\\';
      j++;
      s[j] = 'f';
      break;
    case '\n':
      s[j] = '\\';
      j++;
      s[j] = 'n';
      break;
    case '\r':
      s[j] = '\\';
      j++;
      s[j] = 'r';
      break;
    case '\t':
      s[j] = '\\';
      j++;
      s[j] = 't';
      break;
    case '\v':
      s[j] = '\\';
      j++;
      s[j] = 'v';
      break;
    case '\\':
      s[j] = '\\';
      j++;
      s[j] = '\\';
      break;
    case '\'':
      s[j] = '\\';
      j++;
      s[j] = '\'';
      break;
    case '\"':
      s[j] = '\\';
      j++;
      s[j] = '\"';
      break;
    case '\?':
      s[j] = '\\';
      j++;
      s[j] = '?';
      break;
    default:
      s[j] = t[i];
      break;
    }
  }
  s[j] = '\0';
}

/* converts visible escape sequences to characters while copying t to s */
void escapev2(char s[], char t[]) {
  int i, j;

  for (i = 0, j = 0; t[i] != '\0'; i++, j++) {
    switch (t[i]) {
    case '\\':
      switch (t[i + 1]) {
      case 'a':
        s[j] = '\a';
        i++;
        break;
      case 'b':
        s[j] = '\b';
        i++;
        break;
      case 'f':
        s[j] = '\f';
        i++;
        break;
      case 'n':
        s[j] = '\n';
        i++;
        break;
      case 'r':
        s[j] = '\r';
        i++;
        break;
      case 't':
        s[j] = '\t';
        i++;
        break;
      case 'v':
        s[j] = '\v';
        i++;
        break;
      case '\\':
        s[j] = '\\';
        i++;
        break;
      case '\'':
        s[j] = '\'';
        i++;
        break;
      case '\"':
        s[j] = '\"';
        i++;
        break;
      case '\?':
        s[j] = '\?';
        i++;
        break;
      default:
        break;
      }
      break;
    default:
      s[j] = t[i];
      break;
    }
  }
  s[j] = '\0';
}
