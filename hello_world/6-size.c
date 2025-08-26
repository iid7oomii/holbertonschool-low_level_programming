#include <stdio.h>

/**
 * main - prints the size of various types on the computer
 *
 * Return: 0 (success)
 */

int main(void)
{
int myint;
char mychar;
long int mylongint;
long long int mylonglongint;
float myfloat;
	printf("Size of char: %zu byte(s)\n", sizeof(mychar));
	printf("Size of int: %zu byte(s)\n", sizeof(myint));
	printf("Size of long int: %ld byte(s)\n", sizeof(mylongint));
	printf("Size of long long int: %lld byte(s)\n", sizeof(mylonglongint));
	printf("Size of float: %zu byte(s)\n", sizeof(myfloat));
	return (0);

}
