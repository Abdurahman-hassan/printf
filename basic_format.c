#include "main.h"

/**
 * handle_basic_formats - Handle print of char, string, and %.
 * @buffer: Storage for the specifier's value.
 * @specifier: Format (s, c, %) to be printed.
 * @args: List holding the values.
 * @buffer_index: Index to the buffer.
 * @total_printed: Count of total characters printed.
 * Return: Length of stored characters.
 */
int handle_basic_formats(char *buffer, const char specifier,
		va_list args, int *buffer_index, int *total_printed)
{
	int index = 0;

	switch (specifier)
	{
		/* if its charachter get its value and convert it to char */
		/* then it will be stored in the buffer*/
		case 'c':
			{
				index = print_charachter(buffer, args);
			}
			break;

			/*get the value of the string and store it char by char in the buffer*/
		case 's':
			{
				index += print_string(args, buffer, buffer_index, total_printed);
			}
			break;
		case '%':
			{
				buffer[index++] = '%';
				buffer[index] = '\0';
			}
			break;

	}
	return (index);
}
/**
 * handle_custom_formats - this function should handle the rot13
 * and reversed string
 * @buffer: buffer to store the the value of the specifier
 * @specifier: define the exact format (R , r) to be printed
 * @args: list that hold the values
 * Return: length of the stored charachters
 */
int handle_custom_formats(char *buffer, const char specifier, va_list args)
{
	int index = 0;
	char *original_str, *modified_str;

	switch (specifier)
	{
		case 'R':
			{
				original_str = va_arg(args, char *);
				if (original_str == NULL)
				{
					original_str = "(null)";
				}
				/*make a copy*/
				modified_str = strdup(original_str);
				/*check if memory allocation was success*/
				if (!modified_str)
					return (-1);

				/* modified the copy*/
				modified_str = _rot13(modified_str);

				while (*modified_str)
				{
					buffer[index++] = *modified_str++;
				}
				free(modified_str - index); /*free the copied string*/
			}
			break;
		case 'r':
			{
				original_str = va_arg(args, char *);
				if (original_str == NULL)
				{
					original_str = "(null)";
				}
				index += reverse_string_with_len(buffer + index, original_str);
			}
			break;
	}
	return (index);
}
/**
 * handle_special_string - it will handle the printing of string
 * that out of the range of the printable ascii charachter
 * @buffer: buffer to store the string
 * @specifier : the string that contain special charachter
 * @args: the string that came after convinsion
 * @flag: the flag key
 * Return: length of the string
 */
int handle_special_string(char *buffer, const char specifier,
		va_list args, char flag)
{
	int index = 0;
	char *str;
	char hex_buffer[5]; /* 2 char for hex + '\x' + '\0' */

	switch (specifier)
	{
		int i;

		case 'S':
		{
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(null)";
			while (*str)
			{
				if ((*str > 0 && *str < 32) || *str >= 127)
				{
					hex_buffer[0] = '\\';
					hex_buffer[1] = 'x';
					_utoa((unsigned long)*str, hex_buffer + 2, 16, flag);
					_toUpper(hex_buffer + 2); /* conver the hexa part*/
					/* copy if only one hex char was returned */
					/* in which case add a leading '0' */
					if (hex_buffer[3] == '\0')
					{
						hex_buffer[3] = hex_buffer[2];
						hex_buffer[2] = '0';
					}
					/* copy to the buffer */
					for (i = 0; hex_buffer[i]; i++)
						buffer[index++] = hex_buffer[i];
				}
				else
					buffer[index++] = *str;
				str++;
			}
		}
		break;
	}
	return (index);
}
