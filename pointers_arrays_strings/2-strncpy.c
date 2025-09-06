#include "main.h"

/**
 * _strncpy - copies at most n bytes of src into dest
 * @dest: destination string
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Return: pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
