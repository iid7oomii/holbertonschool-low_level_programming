#include "main.h"

/**
 * _prime_helper - helper function to check if n is prime
 * @n: number to check
 * @i: current divisor
 *
 * Return: 1 if prime, 0 if not
 */
int _prime_helper(int n, int i)
{
	if (n <= 1)
		return (0);
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (_prime_helper(n, i + 1));
}

/**
 * is_prime_number - returns 1 if n is prime, 0 otherwise
 * @n: number to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	return (_prime_helper(n, 2));
}
