#include "main.h"

/**
 * handle_conv_c - print strings
 * @conv: - char to sperate ints
 * @list: - char to sperate ints
 * Return: int
 */
int handle_conv_c(struct struct_conversion *conv, va_list list)
{
	char *new, c;
	int direction, width, len;
	
	direction = 1;
	c = (char)va_arg(list, int);
	if (contains(conv->flags, '-'))
		direction = -1;
	width = conv->width > 1 ? conv->width : 1;
	new = malloc(sizeof(char) * width);
	if (!new)
		exit(1);
	len = assign_width(new, &c, width, 1, direction);
	free(new);
	return len;
}


/**
 * handle_conv_s - print strings
 * @conv: - char to sperate ints
 * @list: - char to sperate ints
 * Return: int
 */
int handle_conv_s(struct struct_conversion *conv, va_list list)
{
	char nil[] = "(null)";
	char *new, *s;
	int direction, width, len;
	
	direction = 1;
	s = va_arg(list, char *);
	if (s == NULL || *s < 0)
		s = nil;
	if (contains(conv->flags, '-'))
		direction = -1;
	len = _strlen(s);
	width = conv->width > len ? conv->width : len;
	new = malloc(sizeof(char) * width);
	if (!new)
		exit(1);
	len = assign_width(new, s, width, len, direction);
	free(new);
	return len;
}

/**
 * handle_conv_percent - print strings
 * @conv: - char to sperate ints
 * @list: - char to sperate ints
 * Return: int
 */
int handle_conv_percent(__attribute__((unused)) struct struct_conversion *conv, __attribute__((unused)) va_list list)
{
	char percent = '%';
	return _putstr(&percent, 1);
}


/**
 * handle_conv_i - print strings
 * @conv: - char to sperate ints
 * @list: - char to sperate ints
 * Return: int
 */
int handle_conv_i(struct struct_conversion *conv, va_list list)
{
	char *new_all, *new_num;
	int direction, width, len, num, sign;
	
	sign = 0;
	direction = 1;
	num = (int)va_arg(list, int);
	len = _intlen(num);
	if (num < 0 || contains(conv->flags, '+'))
	{
		len++;
		sign = 1;
	}
	if (contains(conv->flags, '-'))
		direction = -1;
	if (contains(conv->flags, '.') && conv->p >= len)
		len = conv->p + sign;
	new_num = malloc(sizeof(char) * len);
	if (!new_num)
		exit(1);
	int_to_str(num, new_num, len, sign);
	width = conv->width > len ? conv->width : len;
	new_all = malloc(sizeof(char) * width);
	if (!new_all)
	{
		free(new_num);
		exit(1);
	}
	len = assign_width(new_all, new_num, width, len, direction);
	free(new_num);
	free(new_all);
	return len;
}
