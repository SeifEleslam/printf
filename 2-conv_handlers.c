#include "main.h"
/**
 * handle_conv_S - prints an int
 * @conv: va_list
 * @list: va_list
 * Return: int
 */
int handle_conv_r(__attribute__((unused)) struct struct_conversion *conv, va_list list)
{
	char nil[] = "(null)";
	char *new, *s;
	int len, i;
	
	s = (char *)va_arg(list, char *);
	if (!s || *s < 0)
		s = nil;
	len = _strlen(s);
	new = malloc(sizeof(char) * len);
	if (!new)
		exit(1);
	for (i = len - 1; i >= 0; i--)
		new[len - i - 1] = s[i];
	len = _putstr(new, len);
	free(new);
	return len;
}
