#include "main.h"

/**
 * _printf - This function is simlute the original printf
 * @format: the string include csuxXo%
 * @...: this is allow to us to add multible convinsion
 * Return: length
 */
int _printf(const char *format, ...)
{
	int buffer_index = 0;
	int total_printed = 0;
	char buffer[BUFFER_SIZE];
	va_list args;

	if (!format)
		return (-1);
	if (format[0] == '%' && !format[1])
		return (-1);

	va_start(args, format);

	buffer_index = process_string(format, buffer, args, &total_printed);

	total_printed += handle_remaining_buffer(buffer, buffer_index);

	va_end(args);

	return (total_printed);
}
