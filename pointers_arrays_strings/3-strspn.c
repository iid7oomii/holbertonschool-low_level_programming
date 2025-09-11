#include "main.h"
#include <stddef.h>

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to check
 * @accept: the string containing the accepted characters
 *
 * Return: the number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, found;

	while (*s != '\0')
	{
		found = 0;
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			break;
		}
		count++;
		s++;
	}

	return (count);
}
