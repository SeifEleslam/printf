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
	char nil[] = "(nill)";
	char *new, *s;
	int direction, width, len;
	
	direction = 1;
	s = va_arg(list, char *);
	if (s == NULL)
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
