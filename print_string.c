#include "main.h"

/**
 * print_string - Prints a string to a buffer
 * and flushes the buffer if full.
 * This function prints a string to an output buffer.
 * If the buffer reaches its capacity (as specified by BUFFER_SIZE),
 * the buffer is written to the standard
 * output and the buffer counters are reset.
 * @args: Variable argument list containing the string to be printed.
 * @buffer: The buffer in which the string is to be stored.
 * @buffer_index: The current position index in the buffer.
 * @total_printed: A counter to keep track of the total characters printed.
 * Return: The number of characters added to the buffer by this function.
 */
int print_string(va_list args, char *buffer,
		int *buffer_index, int *total_printed)
{
	int count, start, pos;
	int index = 0;
	char *ptr;
	char *str;

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
