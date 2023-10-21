#include "main.h"

/**
 * inite_params - clears structing fields and reset buffers
 * @params: the parameters structing
 * @tree: the argument pointers
 *
 * Return: void
 */
void inite_params(params_t *params, va_list tree)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)tree;
}
