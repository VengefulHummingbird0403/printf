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
			print_arg(args, format, i, &total_chars);
		}
		else
		{
			total_chars += _putchar(format[i]);
		}
	}
	va_end(args);
	return (total_chars);
}

/**
 * print_arg - prints the argument according to the format specifier
 * @format: the format string
 * @args: the list of arguments
 * @i: iterator
 * @char_count: counting printed values
 *
 * Return: nothing
 */

void print_arg(va_list args, const char *format, int i, int *char_count)
{
	char par;
	const char *par_str;
	int int_par;

	switch (format[i])
	{
		case 'c':
			par = va_arg(args, int);
			(*char_count) += _putchar(par);
			break;
		case 's':
			par_str = va_arg(args, const char *);
			if (par_str == NULL)
			{
				(*char_count) += _puts("(null)");
				return;
			}
			(*char_count) += _puts(par_str);
			break;
		case '%':
			(*char_count) += _putchar('%');
			break;
		case 'd':
			int_par = va_arg(args, int);
			(*char_count) += print_num(int_par);
			break;
		case 'i':
			int_par = va_arg(args, int);
			(*char_count) += print_num(int_par);
			break;
		case 'b':
			int_par = va_arg(args, int);
			(*char_count) += print_binary(int_par);
			break;
		default:
			(*char_count) += _putchar('%');
			(*char_count) += _putchar(format[i]);
	}
}

/**
 * _putchar - prints character
 * @c: character to be printed
 *
 * Return: the number of characters printed to standard output
 * i.e 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * _puts - custom puts
 * @str: pointer to array of characters (string)
 * Return: number of characters printed
 */

int _puts(const char *str)
{
	int i = 0;

	for (; str[i] != '\0'; i++)
		_putchar(str[i]);
	/* _putchar('\n'); */
	return (i);
}

