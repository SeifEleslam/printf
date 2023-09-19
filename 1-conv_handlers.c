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
    uint_to_str(num, new_num, len, 10);
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
    uint_to_str(num, new_num, len, 8);
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
