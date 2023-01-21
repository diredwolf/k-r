/*
** Write a program to determine the range of char, short, int and long
** variables, both signed and unsigned, by printing appropriate values from
** standard headers and by direct computation. Harder if you compute them:
** determine the range of the various floating-point types.
*/

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
  /* Values of integer types as defined in limits.h */
  printf("Maximimum and minimum of values of integers types as defined in limits.h.\n\n");
  printf("Maximum value of char is : %d\n", CHAR_MAX);
  printf("Minimum value of char is : %d\n", CHAR_MIN);
  printf("Maximum value of int is : %d\n", INT_MAX);
  printf("Minimum value of int is : %d\n", INT_MIN);
  printf("Maximum value of long is : %ld\n", LONG_MAX);
  printf("Minimum value of long is : %ld\n", LONG_MIN);
  printf("Maximum value of signed char is : %d\n", SCHAR_MAX);
  printf("Minimum value of signed char is : %d\n", SCHAR_MIN);
  printf("Maximum value of short is : %d\n", SHRT_MAX);
  printf("Minimum value of short is : %d\n", SHRT_MIN);
  printf("Maximum value of unsigned char is : %d\n", UCHAR_MAX);
  printf("Maximum value of unsigned int is : %u\n", UINT_MAX);
  printf("Maximum value of unsigned long is : %lu\n", ULONG_MAX);
  printf("Maximum value of unsigned short is : %d\n", USHRT_MAX);

  /* Values of floating point types as defined in float.h */
  printf("\nMaximimum and minimum of values of floating point types as defined in float.h.\n\n");
  printf("Maximum value of float is : %f\n", FLT_MAX);
  printf("Minimum value of float is : %f\n", FLT_MIN);
  printf("Maximum value of double is : %f\n", DBL_MAX);
  printf("Minimum value of double is : %f\n", DBL_MAX);
  printf("Maximum value of long double is : %Lf\n", LDBL_MAX);
  printf("Minimum value of long double is : %Lf\n", LDBL_MAX);

  /* Value of integers types using computation */
  printf("\nMaximimum and minimum of values of integers types using computation.\n\n");
  printf("signed char min = %d\n", ~(char)((unsigned char)~0 >> 1));
  printf("signed char max = %d\n", (char)((unsigned char)~0 >> 1));

  return 0;
}
