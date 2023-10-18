#include "main.h"

/**
 * print_buf - prints buffer
 * @buf: buffers pointers
 * @nbuf: number of bytess to printed
 * Return: number of bytes printed.
 */
int print_buf(char *buf, unsigned int nbuf)
{
						return (write(1, buf, nbuf));
}
