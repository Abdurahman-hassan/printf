#include "main.h"

/**
 * handle_basic_formats- it handle the print of charachter, string and %
 * @buffer: buffer to store the the value of the specifier
 * @specifier: define the exact format (s,c,%) to be printed
 * @args: list that hold the values
 * Return: length of the stored charachters
 */

int handle_basic_formats(char *buffer, const char specifier, va_list args)
{
	int index = 0;
	char *str;

	switch (specifier)
	{
		/* if its charachter get its value and convert it to char */
		/* then it will be stored in the buffer*/
		case 'c':
			{
				buffer[index++] = (char) va_arg(args, int);
			}
			break;

			/*get the value of the string and store it char by char in the buffer*/
		case 's':
			{
				str = va_arg(args, char *);
				if (str == NULL)
				{
					str = "(null)";
				}
				while (*str)
				{
					buffer[index++] = *str++;
				}
			}
			break;
			/*store % directly in the buffer*/
		case '%':
			{
				buffer[index++] = '%';
			}
			break;
	}
	/*current index of the buffer*/
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
