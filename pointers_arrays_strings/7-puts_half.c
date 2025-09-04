#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: the string to process
 * Return: void
 */
void puts_half(char *str)
{
	int length = 0;
	int start, i;


	while (str[length] != '\0')
	{
	length++;
	}


	if (length % 2 == 0)
	start = length / 2;
	else
	start = (length + 1) / 2;


	for (i = start; i < length; i++)
	{
	_putchar(str[i]);
	}
	_putchar('\n');
}
