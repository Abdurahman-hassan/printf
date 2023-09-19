#include "main.h"

/* handle_special_string - it will handle the printing of string
 * that out of the range of the printable ascii charachter
 * @buffer: buffer to store the string
 * @str : the string that contain special charachter
 * Return: length of the string
 */

int handle_special_string(char *buffer, const char *str)
{
	int index = 0;
	char hex[3];

	while (*str)
	{
		if ((*str >= 1 && *str < 32) || *str >= 127)
		{
			buffer[index++] = '\\';
			buffer[index++] = 'x';

			/* convert the char to hex and append */
			_utoa((unsigned char)*str, hex, 16);
			buffer[index++] = hex[0];
			buffer[index++] = hex[1];	
		}
		else
		{
			buffer[index++] = *str;
		}
		str++;
	}
	return (index);
}
