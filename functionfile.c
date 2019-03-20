#include <stdio.h>
#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * _putchar - writes the character c to stdout.
 * @c: The character to print.
 * Return: Write.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints an char.
 * @chr: va_list to recieve.
 * Return: Number of printed characters, Always (1).
 */
int print_char(va_list chr)
{
	char b = (char)(va_arg(chr, int));

	_putchar(b);
	return (1);
}

/**
 * print_str - Function that prints a string.
 * @s: va_list to recieve.
 * Return: Number of printed characters less 1 (without '\0')
*/

int print_str(va_list s)
{
	int i;
	char *str = va_arg(s, char *);

	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
		}
	}
	else
	{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		return (6);
	}
	return (i);
}

/**
 * find_value - function that will find the necessary function to process n.
 * @n: Character to be operated.
 * Return: The necessary function to process n.
*/

int (*find_value(char n))(va_list)
{
	int i = 0;

	lo_p ftr[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{NULL, NULL}
	};

	while (i <= 2)
	{
		if (n == *(ftr[i].chr))
			return (ftr[i].f);
	i++;
	}
	return (NULL);
}

/**
 * print_percent - Function to print a '%'.
 * @percent: va_list to recieve.
 * Return: Number of printed characters, always (1).
 */

int print_percent(va_list __attribute__((unused)) percent)
{
	_putchar('%');
	return (1);
}
