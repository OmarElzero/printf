#include "main.h"
/**
 * prinlunt - prints as long as an  unsigned integering number
 * @arguments: number to printers
 * @buf: buffer pointerss
 * @ibuf: index for buffers pointers
 * Return: number of charss printed.
 */
int prinlunt(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned long int int_in, int_temp, i, div;

			int_in = va_arg(arguments, unsigned long int);
	int_temp = int_in;
		div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i);
}
