#include<stdio.h>

int main()
{
	int i, sum = 0;
	while (i <= 100) {
		sum += i;
		i ++;
	}
	printf("sum = %d\n", sum);
	return 0;
}
