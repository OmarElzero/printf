#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 *
 */
int _printf(const char *format, ...)
{
    int i, printed = 0;
    va_list list;

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            printed++;
        }
        else
        {
            switch (format[i + 1])
            {
                case 'c':
                    putchar((char)va_arg(list, int));
                    printed++;
                    break;
                case 's':
                    fputs(va_arg(list, char*), stdout);
                    printed += strlen(va_arg(list, char*));
                    break;
                case '%':
                    putchar('%');
                    printed++;
                    break;
                default:
                    return (-1);
            }
            i++;
        }
    }

    va_end(list);

    return (printed);
}
