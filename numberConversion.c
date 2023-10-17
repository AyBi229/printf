#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * numberConversion - converts a num.
 * @number: the integer to be converted
 * @nDigit: the number of digits
 *
 * Return: a string .
 */
char *numberConversion(unsigned int nDigit, int number)
{
	char *str = (char *)malloc(nDigit + 1);

	if (!str)
		exit(1);
	snprintf(str, nDigit + 1, "%d", number);

	return (str);
}
