#include "main.h"
/**
 * _printf - the printf function
 * @param format A format string containing text and format specifiers.
 * @param ... Variable arguments for format specifiers.
 * @return The total number of characters printed.
 */
SpecifierMapping specifierMap[] = {
	{'c', handleChar},
	{'s', handleString},
	{'d', handleInt},
	{'i', handleInt},
	{'u', handleInt},
	{'%', handlePercent},
	{'b', handleBinary},
	{'x', handleHex},
	{'X', handleHex},
	{'o', handleOctal},
	{'p', handlePointer},
	{'r', handleReverse},
	{'S', handlePrint_S},
	{'R', handleRot13},
	{0, NULL}
};
int _printf(const char *format, ...)
{
	int nChar = 0;
	va_list args;

	va_start(args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			nChar += write(1, &format[i], 1);
		}
		else
		{
			i++;
			for (SpecifierMapping *mapping = specifierMap;
					mapping->specifier != 0; mapping++)
			{
				if (format[i] == mapping->specifier)
				{
					mapping->handler(args, &nChar);
					break;
				}
			}
		}
	}

	va_end(args);
	return (nChar);
}
