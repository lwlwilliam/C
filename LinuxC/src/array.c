#include <stdio.h>

void foo(int a[6])
{
	int i;

	for (i = 0; i < 6; i ++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
}

int main()
{
	int test[6] = {0, 1, 2, 3, 4, 5};
	foo(test);
	
	return 0;
}
