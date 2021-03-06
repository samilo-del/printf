#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Print according to a format.
 *
 * @format: Arguments.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j, count = 0;
	print form[] = {{" %", printspace}, {"c", printchar}, {"%", printporcent},
		{"s", printstring}, {"i", printint}, {"d", printint}, {"b", printbinary},
		{"R", printrot13},  {"u", printuint},
		{"X", printhexaMAY}, {"o", printoctal}, {"x", printhexaMIN}, {NULL, NULL}};
	if (!format || (format[i] == '%' && !format[i + 1]))
		return (-1);
	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			_putchar(format[i++]);
		else
		{
			j = 0;
			while (form[j].c != '\0')
			{
				if (format[i + 1] == form[j].c[0] && format[i + 2] == form[j].c[1]
					&& format[i + 2] != '\0')
				{
					count += form[j].f(args);
					i += 3;
					break;
				} else if (format[i + 1] == form[j].c[0])
				{
					count += form[j].f(args);
					i += 2;
					break;
				} else if (format[i + 1] != form[j].c[0] && j >= 12)
				{
					_putchar('%');
					i++;
					break;
				} j++;
			}
		}
	} va_end(args);
	return (i + count);
}
