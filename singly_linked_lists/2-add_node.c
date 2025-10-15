#include "lists.h"
#include <stdlib.h>

/**
 * _strlen - calculate the length of a string
 * @s: the string
 * Return: length
 */
unsigned int _strlen(const char *s)
{
	unsigned int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * _strdup - duplicate a string (without using strdup)
 * @s: string to duplicate
 * Return: pointer to new string, or NULL if fail
 */
char *_strdup(const char *s)
{
	unsigned int len, i;

	char *dup;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = s[i];
	dup[i] = '\0';

	return (dup);
}

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the head of the list
 * @str: string to store in the node
 * Return: address of the new node, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = _strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = _strlen(new_node->str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
