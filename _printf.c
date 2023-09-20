#include "main.h"

/**
 * _printf - This function is simlute the original printf
 * @format: the string include csuxXo%
 * @...: this is allow to us to add multible convinsion
 * Return: length
 */
int _printf(const char *format, ...)
{
	int buffer_index = 0, total_printed = 0;
	char buffer[BUFFER_SIZE];

	memset(buffer, 0, BUFFER_SIZE);

	va_list args;

	if (!format || (format[0] == '%' && !format[1]) ||
			(format[0] == '%' && format[1] == ' ' && !format[2]))
	{
		return (-1);
	}

	va_start(args, format);

	buffer_index = process_string(format, buffer, args);

	total_printed += handle_remaining_buffer(buffer, buffer_index);

	va_end(args);

	return (total_printed);
}
