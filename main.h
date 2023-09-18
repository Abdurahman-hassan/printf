#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

char *_strchr(const char *s, int c);
int _strlen(char *str);
char *_itoa(int value, char *str);
char *_toUpper(char *c);
int reverse_string_with_len(char *buffer, const char *str);
void reverse_string_without_len(char *start, char *end);
int handle_basic_formats(char *buffer, const char specifier, va_list args);
int handle_integer_and_binary(char *buffer, const char specifier, va_list args);
int handle_octal_and_hexa(char *buffer, const char specifier, va_list args);
int _printf(const char *format, ...);

#endif
