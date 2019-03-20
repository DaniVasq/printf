#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list chr);
int print_str(va_list s);
int (*find_value(char n))(va_list);
int print_percent(va_list __attribute__((unused)) percent);
/**
 *
 *
 *
 *
*/

typedef struct lo
{
	char *chr;
	int (*f)(va_list);
} lo_p;

#endif
