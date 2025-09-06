#include "main.h"

/**
 * _strcat - concatenates the string pointed to by src
 *            to the end of the string pointed to by dest
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	i++;

	while (src[j] != '\0')
	{
	dest[i] = src[j];
	i++;
	j++;
	}

	dest[i] = '\0';

	return (dest);
}
