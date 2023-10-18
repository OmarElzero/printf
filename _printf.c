#include <stdarg.h>
#include <stdio.h>
#include <regex.h>
#include <string.h>

#define PRINT_CHAR(c) buffer[printed++] = c;
#define PRINT_STR(str) strcpy(buffer + printed, str); printed += strlen(str);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    int i, printed = 0;
    va_list list;
    char buffer[1024];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            // Replace spaces with tabs.
            regex_t regex;
            regcomp(&regex, " ", REG_EXTENDED);
            char *replaced = (char*)regex_replace(format + i, &regex, "\t", 0);
            if (replaced != NULL) {
                PRINT_STR(replaced);
                free(replaced);
            } else {
                PRINT_CHAR(format[i]);
            }
            regfree(&regex);

            if (printed == 1024)
            {
                fwrite(buffer, 1, printed, stdout);
                printed = 0;
            }
        }
        else
        {
            switch (format[i + 1])
            {
                case 'c':
                    PRINT_CHAR((char)va_arg(list, int));
                    break;
                case 's':
                    PRINT_STR(va_arg(list, char*));
                    break;
                case '%':
                    PRINT_CHAR('%');
                    break;
                default:
                    return (-1);
            }
            i++;
        }
    }

    fwrite(buffer, 1, printed, stdout);

    va_end(list);

    return (printed);
}
