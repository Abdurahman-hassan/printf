#include "main.h"

/**
 * _itoa - convert integer to its string
 * @value: the integer to be converted
 * @str: string to store the converted integer
 * Return: pointer to the string
 */

char *_itoa(int value, char *str)
{
	/* holds the starting addres of where to store string*/
	char *start = str;
	char *end;

	/* check if the value is 0 or not*/
	/* if it's 0 assign 0 and return start*/
	if (value == 0)
	{
		*str++ = '0';
		*str = '\0';
		return (start);
	}
	/* if the integer is negative we first store the sign*/
	/* then we will make it positive*/
	if (value < 0)
	{
		*str++ = '-';
		value = -value;
	}
	/*end will hold the converted integer value in reverse */
	end = str;
	while (value)
	{
		/*convert to charachter and add it to the end*/
		*end++ = '0' + (value % 10);
		/* update the value, moving the corsur to left */
		value /= 10;
	}
	*end-- = '\0';
	/*reverse the number back to its originl value*/
	reverse_string_without_len(str, end);
	return (start);
}
