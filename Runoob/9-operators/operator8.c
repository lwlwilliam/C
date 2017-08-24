#include <stdio.h>

int main()
{
	int a = 20;
	int b = 10;
	int c = 15;
	int d = 5;
	int e;

	e = (a + b) * c /d;
	printf("%d\n", e);

	e = ((a + b) * c) / d;
	printf("%d\n", e);

	e = (a + b) * (c / d);
	printf("%d\n", e);

	e = a + (b * c) / d;
	printf("%d\n", e);

	return 0;
}
