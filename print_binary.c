#include "main.h"

/**
 * print_binary - prints integers in binary format
 * @n: number to print
 * Return: number of characters printed
 */
int print_binary(int n)
{
	int count = 0;
	int i, msb;

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	/* Find the most significant bit (MSB) */
	msb = sizeof(int) * 8 - 1;

	while ((n & (1 << msb)) == 0)
	{
		msb--;
	}

	/* Print binary digits */
	for (i = msb; i >= 0; i--)
	{
		int bit = (n >> i) & 1;

		count += _putchar('0' + bit);
	}

	return (count);
}
