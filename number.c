#include "main.h"

/**
 * turn - converter function, a clone of omar
 * @num: numbers
 * @base: basic
 * @flags: argument flag
 * @params: paramater structing
 *
 * Return: string
 */
char *turn(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * printing_unsigned - printing unsigned integers number
 * @tree: argument pointers
 * @params: the parameters structing
 *
 * Return: bytes printed
 */
int printing_unsigned(va_list tree, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(tree, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(tree, unsigned int);
	else
		l = (unsigned int)va_arg(tree, unsigned int);
	params->unsign = 1;
	return (print_number(turn(l, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * printing_address - printing address
 * @tree: argument pointers
 * @params: the parameters structing
 *
 * Return: bytes printed
 */
int printing_address(va_list tree, params_t *params)
{
	unsigned long int n = va_arg(tree, unsigned long int);
	char *tour;

	if (!n)
		return (_puts("(nil)"));

	tour = turn(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--tour = 'x';
	*--tour = '0';
	return (print_number(tour, params));
}
