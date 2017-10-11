// 有一分数序列，2/1, 3/2, 5/3, 8/5, 13/8, 21/13...求出这个数列的前20项之和

#include <stdio.h>

float cal(int n);

int main()
{
/*
	int i, t;
	float sum = 0;
	float a = 2, b = 1;
	for (i = 1; i <= 20; i ++) {
		sum = sum + a/b;
		t = a;
		a = a + b;
		b = t;
	}
	printf("%9.6f\n", sum);
*/

	float sum;
	sum = cal(20);

	printf("sum = %f\n", sum);
	
	return 0;
}


float cal(int n)
{
	float x = 2, y = 1;
	float inter;
	float sum = 0;
	int i = 1;
	while (i <= n) {
		sum += x / y;
		inter = x;
		x = x + y;
		y = inter;

		i ++;
	}

	return sum;
}
