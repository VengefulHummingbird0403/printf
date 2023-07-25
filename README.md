# Custom `printf` function - ALX Project
## Team Members
- Humphrey Kinoti
- Add your name

## Table of Content
+ [Description](#description)
+ [Prototype](#prototype)
+ [Return Value](#return-value)
+ [Supported Conversion Specifiers](#supported-conversion-specifiers)
+ [Instructions](#instructions)
+ [Example Usage](#example-usage)
+ [Note](#note)
+ [Collaborators](#collaborators)

## Description

This project aims to create a custom implementation of the `printf` function in C. The function will produce output according to a given format string, which can include conversion specifiers for characters, strings, and the percent symbol. The function will write the output to the standard output stream (stdout).

## Prototype

```c
int _printf(const char *format, ...);
```

## Return Value

The `_printf` function will return the number of characters printed (excluding the null byte used to end output to strings).

## Supported Conversion Specifiers

The custom `printf` function will handle the following conversion specifiers:

- `%c`: Print a single character.
- `%s`: Print a null-terminated string.
- `%%`: Print a percent symbol.

Additionally, the following conversion specifiers for integers will also be handled:

- `%d`: Print a signed integer.
- `%i`: Print a signed integer.

## Instructions

1. Clone the repository from GitHub: [printf](https://github.com/VengefulHummingbird0403/printf.git).

2. Implement the custom `_printf` function in the provided source files. You are required to handle the specified conversion specifiers: `%c`, `%s`, `%%`, `%d`, and `%i`

3. Test your implementation with various test cases to ensure correctness and accuracy.

## Example Usage

```c
#include "alx.h"

int main(void)
{
    int len;

    len = _printf("Hello, %s!\n", "world");
    _printf("The number of characters printed is: %d\n", len);

    _printf("%c\n", 'A');
    _printf("%%\n");

    return (0);
}

