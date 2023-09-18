# include "main.h"

/**
  * _utoa - this function convert the numbers to string
  * also convert the decimal to binary octal and hexa
  * as per the base that will we use
  * @value: the number that will turn into string
  * @str: the buffer that will use
  * @base: 2, 8, 16
  * Return: the adress of buffer -> converted string
  */
char *_utoa(unsigned long value, char *str, int base)
{
	/* all digits that we will check using it */
	char allCharHex[] = "0123456789abcdef";
	/* empty buffer + buffer index */
	char *start = str;
	/* end is also empty*/
	char *end = str;

	if (value == 0)
	{
		/* assign the string with zero */
		*str++ = '0';

		/* end string */
		*str = '\0';
		return (start);
	}

	/* this logic will read from right to left*/
	/* and make the number reversed */

	while (value)
	{
		/* fill the end with reversed converted*/
		/* numbers by check through allCharHex */
		/* 100 decimal -> 64 hex */
		*end++ = allCharHex[value % base];
		value /= base;
	}
	/* termenate it at with \0 */

	*end-- = '\0';
	/* revers the numbers to be from the left to right */
	/* in the original way */
	reverse_string_without_len(str, end);

	return (start);
}
