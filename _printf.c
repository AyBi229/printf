#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * _printf - the printf function
 * @param format A format string containing text and format specifiers.
 * @param ... Variable arguments for format specifiers.
 * @return The total number of characters printed.
 */
int _printf(const char *format, ...)
{
	int nChar = 0; va_list args;

	va_start(args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			nChar++;
			write(1, &format[i], 1);
		}
		else
		{
			switch (format[i + 1])
			{
				case 'c':
					{
						nChar++; char currentArg = va_arg(args, int);

						write(1, &currentArg, 1);
						break;
					}
				case 's':
					{
						char *currentArg = va_arg(args, char *);

						nChar += strlen(currentArg);
						write(1, currentArg, strlen(currentArg));
						break;
					}
				case 'd':
				case 'i':
					{
						int currentArg = va_arg(args, int), nDigit = digitCounter(currentArg);
						char *str = numberConversion(nDigit, currentArg);

						nChar += nDigit;
						write(1, str, strlen(str));
						break;
					}
				case '%':
					{
						char percent = '%';

						write(1, &percent, 1);
						break;
					}
				default:
					break;
			}
		}
	}
	va_end(args);
	return (nChar);
}
