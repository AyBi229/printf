#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Converts an integer to a string representation.
 *
 * This function allocates memory for the string representation, converts the
 * integer to a string using snprintf, and returns the resulting string.
 *
 * @param nDigit The number of digits expected in the resulting string.
 * @param number The integer to be converted to a string.
 * @return A dynamically allocated string containing the integer as a string.
 */
char *numberConversion(unsigned int nDigit, int number)
{
    char *str = (char *)malloc(nDigit+1);
    if (!str) exit (1);
    snprintf(str, nDigit+1, "%d", number);
    return (str);
}

