#include "main.h"

/**
 * handle_buffer - Function to handle buffer overflow
 * and write the buffer content
 * @buffer: and empty array
 * @buffer_index: the counter to make sure the buffer not execded
 * Return: 0
 */
int handle_buffer(char *buffer, int *buffer_index)
{
	/* to keep track of total printed*/
	int written = *buffer_index;

	if (*buffer_index >= BUFFER_SIZE - 1)
	{
		write(1, buffer, *buffer_index);
		*buffer_index = 0;
		return (written);
	}
	return (0);
}

/**
 * process_string - Function to process each
 * character in the format string
 * @format: the format key
 * @buffer: an empty string
 * @args: values came from the function
 * @total_printed: total number of printed charachter
 * Return: buffer_index
 */
int process_string(const char *format, char *buffer, va_list
		args, int *total_printed)
{
	int i, buffer_index = 0;

	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			buffer_index += process_format(format, &i, args, buffer + buffer_index,
					&buffer_index, total_printed);
		}
		else
		{
			buffer[buffer_index++] = format[i];
		}

		handle_buffer(buffer, &buffer_index);
	}

	return (buffer_index);
}

/**
 * handle_remaining_buffer - Function to handle
 * remaining content in buffer
 * @buffer: an empty array
 * @buffer_index: buffer to added to the original one
 * Return: 0 if success
 */
int handle_remaining_buffer(char *buffer, int buffer_index)
{
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
		return (buffer_index);
	}
	return (0);
}
