#include "main.h"

/**
 * prints_from_too - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int prints_from_too(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _my_putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_revw - printing strings in reverse
 * @tree: strings
 * @params: the parameters structing
 *
 * Return: numbers bytes printed
 */
int print_revw(va_list tree, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(tree, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _my_putchar(*str);
	}
	return (sum);
}

/**
 * print_rot1345 - printing strings in rot1345
 * @tree: strings
 * @params: the parameters structing
 *
 * Return: numbers of bytes printed
 */
int print_rot1345(va_list tree, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(tree, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _my_putchar(arr[index]);
		}
		else
			count += _my_putchar(a[i]);
		i++;
	}
	return (count);
}
