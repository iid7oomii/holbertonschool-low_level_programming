#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer value of the string
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0;
	unsigned int result = 0;

	while (s[i] != '\0')
	{
	if (s[i] == '-')
	sign *= -1;
	else if (s[i] >= '0' && s[i] <= '9')
	{
	started = 1;
	result = result * 10 + (s[i] - '0');
	}
	else if (started)
	break;
	i++;
	}

	return (sign * result);
}
