#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Buffer handling functions */
int handle_buffer(char *buffer, int *buffer_index);
int process_string(const char *format, char *buffer,
		va_list arg, int *total_printed);
int handle_remaining_buffer(char *buffer, int buffer_index);

/* Flag handling functions */
char handle_flags(const char *format, int *i);
int handle_width(int *i, char *format);
int identify_specifier(const char *format, int *i,
		va_list args, char *buffer, char flag, int *buff_index, int *total_printed);
int process_format(const char *format, int *i, va_list args, char *buffer,
		int *buffer_index, int *total_printed);

/* Utility functions */
char *_strchr(const char *s, int c);
int _strlen(char *str);
char *_itoa(int value, char *str, char flag);
char *_utoa_core(unsigned long value, char *str, int base);
char *_utoa_format(char *str, unsigned long value, int base, char flag);
char *_utoa(unsigned long value, char *str, int base, char flag);
char *_toUpper(char *c);
char *_rot13(char *c);
int reverse_string_with_len(char *buffer, char *str);
void reverse_string_without_len(char *start, char *end);

/* Format handling functions */
int handle_basic_formats(char *buffer, const char specifier, va_list args,
		int *buff_index, int *total_printed);
int handle_custom_formats(char *buffer, const char specifier, va_list args);
int handle_integer_binary(char *buffer, const char specifier,
		va_list args, char flag);
int handle_octal_hexa(char *buffer, const char specifier,
		va_list args, char flag);
int handle_unsigned_pointer(char *buffer, const char specifier,
		va_list args, char flag);
int handle_special_string(char *buffer, const char specifier,
		va_list args, char flag);
int print_charachter(char *buffer, va_list args);
int print_string(va_list args, char *buffer, int *buffer_index,
		int *total_printed);

/* Main printf function */
int _printf(const char *format, ...);

#endif
