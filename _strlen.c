/**
 * _strlen - count the length of the string
 * @str: the string we want to count it length
 * Return: intger value of the length
 */

int _strlen(char *str)
{
	/* variable i to hold the length*/
	int i = 0;

	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
