#include "main.h"
#include "convert.h"
/**
 * my_print_to_hex - printing unsigned hex number in lowercases
 * @tree: the argument pointers
 * @params: the parameters structing
 *
 * Return: byte printed
 */
int my_print_to_hex(va_list tree, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *tour;

	if (params->l_modifier)
		l = (unsigned long)va_arg(tree, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(tree, unsigned int);
	else
		l = (unsigned int)va_arg(tree, unsigned int);

	tour = (char *)(void *)convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--tour = 'x';
		*--tour = '0';
	}
	params->unsign = 1;
	return (c += print_my_number(tour, params));
}

/**
 * my_print_into_HEX - prints unsigned hex numbers in uppercase
 * @tree: the argument pointers
 * @params: the parameters structing
 *
 * Return: bytes printed
 */
int my_print_into_HEX(va_list tree, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *tour;

	if (params->l_modifier)
		l = (unsigned long)va_arg(tree, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(tree, unsigned int);
	else
		l = (unsigned int)va_arg(tree, unsigned int);

	tour =(char *) convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--tour = 'X';
		*--tour = '0';
	}
	params->unsign = 1;
	return (c += print_my_number(tour, params));
}
/**
 * my_print_into_binary - prints unsigned binary numbers
 * @tree: the arguments pointers
 * @params: the parameters which are struct
 *
 * Return: bytes printed
 */
int my_print_into_binary(va_list tree, params_t *params)
{
	unsigned int n = va_arg(tree, unsigned int);
	char *tour = (char *) convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--tour = '0';
	params->unsign = 1;
	return (c += print_my_number(tour, params));
}

/**
 * my_print_to_octal - printing unsigned octal numbers
 * @tree: the argument pointers
 * @params: the parameters which are structing
 *
 * Return: bytes printed
 */
int my_print_to_octal(va_list tree, params_t *params)
{
	unsigned long l;
	char *tour;
	int c = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(tree, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(tree, unsigned int);
	else
		l = (unsigned int)va_arg(tree, unsigned int);
	tour = (char *) convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--tour = '0';
	params->unsign = 1;
	return (c += print_my_number(tour, params));
}
