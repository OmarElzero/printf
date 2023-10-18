#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...) {
   int count = 0;
   va_list args;
   va_start(args, format);

   for (const char *p = format; *p; ++p) {
       if (*p != '%') {
           putchar(*p);
           count++;
       } else {
           p++;
           switch (*p) {
               case 'c': {
                   char c = (char) va_arg(args, int);
                   putchar(c);
                   count++;
                   break;
               }
               case 's': {
                   const char *s = va_arg(args, const char *);
                   for (const char *sp = s; *sp; ++sp) {
                       putchar(*sp);
                       count++;
                   }
                   break;
               }
               case '%': {
                   putchar('%');
                   count++;
                   break;
               }
               default: {
                   break;
               }
           }
       }
   }

   va_end(args);
   return count;
}
