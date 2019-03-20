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
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

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
			if (find_value(format[i]) == NULL)
			{
				_putchar('%');
				_putchar(format[i]);
				chrcounter = chrcounter + 2;
			}
			else
			{
				chrcounter += (find_value(format[i]))(args);
			}
			i++;
		}
		if (format[i] != '\0' && format[i] != '%')
		{
			_putchar(format[i]);
			chrcounter++;
			i++;
		}
	}
	return (chrcounter);
}
