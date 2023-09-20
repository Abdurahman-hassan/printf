# include "main.h"

/**
  * _rot13 - function that encodes a string using rot13.
  * @c: is the char that we use
  * Return: char with ((x - A + 13)  % 26 + A))
  * ((x - a + 13) % 26 + a) for lowercase
  */
char *_rot13(char *c)
{
	int i = 0, j;
	/*string that hold all letter*/
	char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	/*string that holds the encrypt letter*/
	char *encoded = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (c[i])
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (c[i] == letters[j])
			{
				c[i] = encoded[j];
				break;
			}
		}

		i++;
	}
	return (c);
}
