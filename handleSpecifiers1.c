#include "main.h"
/**
 * handleChar - prints char
 * @nchar: num of chars
 * @args: va_list
 * Return: (void)
 **/
void handleChar(va_list args, int *nChar)
{
	char currentArg = va_arg(args, int);

	*nChar += write(1, &currentArg, 1);
}
/**
 * handleString - prints string
 * @nchar: num of chars
 * @args: va_list
 * Return: (void)
 **/
void handleString(va_list args, int *nChar)
{
	char *currentArg = va_arg(args, char *);

	*nChar += write(1, currentArg, strlen(currentArg));
}
/**
 * handleInt - prints int
 * @nchar: num of chars
 * @args: va_list
 * Return: (void)
 **/
void handleInt(va_list args, int *nChar)
{
	int currentArg = va_arg(args, int), nDigit = digitCounter(currentArg);
	char *str = numberConversion(nDigit, currentArg);

	*nChar += nDigit;
	write(1, str, nDigit);
}
/**
 * handlePercent - prints percent sspec
 * @nchar: num of chars
 * @args: va_list
 * Return: (void)
 **/
void handlePercent(va_list args, int *nChar)
{
	*nChar += write(1, "%", 1);
}
