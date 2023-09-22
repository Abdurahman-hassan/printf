#include "main.h"

/**
 * handle_width - Parses width specifier from a format string.
 * Given a position in a format string
 * (typically where a '%' was found),
 * this function parses the width specification
 * if present. Width specifier
 * is expected to be a sequence of digits following the '%'.
 * @i: A pointer to an integer representing the
 * current position in the format string.
 * After execution, it will point to the last character of the width specifier.
 * @format: The format string being parsed.
 * Return: Returns the parsed width as an integer.
 * If no width is present, returns 0.
 */
int handle_width(int *i, char *format)
{
	int position;
	int width = 0;
	int unit = 1;

	for (position = *i + 1; format[position] != '\0'; position++)
	{
		if (format[position] >= 48 && format[position] <= 57)
		{
			width = (width * unit) + (format[position] - '0');
			unit = 10;
		}
		else
			break;
	}
	*i = position - 1;
	return (width);
}
