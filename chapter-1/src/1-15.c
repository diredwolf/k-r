/*
** Rewrite the temperature conversion program of section 1.2 to use a function
** for conversion.
*/

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahrenheit_to_celsius(int);

int main(void)
{
    int i;

    for (i = LOWER; i <= UPPER; i = i + STEP) {
        printf("%3d\t%6.1f\n", i, fahrenheit_to_celsius(i));
    }

    return 0;
}

/* Converts a Fahrenheit temperature in Celsius */
float fahrenheit_to_celsius(int fahrenheit)
{
    float celsius;
    celsius = (5.0 / 9.0) * (fahrenheit - 32.0);

    return celsius;
}
