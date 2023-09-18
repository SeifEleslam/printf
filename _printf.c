#include "main.h"

/**
 * _printf - print strings
 * @format: - char to sperate ints
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i, sum;
	conv_actions conversions['z' - '%'], func;
	char flags['/' - ' '], conv_flag[5], *s;
	struct struct_conversion conv;
	va_list list;
	
	if (!format)
		return -1;
	sum = 0;
	s = (char *)format;
	define_consts(conversions, flags);
	va_start(list, format);
	for (i = 0; s[i] != '\0'; i++)
	{
	init_conv(&conv, conv_flag);
	if (s[i] == '%')
	{
		valid_exp(s + i + 1, conversions, flags, &conv);
		if (conv.conv != '\0')
		{
			if (conv.conv - '%' >= 0 && conversions[conv.conv - '%'])
			{
				sum += _putstr(s, i), i++;
				while (s[i] != conv.conv)
					i++;
				s += i + 1;
				i = -1;
				func = conversions[conv.conv - '%'];
				sum += func(&conv, list);
			}
		}
		else
		{
			_putstr(s, i);
			return (-1);
		}
	}
	}
	sum = sum + _putstr(s, i);
	va_end(list);
	return sum;
}

/**
 * define_consts - print strings
 * @conversions: - char to sperate ints
 * @flags: - char to sperate ints
 */
void define_consts(conv_actions *conversions, char *flags)
{
	int i;

	for (i = 0; i < 'z' - '%'; i++)
		conversions[i] = NULL;
	for (i = 0; i < '/' - ' '; i++)
		flags[i] = '\0';
	
	conversions['c' - '%'] = handle_conv_c;
	conversions['s' - '%'] = handle_conv_s;
	conversions['%' - '%'] = handle_conv_percent;
	/* conversions['i' - '%'] = 'i';
	 * conversions['d' - '%'] = 'd';
	 */
	flags['.' - ' '] = '.';
	flags['#' - ' '] = '#';
	flags[' ' - ' '] = ' ';
	flags['-' - ' '] = '-';
	flags['+' - ' '] = '+';
}

/**
 * valid_exp - print strings
 * @s: - char to sperate ints
 * @conversions: - char to sperate ints
 * @flags: - char to sperate ints
 * @conv: - char to sperate ints
 */
void valid_exp(char *s, conv_actions *conversions, char *flags, struct struct_conversion *conv)
{
	char conv_flags[5] = "\0\0\0\0\0", *local_s;
	int i, flag_i, p, num;
	
	local_s = s;
	flag_i = 0, p = 0;
	for (i = 0; local_s[i] != '\0'; i++)
	{
		if (local_s[i] - ' ' >= 0 && local_s[i] - ' ' <= '.' - ' ' && flags[local_s[i] - ' ']
			&& p == 0 && (conv->width == 0 || local_s[i] == '.'))
		{
			if (local_s[i] == '.')
				p++;
			if (contains(conv_flags, local_s[i]) == 0)
			{
			conv_flags[flag_i] = local_s[i];
			flag_i++;
			}
		}
		else if (local_s[i] >= '0' && local_s[i] <= '9' &&
			((conv->width == 0 && p == 0) || (conv->p == 0 && p == 1)))
		{
			local_s += i;
			i = -1;
			num = to_int(&local_s);
			if (conv->width == 0 && p == 0)
				conv->width = num;
			else
				conv->p = num;
		}
		else
		{
			conv->conv = local_s[i];
			_strcp(conv->flags, conv_flags);
			return;
		}
	}
}

/**
 * init_conv - print strings
 * @conv: - char to sperate ints
 * @conv_flag: - char to sperate ints
 */
void init_conv(struct struct_conversion *conv, char *conv_flag)
{
	conv->conv = '\0';
	conv->flags = conv_flag;
	conv->p = 0;
	conv->width = 0;
}

/**
 * to_int - print strings
 * @s: - char** to sperate ints
 * Return: int
 */
int to_int(char **s)
{
	int i, val;
	
	val = 0;
	for (i = 0; (*s)[i] >= '0' && (*s)[i] <= '9'; i++)
	{
		val *= 10;
		val += (*s)[i] - '0';
	}
	*s += i;
	return (val);
}
