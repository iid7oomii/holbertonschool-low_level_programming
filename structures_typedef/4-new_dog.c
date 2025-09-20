#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s:	string to measure
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s && s[len])
		len++;
	return (len);
}

/**
 * _strcpy - copies a string to another buffer
 * @dest:	destination buffer
 * @src:	source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - creates a new dog
 * @name:	name of the dog
 * @age:	age of the dog
 * @owner:	owner of the dog
 *
 * Return: pointer to new dog_t, or NULL if fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int len_name, len_owner;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	len_name = _strlen(name);
	len_owner = _strlen(owner);

	d->name = malloc(len_name + 1);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	_strcpy(d->name, name);

	d->owner = malloc(len_owner + 1);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	_strcpy(d->owner, owner);

	d->age = age;

	return (d);
}
