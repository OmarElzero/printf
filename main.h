#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define CONVERT_H		0
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED	2

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define FIELD_BUF_SIZE 50
#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct parameters - parameters structing
 *
 * @unsign: flag if unsigned value appears
 *
 * @plus_flag: on if plus_flag specifing
 * @space_flag: on if hashtag_flag specifing
 * @hashtag_flag: on if _flag specifiing
 * @zero_flag: on if _flag specifiing
 * @minus_flag: on if _flag specifiing
 *
 * @width: field width specifiing
 * @precision: field precision specifiing
 *
 * @h_modifier: on if h_modifier is specifing
 * @l_modifier: on if l_modifier is specifiing
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _my_put.c module */
int _my_puts(char *tour);
int _my_putchar(int c);

/* print_functions.c module */
int printing_char(va_list tree, params_t *params);
int print_int_1(va_list tree, params_t *params);
int printed_string(va_list tree, params_t *params);
int print_percent02(va_list tree, params_t *params);
int print_co(va_list tree, params_t *params);

/* number.c module */
char *turn(long int num, int base, int flags, params_t *params);
int printing_unsigned(va_list tree, params_t *params);
int printing_address(va_list tree, params_t *params);

/* specifier.c module */
int (*geting_specifier(char *s))(va_list tree, params_t *params);
int gots_print_func(char *s, va_list tree, params_t *params);
int geting_my_flag(char *s, params_t *params);
int get_modifiers(char *s, params_t *params);
char *get_widths5(char *s, params_t *params, va_list ap);

/* convert_number.c module */
int my_print_to_hex(va_list tree, params_t *params);
int my_print_into_HEX(va_list tree, params_t *params);
int my_print_into_binary(va_list tree, params_t *params);
int my_print_to_octal(va_list tree, params_t *params);

/* simple_printers.c module */
int prints_from_too(char *start, char *stop, char *except);
int print_revw(va_list tree, params_t *params);
int print_rot1345(va_list tree, params_t *params);

/* print_number.c module */
int _is_digiting(int c);
int _strleng(char *s);
int print_my_number(char *tour, params_t *params);
int printing_number_right_shift(char *tour, params_t *params);
int printing_number_left_shift(char *tour, params_t *params);

/* params.c module */
void inite_params(params_t *params, va_list tree);

/* string_fields.c modoule */
char *get_precisions1(char *p, params_t *params, va_list tree);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif
