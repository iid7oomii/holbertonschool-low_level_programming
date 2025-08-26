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
	printf("Size of a char: %zu byte(s)\n", sizeof(mychar));
	printf("Size of an int: %zu byte(s)\n", sizeof(myint));
	printf("Size of a long int: %ld byte(s)\n", sizeof(mylongint));
	printf("Size of a long long int: %ld byte(s)\n", sizeof(mylonglongint));
	printf("Size of a float: %zu byte(s)\n", sizeof(myfloat));
	return (0);

}
