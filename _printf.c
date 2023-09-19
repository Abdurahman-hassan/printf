#include "main.h"

/**
 * process_format - this function reposable for handling
 * the format in order to make the code readable and clean
 * @format: this is string that we will use
 * @i: integer number to use in loop
 * @args: this is the input that takes after convinsion
 * @buffer: the array that we will use to store the strings into it
 * Return: the index
 */
int process_format(const char *format, int *i, va_list args, char *buffer)
{
	int buffer_index = 0;
	char flag = '\0';

	if (format[*i + 1] == '+' || format[*i + 1] == ' ' || format[*i + 1] == '#')
	{
		flag = format[*i + 1];
		(*i)++;
	}
	if (_strchr("cs%", format[*i + 1]))
	{
		buffer_index +=
			handle_basic_formats(buffer + buffer_index, format[*i + 1], args);
		(*i)++;
	}
	else if (_strchr("rR", format[*i + 1]))
	{
		buffer_index +=
			handle_custom_formats(buffer + buffer_index, format[*i + 1], args);
		(*i)++;
	}
	else if (_strchr("dib", format[*i + 1]))
	{
		buffer_index +=
			handle_integer_binary(buffer + buffer_index, format[*i + 1], args, flag);
		(*i)++;
	}
	else if (_strchr("xoX", format[*i + 1]))
	{
		buffer_index +=
			handle_octal_hexa(buffer + buffer_index, format[*i + 1], args, flag);
		(*i)++;
	}
	else if (_strchr("up", format[*i + 1]))
	{
		buffer_index +=
			handle_unsigned_pointer(buffer + buffer_index, format[*i + 1], args, flag);
		(*i)++;
	}
	else if (_strchr("S", format[*i + 1]))
	{
		buffer_index +=
			handle_special_string(buffer + buffer_index, format[*i + 1], args, flag);
		(*i)++;
	}
	else
	{
		buffer[buffer_index++] = format[*i + 1];
		(*i)++;
	}
	return (buffer_index);

}

/**
 * _printf - This function is simlute the original printf
 * @format: the string include csuxXo%
 * @...: this is allow to us to add multible convinsion
 * Return: length
 */
int _printf(const char *format, ...)
{
	int i, buffer_index = 0, total_printed = 0;
	char buffer[BUFFER_SIZE];
	va_list args;

	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			buffer_index += process_format(format, &i, args, buffer + buffer_index);
		}
		else
		{
			buffer[buffer_index++] = format[i];
		}
		if (buffer_index >= BUFFER_SIZE - 1)
		{
			write(1, buffer, buffer_index);
			total_printed += buffer_index;
			buffer_index = 0;
		}
	}
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
		total_printed += buffer_index;
	}
	va_end(args);
	return (total_printed);
}
