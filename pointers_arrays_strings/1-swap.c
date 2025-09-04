#include "main.h"
#include <stdio.h>

/**
 * swap_int - swaps the values of two integers
 * @a: First integer
 * @b: Second integer
 * Return: nothing
 */

void swap_int(int *a, int *b)

{
	int temp = *a;

	*a = *b;

	*b = temp;

}
