#include "main.h"

/**
  * _printf - This function is simlute the original printf
  * This function check after % and call the sutable function
  * these functions need a buffer to store the chars into it
  * and the format cs%uxXou ... etc and the args that take
  * after convinsion from function throght va_arg
  * @format: the string include csuxXo%
  * @...: this is allow to us to add multible convinsion
  * Return: length
  */
int _printf(const char *format, ...)
{
	int i;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		/* check after % if thers csdiouxX and not empty */
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			if (_strchr("cs%", format[i + 1]))
			{
				buffer_index +=
					handle_basic_formats(buffer + buffer_index, format[i + 1], args);
				i++;
			}
			else if (_strchr("dib", format[i + 1]))
			{
				buffer_index +=
					handle_integer_binary(buffer + buffer_index, format[i + 1], args);
				i++;
			}
			else if (_strchr("xoX", format[i + 1]))
			{
				buffer_index +=
					handle_octal_hexa(buffer + buffer_index, format[i + 1], args);
				i++;
			}
			else if (_strchr("up", format[i + 1]))
			{
				buffer_index +=
					handle_unsigned_pointer(buffer + buffer_index, format[i + 1], args);
				i++;
			}
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
