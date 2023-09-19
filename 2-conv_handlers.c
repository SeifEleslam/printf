#include "main.h"
/**
 * handle_conv_r - prints an int
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
	return (len);
}


/**
 * handle_conv_R - prints an int
 * @conv: va_list
 * @list: va_list
 * Return: int
 */
int handle_conv_R(__attribute__((unused)) struct struct_conversion *conv, va_list list)
{
	char nil[] = "(null)";
	char *new, *s;
	int len, i;

	s = (char *)va_arg(list, char *);
	if (!s || *s < 0)
		s = nil;
	len = _strlen(s);

	for (i = 0; i < len; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
			s[i] += 13;
		else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
			s[i] -= 13;
	}
	len = _putstr(s, len);
	return (len);
}
