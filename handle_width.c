#include "main.h"

int handle_width (int *i, char *format)
{
	int position;
	int width = 0;
	int unit = 1;

	for (position = *i + 1; format[position] != '\0'; position++)
	{
		if (format[position] >= 48 && format[position] <= 57)
		{
			width = (width * unit ) + (format[position] - '0');
			unit = 10;
		}
		else
		{
			break;
		}
	}
	*i = position - 1;
	return (width); 
}
