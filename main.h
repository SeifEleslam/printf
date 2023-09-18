#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

struct struct_conversion
{
  char conv;
  char *flags;
  int p;
  int width;
} struct_conversion;

typedef int (*conv_actions)(struct struct_conversion *, va_list);

int _printf(const char *format, ...);
void define_consts(conv_actions *conversions, char *flags);
void init_conv(struct struct_conversion *conv, char *conv_flag);
void valid_exp(char *s, conv_actions *conversions, char *flags, struct struct_conversion *conv);
int to_int(char **s);

int _putstr(char *s, unsigned int n);
int contains(char *s, char c);
int _strlen(char *s);
void _strcp(char *to, char *from);

int assign_width(char *new, char *s, int total_width, int width, int direction);
int assign_width_pos(char *new, char *s, int total_width, int width);
int assign_width_neg(char *new, char *s, int total_width, int width);

int handle_conv_c(struct struct_conversion *conv, va_list list);
int handle_conv_s(struct struct_conversion *conv, va_list list);

#endif
