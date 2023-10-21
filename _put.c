#include "main.h"

/**
 * _my_puts - printing a strings with newlines
 * @tour: the strings ara about to print
 *
 * Return: void
 *
 */
int _my_puts(char *tour)
{
	char *a = tour;

	while (*tour)
		_my_putchar(*tour++);
	return (tour - a);
}

/**
 * _my_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and error no is set appropriately.
 */
int _my_putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
