#include "main.h"

/**
 * reverse_string_with_len - it reverse the string according to it length
 * @buffer: buffer to store the reversed string
 * @str: the string to be reversed
 * Return: the length of the string
 */

int reverse_string_with_len(char *buffer, char *str)
{
	int len = _strlen(str);
	int i;

	for (i = 0; i < len; i++)
	{
		buffer[i] = str[len - i - 1];
	}
	return (len);
}

/**
 * reverse_string_without_len - reserve string by swabing between start and end
 * @start: charachter to be swaped to the rigth
 * @end: charachter to be swaped to the left
 * Return: void
 */

void reverse_string_without_len(char *start, char *end)
{
	char temp;

	if (!start || !end)
	{
		return;
	}
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
