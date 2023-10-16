#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * Custom printf function that formats and prints text to the standard output.
 * It processes format specifiers ('%c', '%s', '%d', '%i', and '%%') and handles
 * both character and string printing, integer formatting, and the '%' character.
 *
 * @param format A format string containing text and format specifiers.
 * @param ... Variable arguments for format specifiers.
 * @return The total number of characters printed.
 */
int _printf(const char *format, ...) {
    int nChar = 0;
    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            nChar++;
            write(1, &format[i], 1);
        } else {
            i++;
            switch (format[i]) {
                case 'c': {
                    nChar++;
                    char currentArg = va_arg(args, int);
                    write(1, &currentArg, 1);
                    break;
                }
                case 's': {
                    char *currentArg = va_arg(args, char *);
                    nChar += strlen(currentArg);
                    write(1, currentArg, strlen(currentArg));
                    break;
                }
                case 'd':
                case 'i': {
                    int currentArg = va_arg(args, int);
                    int nDigit = digitCounter(currentArg);
                    nChar += nDigit;
                    char *str = numberConversion(nDigit, currentArg);
                    write(1, str, strlen(str));
                    break;
                }
                case '%': {
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
    return nChar;
}

