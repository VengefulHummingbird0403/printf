#include "main.h"

/**
 * _printf - produces the output according to a format
 * @format: the character string composed of 0 or more directives
 *
 * Return: number of characters printed, excluding the null byte
 */

int _printf(const char *format, ...)
{
	int total_chars = 0;
	int i;
	va_list args;
	char c;
	char *str;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);

	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			total_chars++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				/* This will handle %% */
				write(1, format, 1);
				total_chars++;
			}
			else if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				total_chars++;
			}
			else if (*format == 's')
			{
				str = va_arg(args, char*);

				write(1, str, strlen(str));
				total_chars += strlen(str);
			}
		}
	}
	va_end(args);
	return (total_chars);
}
