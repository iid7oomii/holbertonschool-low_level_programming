#include "main.h"

/**
 * _puts -  prints a string, followed by a new line
 * @str: The string that i will print
 * Return: void
 */

void _puts(char *str)

{
	for (; *str != '\0'; str++)
	{
	_putchar(*str);
	}
	_putchar('\n');
}
