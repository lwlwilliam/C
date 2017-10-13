// 利用递归求5!

#include <stdio.h>

int main()
{
	int n = 5;
	int fact(int);
	printf("%d! = %d\n", n, fact(n));
}

int fact(int j)
{
	int sum;
	if (j == 0) {
		sum = 1;
	} else {
		sum = j * fact(j - 1);
	}

	return sum;
}
