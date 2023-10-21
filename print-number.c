#include "main.h"

/**
 * _is_digiting - checking if the character is digit
 * @c: the character to checks
 *
 * Return: 1 if digits, 0 otherwise
 */
int _is_digiting(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strleng - returns the lengths of a string
 * @s: the strings whose lengths to check
 *
 * Return: integers lengths of string
 */
int _strleng(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_my_number - printing a numbers with options
 * @tour: the base number as a string
 * @params: the parameter structing
 *
 * Return: chars printed
 */
int print_my_number(char *tour, params_t *params)
{
	unsigned int i = _strlen(tour);
	int neg = (!params->unsign && *tour == '-');

	if (!params->precision && *tour == '0' && !tour[1])
		tour = "";
	if (neg)
	{
		tour++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--tour = '0';
	if (neg)
		*--tour = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(tour, params));
	else
		return (print_number_left_shift(tour, params));
}

/**
 * printing_number_right_shift - printing a numbers with options
 * @tour: the base numbers as a strings
 * @params: the parameter structing
 *
 * Return: chars printed
 */
int printing_number_right_shift(char *tour, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(tour);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *tour == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		tour++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(tour);
	return (n);
}

/**
 * printing_number_left_shift - prints a number with options
 * @tour: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int printing_number_left_shift(char *tour, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(tour);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *tour == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		tour++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(tour);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
