#include "main.h"

/**
 * handle_flags - this function will handle the printing of flags
 * @format: the string that contain flags
 * @i: to track the index
 * Return: flag charachter
 */
char handle_flags(const char *format, int *i)
{
	char flag = '\0';

	if (format[*i + 1] == '+' || format[*i + 1] == ' ' || format[*i + 1] == '#')
	{
		flag = format[*i + 1];
		(*i)++;
	}
	return (flag);

}

/**
 * identify_specifier - will specify the format with the flag
 * @format: string that contain the formats
 * @i: to track the index
 * @args: the list that contain the value of the specifier
 * @buffer: to store the value of argument
 * @flag: define the way to print the string
 * Return: int value of buffer index
 */

int identify_specifier(const char *format, int *i, va_list args,
		char *buffer, char flag)
{
	int buffer_index = 0;

	if (_strchr("cs%", format[*i + 1]))
	{
		buffer_index += handle_basic_formats(buffer, format[*i + 1], args);
		(*i)++;
	}
	else if (_strchr("rR", format[*i + 1]))
	{
		buffer_index += handle_custom_formats(buffer, format[*i + 1], args);
		(*i)++;
	}
	else if (_strchr("dib", format[*i + 1]))
	{
		buffer_index += handle_integer_binary(buffer, format[*i + 1], args, flag);
		(*i)++;
	}
	else if (_strchr("xoX", format[*i + 1]))
	{
		buffer_index += handle_octal_hexa(buffer, format[*i + 1], args, flag);
		(*i)++;
	}
	else if (_strchr("up", format[*i + 1]))
	{
		buffer_index += handle_unsigned_pointer(buffer, format[*i + 1], args, flag);
		(*i)++;
	}
	else if (_strchr("S", format[*i + 1]))
	{
		buffer_index += handle_special_string(buffer, format[*i + 1], args, flag);
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
 * process_format - Modify the process_format
 * function to use the split functions
 * @format: this is the format flag key
 * @i: is a counter
 * @args: data from user
 * @buffer: an empty array
 * Return: buffer_index
 */
int process_format(const char *format, int *i, va_list args, char *buffer)
{

	char flag;
	int buffer_index = 0;
	/*get the flag if any*/
	flag = handle_flags(format, i);
	buffer_index = identify_specifier(format, i, args, buffer, flag);
	return (buffer_index);
} 
