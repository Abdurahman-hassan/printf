#include "main.h"

/**
  * _toUpper - this function convert the lower char to upper
  * @c: this is the char that will check and use to make it upper
  * Return: adress of upper string
  */
char *_toUpper(char *c)
{
	int i = 0;

	while (c[i])
	{
		if (c[i] >= 'a' && c[i] <= 'z')
		{
			c[i] -= 32;
		}
		i++;
	}
	return (c);
}
