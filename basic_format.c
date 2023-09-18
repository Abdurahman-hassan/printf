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
  * @specifier: define the exact format (s,c,%) to be printed
  * @args: list that hold the values
  * Return: length of the stored charachters
  */
int handle_custom_formats(char *buffer, const char specifier, va_list args)
{
	int index = 0;
	char *str;

	switch (specifier)
	{
		case 'R':
			{
				str = va_arg(args, char *);
				if (str == NULL)
				{
					str = "(null)";
				}

				str = _rot13(str);
				while (*str)
				{
					buffer[index++] = *str++;
				}
			}
			break;
	}
	return (index);
}

