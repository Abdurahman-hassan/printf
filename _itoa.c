#include "main.h"

/**
 * _itoa - convert integer to its string
 * @value: the integer to be converted
 * @str: string to store the converted integer
 * @flag: this is the flag key
 * Return: pointer to the string
 */

char *_itoa(int value, char *str, char flag)
{
	/* holds the starting addres of where to store string*/
	char *start = str;
	char *end;

	if (!str)
	{
		return (NULL);
	}

	if (value == 0)
	{
		*str++ = '0';
		*str = '\0';
		return (start);
	}
	if (value < 0)
		*str++ = '-';
	else if (flag == '+')
		*str++ = '+';
	else if (flag == ' ')
		*str++ = ' ';

	/*end will hold the converted integer value in reverse */
	end = str;
	while (value)
	{
		int rem = value % 10;

		if (value < 0)
			rem = -rem;
		/*convert to charachter and add it to the end*/
		*end++ = '0' + rem;
		/* update the value, moving the corsur to left */
		value /= 10;
	}
	*end-- = '\0';
	/*reverse the number back to its originl value*/
	reverse_string_without_len(str, end);
	return (start);
}
