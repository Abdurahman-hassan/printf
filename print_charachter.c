#include "main.h"

/**
 * print_charachter - this function is resposible for printing a characher
 * arg: list contain the charachter to be printed
 * Return: number of printed
 */

int print_charachter(char *buffer, va_list args)
{
	int index = 0;

	buffer[index++] = (char) va_arg(args, int);
	buffer[index] = '\0';
	return (index);

}
