#include "main.h"
/**
 * handleBinary - prints binary
 *@args: argument
 *@nChar: num of chars
 * Return: (void)
 */
void handleBinary(va_list args, int *nChar)
{
	int currentArg = va_arg(args, int);

	if (currentArg == 0)
	{
	char zero = '0';

	write(1, &zero, 1);
	return;
	}
	int binary[CHAR_BIT * sizeof(unsigned int)];
	int i = 0;

	while (currentArg > 0)
	{
	binary[i] = currentArg % 2;
	currentArg /= 2;
	i++;
	}
	int nDigit = digitCounter(currentArg);
	char *str = numberConversion(nDigit, currentArg);

	*nChar += nDigit;
	write(1, str, nDigit);
}
/**
 * handleOctal - Function to convert an integer to its octal representation
 * @nChar: octal str
 * @args: argument
 * Return: (void)
*/
void handleOctal(va_list args, int *nChar)
{
	unsigned int currentArg = va_arg(args, unsigned int);

	if (currentArg == 0)
	{
	char zero = '0';
	*nChar += write(1, &zero, 1);
	return;
	}
	char octal[CHAR_BIT * sizeof(unsigned int)];
	int i = 0;

	while (currentArg > 0)
	{
	octal[i] = currentArg % 8 + '0';
	currentArg /= 8;
	i++;
	}
	for (int j = i - 1; j >= 0; j--)
	{
	*nChar += write(1, &octal[j], 1);
	}
}
/**
 * handleHex - handles x specifier
 * @nChar: number of chars
 * @args: argument
 * Return: (void)
 */
void handleHex(va_list args, int *nChar)
{
	unsigned int currentArg = va_arg(args, unsigned int);

	if (currentArg == 0)
	{
		char zero = '0';
		*nChar += write(1, &zero, 1);
		return;
	}
	char hex[CHAR_BIT * sizeof(unsigned int)];
	int i = 0;

	while (currentArg > 0)
	{
	int remainder = currentArg % 16;

	if (remainder < 10)
		hex[i] = remainder + '0';
	else
		hex[i] = remainder - 10 + 'a';
	currentArg /= 16;
	i++;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		*nChar += write(1, &hex[j], 1);
	}
}
/**
 * handlePointer - prints pointer
 * @nChar: Address to print
 * @args: argument
 * Return: (void)
*/
void handlePointer(va_list args, int *nChar)
{
	void *currentArg = va_arg(args, void *);
	char *str = numberConversion(sizeof(void *) * 2, (intptr_t)currentArg);

	*nChar += write(1, str, strlen(str));
	free(str);
}
