#include "main.h"
#include <math.h>
/**
 * digitCounter - a function to count the number of digits in an integer.
 * @number: number to count
 *
 * Return: number of digits
 */
unsigned int digitCounter(int number)
{
	if (number == 0)
	{
		return (1);
	}
	if (number < 0)
	{
		number = -number;
	}
	int nDigit = (int)log10(number) + 1;

	return (nDigit);
}
