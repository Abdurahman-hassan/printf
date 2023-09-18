#include "main.h"

/**
 * _strchr - search for charachter in a string and return it index
 * @s: string to search in
 * @c: search key
 * Return: pointer to the index of c
 */

char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			/* return a pointer to first occurrence of c */
			return ((char *)s);
		}
		s++;
	}
	/* if c is null terminator return null terminator of the string */
	if (c == '\0')
	{
		return ((char *)s);
	}
	/* if reach end of string and c is not found */
	return (NULL);

}
