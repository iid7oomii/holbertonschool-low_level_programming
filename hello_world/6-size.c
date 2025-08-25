#include <stdio.h>

/**
 * main - prints the size of various types on the computer
 *
 * Return: 0 (success)
 */

int main(void)
{
#if __x86_64__ || __ppc64__
	printf("Correct output for a 64bit machine\n");
#else
	printf("Correct output for a 32bit machine\n");
#endif
	printf("Size of char: %zu byte(s)\n", sizeof(char));
	printf("Size of int: %zu byte(s)\n", sizeof(int));
	printf("Size of long int: %zu byte(s)\n", sizeof(long int));
	printf("Size of long long int: %zu byte(s)\n", sizeof(long long int));
	printf("Size of float: %zu byte(s)\n", sizeof(float));
	return (0);

}
