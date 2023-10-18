#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>

typedef void (*SpecifierHandler)(va_list args, int *nChar);
/**
 * SpecifierMapping - gets the suitable func for the specifier
 *@specifier: the specifier
 *@handler: the function for the spec
 *
 * Return: nothing
 */
typedef struct
{
	char specifier;
	SpecifierHandler handler;
} SpecifierMapping;

extern SpecifierMapping specifierMap[];

int _printf(const char *format, ...);
unsigned int digitCounter(int number);
char *numberConversion(unsigned int nDigit, int number);

void handleChar(va_list args, int *nChar);
void handleString(va_list args, int *nChar);
void handleInt(va_list args, int *nChar);
void handlePercent(va_list args, int *nChar);
void handleBinary(va_list args, int *nChar);
void handleOctal(va_list args, int *nChar);
void handleHex(va_list args, int *nChar);
void handlePointer(va_list args, int *nChar);
void handleReverse(va_list args, int *nChar);
void handlePrint_S(va_list args, int *nChar);
void handleRot13(va_list args, int *nChar);

#endif
