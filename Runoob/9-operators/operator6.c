#include <stdio.h>

int main()
{
	int a = 21;
	int c;

	c = a;
	printf("Line 1 - c = %d\n", c);

	c += a;
	printf("Line 2 - c += %d\n", c);

	c -= a;
	printf("Line 3 - c -= %d\n", c);

	c *= a;
	printf("Line 4 - c *= %d\n", c);

	c /= a;
	printf("Line 5 - c /= %d\n", c);

	c = 200;
	c %= a;
	printf("Line 6 - c %= %d\n", c);

	c <<= 2;
	printf("Line 7 - c <<= %d\n", c);

	c >>= 2;
	printf("Line 8 - c >>= %d\n", c);

	c &= 2;
	printf("Line 9 - c &= %d\n", c);

	c ^= 2;
	printf("Line 10 - c ^= %d\n", c);

	c |= 2;
	printf("Line 11 - c |= %d\n", c);


}
