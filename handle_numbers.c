#include "main.h"

/**
 * handle_integer_binary - this function is responsble for
 * taking a numbers from _printf if the convinsion is
 * %d %i %b
 * %d, %i: for integers, %b: for binary
 * and then call the _itoa and _utoa function
 * in order to convert these numbers into string
 * @buffer: empty array that we store the data into it
 * @specifier: %d %i %b
 * @args: the numbers after convinsions
 * @flag: the flag key
 * Return: the index / length of string
 */
int handle_integer_binary(char *buffer, const char specifier,
		va_list args, char flag)
{
	int index = 0;

	switch (specifier)
	{
		case 'd':
		case 'i':
			{
				int value = va_arg(args, int);
				char *str = _itoa(value, buffer, flag);

				while (*str)
				{
					buffer[index++] = *str++;
				}
			}
			break;
		case 'b':
			{
				unsigned int value = va_arg(args, unsigned int);
				char *str = _utoa(value, buffer, 2, flag);

				while (*str)
				{
					buffer[index++] = *str++;
				}
			}
			break;
	}
	return (index);
}
/**
 * handle_octal_hexa - this function is responsble for
 * taking a numbers from _printf if the convinsion is %o%X%x
 * and then call the _itoa and _utoa function
 * in order to convert these numbers into string
 * @buffer: empty array that we store the data into it
 * @specifier: %o %x %X
 * @args: the numbers after convinsions
 * @flag: the flag key
 * Return: the index / length of string
 */
int handle_octal_hexa(char *buffer, const char specifier,
		va_list args, char flag)
{
	int index = 0;

	switch (specifier)
	{
		case 'o':
			{
				unsigned int value = va_arg(args, unsigned int);
				char *str = _utoa(value, buffer, 8, flag);

				while (*str)
				{
					buffer[index++] = *str++;
				}
			}
			break;
		case 'x':
			{
				unsigned int value = va_arg(args, unsigned int);
				char *str = _utoa(value, buffer, 16, flag);

				while (*str)
				{
					buffer[index++] = *str++;
				}
			}
			break;
		case 'X':
			{
				unsigned int value = va_arg(args, unsigned int);
				char *str = _utoa(value, buffer, 16, flag);

				_toUpper(str);
				while (*str)
				{
					buffer[index++] = *str++;
				}
			}
			break;
	}
	return (index);
}
/**
 * handle_unsigned_pointer - this function is responsible for handling the
 * printing of unsigned integer with the format %b and the pointer %p
 * @buffer: array where to store the values of the format
 * @specifier: the exact format (u or p)
 * @args: the unsigned int or the pointer value
 * @flag: the flag key
 * Return: index to current buffer
 */
int handle_unsigned_pointer(char *buffer, const char specifier,
		va_list args, char flag)
{
	int index = 0;
	char *tmp;

	switch (specifier)
	{
		case 'u':
			{
				unsigned int value = va_arg(args, unsigned int);
				char *str = _utoa(value, buffer, 10, flag);

				while (*str)
				{
					buffer[index++] = *str++;
				}
			}
			break;
		case 'p':
			{
				void *ptr = va_arg(args, void *);
				unsigned long adress = (unsigned long) ptr;

				if (ptr == NULL)
				{
					tmp = "(nil)";
				}
				else
				{
					buffer[index++] = '0';
					buffer[index++] = 'x';
					tmp = _utoa(adress, buffer + index, 16, flag);
				}
				while (*tmp)
				{
					buffer[index++] = *tmp++;
				}
			}
			break;
	}
	return (index);
}
