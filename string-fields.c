#include "main.h"

/**
 * get_precisions1 - geting the precisions1 from the format strings
 * @p: the format strings
 * @params: the parameters structing
 * @tree: the argument pointers
 *
 * Return: new pointer
 */
char *get_precisions1(char *p, params_t *params, va_list tree)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(tree, int);
		p++;
	}
	else
	{
		while (_is_digiting(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
