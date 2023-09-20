#include "main.h"

/**
 * _utoa_core - Convert an unsigned long value to its string representation.
 * This function is a helper function to break down the conversion task.
 *
 * @value: The number to convert.
 * @str: The buffer to store the converted string.
 * @base: The base for conversion (2 for binary, 8 for octal, 16 for hex).
 * Return: Pointer to the converted string.
 */
char *_utoa_core(unsigned long value, char *str, int base)
{
	char allCharHex[] = "0123456789abcdef";
	char *start = str;
	char *end = str;
	unsigned long original_value = value;

	if (original_value == 0)
	{
		*str++ = '0';
		*str = '\0';
		return (start);
	}
	/*conveerting the value acording to given base*/
	while (original_value)
	{
		*end++ = allCharHex[original_value % base];
		original_value /= base;
	}

	reverse_string_without_len(str, end - 1);
	*(end) = '\0';  /* mark the end of the string */

	return (start);
}


/**
 * _utoa_format - Format the converted string based on the given flags.
 * This function adjusts the converted string to match certain format
 * specifications like adding '0' prefix for octal or '0x' for hex.
 *
 * @str: The string to format.
 * @value: The original number. (used to check for value like 0)
 * @base: The base for conversion.
 * @flag: Format flag (like '#' to dictate prefix behavior).
 * Return: Pointer to the formatted string.
 */
char *_utoa_format(char *str, unsigned long value, int base,
		char flag)
{
	char *start = str;
	char *end = str + strlen(str) - 1;
	char *ptr;

	if (flag == '#' && base == 8 && value != 0)
	{
		*(end + 1) = '\0';
		for (; end >= start; end--)
			*(end + 1) = *end;
		*start = '0';
	}
	else if (flag == '#' && (base == 16 || base == -16) && value != 0)
	{
		for (ptr = end; ptr >= start; ptr--)
			*(ptr + 2) = *ptr;
		*start = '0';
		*(start + 1) = (base == 16) ? 'x' : 'X';
		end += 2;
		*(end + 1) = '\0';
	}
	else
	{
		*(end + 1) = '\0';
	}

	return (start);
}

/**
 * _utoa - Convert an unsigned long value
 * to a string representation with
 * additional format specifier handling.
 * This function combines _utoa_core and
 * _utoa_format to provide a full
 * conversion with formatting.
 *
 * @value: The number to convert.
 * @str: The buffer to store the converted string.
 * @base: The base for conversion (2 for binary, 8 for octal, 16 for hex).
 * @flag: The flag for format specifiers (e.g., '#').
 * Return: Pointer to the converted and formatted string.
 */
char *_utoa(unsigned long value, char *str, int base, char flag)
{
	_utoa_core(value, str, base);
	_utoa_format(str, value, base, flag);

	return (str);
}
