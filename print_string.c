#include "main.h"
#include <stdio.h>

int print_string(va_list args, char *buffer, int *total_printed, int *buffer_index)
{
	int count, start, pos;
	int index = 0;
	char *ptr;
	char *str;

	printf("%d ", *buffer_index);
	count = *buffer_index;
	start = *buffer_index;
	pos = *buffer_index;
	ptr = buffer;
	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{

		if (count >= BUFFER_SIZE)
		{
			write(1, buffer - (start), count);
			*total_printed += count;
			index = 0;
			count = 0;
			ptr = buffer - start;
			start = 0;
		}
		ptr[index++] = *str++;
		count++;
	}
	index = count - pos;
	buffer[index] = '\0';
	return (index);
}

