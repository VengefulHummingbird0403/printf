#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int _printf(const char *format, ...);
int print_arg(char specifier, va_list args);
int print_char(va_list args);
int print_string(va_list args);
#endif
