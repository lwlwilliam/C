#include <stdio.h>

int main()
{
	int integerType;
	float floatType;
	double doubleType;
	char charType;
	long b;
	long long c;
	long double d;

	printf("Size of int : %ld bytes\n", sizeof(integerType));
	printf("Size of float : %ld bytes\n", sizeof(floatType));
	printf("Size of double : %ld bytes\n", sizeof(doubleType));
	printf("Size of char : %ld bytes\n", sizeof(charType));
	printf("Size of long : %ld bytes\n", sizeof(b));
	printf("Size of long long : %ld bytes\n", sizeof(c));
	printf("Size of long double : %ld bytes\n", sizeof(d));

	return 0;
}
