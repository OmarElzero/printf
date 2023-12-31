#include "main.h"

/**
 * geting_specifier - finding the formating functions
 * @s: the format strings
 *
 * Return: the number of byte which are printed
 */
int (*geting_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", printing_char},
		{"d", print_int_1},
		{"i", print_int_1},
		{"s", printed_string},
		{"%", print_percent02},
		{"b", my_print_into_binary},
		{"o", my_print_to_octal},
		{"u", printing_unsigned},
		{"x", my_print_to_hex},
		{"X", my_print_into_HEX},
		{"p", printing_address},
		{"S", print_co},
		{"r", print_revw},
		{"R", print_rot1345},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * gots_print_func - finding the formats function
 * @s: the format strings
 * @tree: argument pointers
 * @params: the parameters struction
 *
 * Return: the numbers of bytes which are printed
 */
int gots_print_func(char *s, va_list tree, params_t *params)
{
	int (*f)(va_list, params_t *) = geting_specifier(s);

	if (f)
		return (f(tree, params));
	return (0);
}

/**
 * geting_my_flag - finds the flag function
 * @s: the format strings
 * @params: the parameters struction
 *
 * Return: if flags was valids
 */
int geting_my_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifiers - finding the modifiers function
 * @s: the format strings
 * @params: the parameters struction
 *
 * Return: if modifiers was valids
 */
int get_modifiers(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_widths5 - geting the widths5 from the formats strings
 * @s: the format strings
 * @params: the parameters struction
 * @tree: the argument pointers
 *
 * Return: new pointers
 */
char *get_widths5(char *s, params_t *params, va_list tree)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(tree, int);
		s++;
	}
	else
	{
		while (_is_digiting(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}
