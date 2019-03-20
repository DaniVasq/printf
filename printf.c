#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to format.
 * @format: argument
 * Return: Number of printed characters (chrcounter).
*/

int _printf(const char *format, ...)
{
	va_list args;
	int chrcounter = 0, i = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		while ((format[i] != '%') && (format[i + 1] != '\0'))
		{
			_putchar(format[i]);
			i++;
			chrcounter++;
		}
		if (format[i] == '%')
		{
			i++;
			chrcounter += (find_value(format[i]))(args);
			i++;
		}
		_putchar(format[i]);
		i++;
	}
	return (chrcounter);
}
