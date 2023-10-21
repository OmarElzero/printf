#include "main.h"
#include "convert.h"
/**
 * printing_char - printing characters
 * @tree: argument pointering
 * @params: the parameters structing
 *
 * Return: numbers of chars printed
 */
int printing_char(va_list tree, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(tree, int);

	if (params->minus_flag)
		sum += putchar(ch);
	while (pad++ < params->width)
		sum += putchar(pad_char);
	if (!params->minus_flag)
		sum += putchar(ch);
	return (sum);
}

/**
 * print_int_1 - printing integers
 * @tree: argument pointers
 * @params: the parameters structing
 *
 * Return: number chars printed
 */
int print_int_1(va_list tree, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(tree, long);
	else if (params->h_modifier)
		l = (short int)va_arg(tree, int);
	else
		l = (int)va_arg(tree, int);
	return (print_my_number(convert(l, 10, 0, params), params));
}

/**
 * printed_string - printing string
 * @tree: argument pointers
 * @params: the parameters structing
 *
 * Return: numbers chars printed
 */
int printed_string(va_list tree, params_t *params)
{
	char *tour = va_arg(tree, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!tour))
		case 1:
			tour = NULL_STRING;

	j = pad = _strleng(tour);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += putchar(*tour++);
		else
			sum += puts(tour);
	}
	while (j++ < params->width)
		sum += putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += putchar(*tour++);
		else
			sum += puts(tour);
	}
	return (sum);
}

/**
 * print_percent02 - prints string
 * @tree: argument pointers
 * @params: the parameters structing
 *
 * Return: numbers of chars printed
 */
int print_percent02(va_list tree, params_t *params)
{
	(void)tree;
	(void)params;
	return (putchar('%'));
}

/**
 * print_co - custom formating specifiers
 * @tree: argument pointers
 * @params: the parameters structing
 *
 * Return: numbers of chars printed
 */
int print_co(va_list tree, params_t *params)
{
	char *tour = va_arg(tree, char *);
	char *hex;
	int sum = 0;

	if ((int)(!tour))
		return (puts(NULL_STRING));
	for (; *tour; tour++)
	{
		if ((*tour > 0 && *tour < 32) || *tour >= 127)
		{
			sum += putchar('\\');
			sum += putchar('x');
			hex =(void *) convert(&tour, 16, 0, params);
			if (!hex[1])
				sum += putchar('0');
			sum += puts(hex);
		}
		else
		{
			sum += putchar(*tour);
		}
	}
	return (sum);
}
