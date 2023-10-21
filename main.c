#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry pointing
 *
 * Return: Always 0
 *
 */
int main(void)
{
	int len;
	int my_lenth2;
	unsigned int ui;
	void *addr;

	lenth1 = _printf("Let's try to printf a simple sentence.\n");
	my_lenth2 = printf("Let's try to printf a simple sentence.\n");
ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", lenth1, lenth1);
	printf("Length:[%d, %i]\n", my_lenth2, my_lenth2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	lenth1 = _printf("Percent:[%%]\n");
	my_lenth2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", lenth1);
	printf("Len:[%d]\n", my_lenth2);
	 _printf("Unknown:[%r]\n");
	return (0);
}
