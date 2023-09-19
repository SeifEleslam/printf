#include "main.h"

/**
 * handle_conv_u - prints an int
 * @conv: va_list
 * @list: va_list
 * Return: int
 */
int handle_conv_u(struct struct_conversion *conv, va_list list)
{
	char *new_all, *new_num;
	int direction, width, len;
	unsigned int num;
	
	direction = 1;
	num = (unsigned int)va_arg(list, unsigned int);
	len = _uintlen(num, 10);
	if (contains(conv->flags, '-'))
		direction = -1;
	if (contains(conv->flags, '.'))
		len++;
	if (contains(conv->flags, '.') && conv->p > len)
		len = conv->p;
	new_num = malloc(sizeof(char) * len);
	if (!new_num)
		exit(1);
	uint_to_str(num, new_num, len, 10, 0);
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


/**
 * handle_conv_o - prints an int
 * @conv: va_list
 * @list: va_list
 * Return: int
 */
int handle_conv_o(struct struct_conversion *conv, va_list list)
{
	char *new_all, *new_num;
	int direction, width, len;
	unsigned int num;
	
	direction = 1;
	num = (unsigned int)va_arg(list, unsigned int);
	len = _uintlen(num, 8);
	if (contains(conv->flags, '-'))
		direction = -1;
	if (contains(conv->flags, '#') && num > 0)
		len++;
	if (contains(conv->flags, '.') && conv->p > len)
		len = conv->p;
	new_num = malloc(sizeof(char) * len);
	if (!new_num)
		exit(1);
	uint_to_str(num, new_num, len, 8, 0);
	if (contains(conv->flags, '#') && num > 0)
		new_num[0] = '0';
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


/**
 * handle_conv_x - prints an int
 * @conv: va_list
 * @list: va_list
 * Return: int
 */
int handle_conv_x(struct struct_conversion *conv, va_list list)
{
	char *new_all, *new_num;
	int direction, width, len;
	unsigned int num;
	
	direction = 1;
	num = (unsigned int)va_arg(list, unsigned int);
	len = _uintlen(num, 16);
	if (contains(conv->flags, '-'))
		direction = -1;
	if (contains(conv->flags, '.') && conv->p > len)
		len = conv->p;
	if (contains(conv->flags, '#') && num > 0)
		len += 2;
	new_num = malloc(sizeof(char) * len);
	if (!new_num)
		exit(1);
	uint_to_str(num, new_num, len, 16, conv->conv == 'X' ? 1 : 0);
	if (contains(conv->flags, '#') && num > 0)
		new_num[0] = '0', new_num[1] = 'x';
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

/**
 * handle_conv_S - prints an int
 * @conv: va_list
 * @list: va_list
 * Return: int
 */
int handle_conv_S(__attribute__((unused)) struct struct_conversion *conv, va_list list)
{
	char nil[] = "(null)";
	char *new, *s;
	int len, i, l;
	
	s = (char *)va_arg(list, char *);
	if (!s || *s < 0)
		s = nil;
	
	len = _strlen(s);
	l = len;
	for (i = 0; i < l; i++)
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
			len += 3;
	
	new = malloc(sizeof(char) * len);
	if (!new)
		exit(1);
	l = 0;
	for (i = 0; i < len; i++)
	{
		if ((s[l] > 0 && s[l] < 32) || s[l] >= 127)
		{
			new[i] = '\\', new[i + 1] = 'x';
			new[i + 2] = (s[l] / 16) >= 10 ? (s[l] / 16 - 10 + 'A') : (s[l] / 16 + '0');
			new[i + 3] = (s[l] % 16) >= 10 ? (s[l] % 16 - 10 + 'A') : (s[l] % 16 + '0');
			i += 3;
			l++;
		}
		else
			new[i] = s[l], l++;
	}
	len = _putstr(new, len);
	free(new);
	return len;
}


/**
 * handle_conv_p - prints an int
 * @conv: va_list
 * @list: va_list
 * Return: int
 */
int handle_conv_p(struct struct_conversion *conv, va_list list)
{
	char *new_all, new_num[15], nil[] = "(nil)";
	int direction, width, len;
	unsigned long int num;
	
	direction = 1, len = 2;
	num = (unsigned long int)va_arg(list, unsigned long int);
	if (contains(conv->flags, '-'))
		direction = -1;
	
	if (num)
	{
		len += _uintlen(num, 16);
		uint_to_str(num, new_num, len, 16, 0);
		new_num[0] = '0', new_num[1] = 'x';
	}
	else
		len = 5, _strcp(new_num, nil);
	width = conv->width > len ? conv->width : len;
	new_all = malloc(sizeof(char) * width);
	if (!new_all)
		exit(1);
	len = assign_width(new_all, new_num, width, len, direction);
	free(new_all);
	return len;
}

