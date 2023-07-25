#include "main.h"

/**
 * _printf - produces the output according to a format
 * @format: the character string composed of 0 or more directives
 *
 * Return: number of characters printed, excluding the null byte
 */

int _printf(const char *format, ...)
{
	va_list args;
	int total_chars = 0;
	int i;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			total_chars += print_arg(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			total_chars++;
		}
	}
	va_end(args);
	return (total_chars);
}

/**
 * print_arg - prints the argument according to the format specifier
 * @specifier: the format specifier
 * @args: the list of arguments
 *
 * Return: the number of characters printed
 */

int print_arg(char specifier, va_list args)
{
	switch (specifier)
	{
		case 's':
			return (print_string(args));
		case 'c':
			return (print_char(args));
		case '%':
			write(1, "%", 1);
			return (1);
		default:
			write(1, &specifier, 1);
			return (0);
	}
}

/**
 * _strlen - calculates the length
 * @s: a pointer used to access the memory address of the string passed
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
	{
		i++;
	}
	return (i);
}

/**
 * print_string - prints a string
 * @args: the argument list
 *
 * Return: number of characters printed
 */

int print_string(va_list args)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, _strlen(s));
	return (_strlen(s));
}

/**
 * print_char - prints a character
 * @args: the argument list containing the character
 *
 * Return: the number of characters printed (1)
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
