#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int _printf(const char *format, ...);
void print_arg(va_list args, const char *format, int i, int *char_count);
int _putchar(char c);
int _puts(const char *str);
#endif
