#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

char *_strchr(const char *s, int c);
int _strlen(char *str);
char *_itoa(int value, char *str);
char *_utoa(unsigned long value, char *str, int base);
char *_toUpper(char *c);
char *_rot13(char *c);

int reverse_string_with_len(char *buffer, char *str);
void reverse_string_without_len(char *start, char *end);
int handle_basic_formats(char *buffer, const char specifier, va_list args);
int handle_integer_binary(char *buffer, const char specifier, va_list args);
int handle_octal_hexa(char *buffer, const char specifier, va_list args);
int handle_unsigned_pointer(char *buffer, const char specifier, va_list args);
int process_format(const char *format, int *i, va_list args, char *buffer);
int handle_custom_formats(char *buffer, const char specifier, va_list args);
int handle_special_string(char *buffer, const char *str);
int _printf(const char *format, ...);

#endif
