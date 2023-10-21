#include "main.h"

/**
 *
 * _printf - printing anything we want
 * @format: the format strings
 *
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
		init_params(&params, tree);
		if (*p != '%')
		{
			omar += putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, tree);
		p = get_precision(p, &params, tree);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			omar += print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			omar += get_print_func(p, tree, &params);
	}
	putchar(BUF_FLUSH);
	va_end(tree);
	return (omar);/*end of the code*/
}
