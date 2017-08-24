#include <stdio.h>

int main()
{
	int a = 4;
	short b;
	double c;
	int *ptr;

	/* sizeo */
	printf("Line 1 - a = %lu\n", sizeof(a));
	printf("Line 2 - b = %lu\n", sizeof(b));
	printf("Line 1 - c = %lu\n", sizeof(c));

	/* & 和 * */
	ptr = &a;
	printf("a = %d\n", a);
	printf("*ptf = %d\n", *ptr);

	/* 三元运算符 */
	a = 10;
	b = (a == 1) ? 20 : 30;
	printf("b = %d\n", b);

	b = (a == 10) ? 20 : 30;
	printf("b = %d\n", b);

	return 0;
}
