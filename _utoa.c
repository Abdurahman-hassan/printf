#include "main.h"
#include <stdio.h>

/**
 * _utoa - this function convert the numbers to string
 * also convert the decimal to binary octal and hexa
 * as per the base that will we use
 * @value: the number that will turn into string
 * @str: the buffer that will use
 * @base: 2, 8, 16
 * @flag: the flag for format specifiers
 * Return: the address of buffer -> converted string
 */
char *_utoa(unsigned long value, char *str, int base, char flag)
{
	/* all digits that we will check using it */
	char allCharHex[] = "0123456789abcdef";
	/* empty buffer + buffer index */
	char *start = str;
	/* end is also empty */
	char *end = str;
	unsigned long original_value = value;
	char *ptr;

	if (original_value == 0)
	{
		/* assign the string with zero */
		*str++ = '0';
		/* end string */
		*str = '\0';
		return (start);
	}

	/* this logic will read from right to left */
	/* and make the number reversed */
	while (original_value)
	{
		/* fill the end with reversed converted */
		/* numbers by checking through allCharHex */
		*end++ = allCharHex[original_value % base];
		original_value /= base;
	}

	reverse_string_without_len(str, end - 1);
	end = str + (end - str) - 1;

	if (flag == '#' && base == 8 && value != 0)
	{
		*(end + 1) = '\0';
		for (; end >= start; end--) *(end + 1) = *end;
		*start = '0';
	}
	else if (flag == '#' && (base == 16 || base == -16) && value != 0)
	{
		for (ptr = end; ptr >= start; ptr--) *(ptr + 2) = *ptr;
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
