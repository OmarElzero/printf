#include "main.h"

/**
 * _printf - printing anything we want
 * @format: the format strings
 * Return: numbers of bytes printed
 */

int _printf(const char *format, ...)
{
	int omar = 0;
	va_list tree;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(tree, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		inite_params(&params, tree);
		if (*p != '%')
		{
			omar += _my_putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (geting_my_flag(p, &params))
		{
			p++;
		}
		p = get_widths5(p, &params, tree);
		p = get_precisions1(p, &params, tree);
		if (get_modifiers(p, &params))
			p++;
		if (!geting_specifier(p))
			omar += prints_from_too(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			omar += gots_print_func(p, tree, &params);
	}
	_my_putchar(BUF_FLUSH);
	va_end(tree);
	return (omar);/*end of the code*/
}
