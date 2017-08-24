#include <stdio.h>

int main()
{
	int a = 5;
	int b = 20;
	int c;

	if (a && b) {
		printf("Line 1 - true\n");
	}

	if (a || b) {
		printf("Line 2 - true\n");
	}

	/* 改变 a 和 b 的值 */
	a = 0;
	b = 10;
	if (a && b) {
		printf("Line 3 - true\n");
	} else {
		printf("Line 3 - false\n");
	}

	if (! (a && b)) {
		printf("Line 4 - true\n");
	}

	return 0;
}
