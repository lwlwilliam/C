/*
古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月）
程序分析：兔子的规律为数列1，1，2，3，5，8，13，21...，即下个月是上两个月之和（从第三个月开始）。
*/

#include <stdio.h>

int main()
{
	// 方法一
	/*
	int f1 = 1, f2 = 1, i;
	for (i = 1; i <= 20; i ++) {
		printf("%12d%12d", f1, f2);
		if (i % 2 == 0) {
			printf("\n");
		}
		f1 = f1 + f2;
		f2 = f1 + f2;
	}
	return 0;
	*/

	// 方法二：递归，斐波那契散列
	int i;
	printf("month\tnumber\n");
	for (i = 1; i < 41; i ++) {
		printf("%d\t%d\n", i, fibonacci(i));
	}
	return 0;
}

int fibonacci(int i)
{
	if (i == 0) {
		return 0;
	}

	if (i == 1) {
		return 1;
	}

	return fibonacci(i - 1) + fibonacci(i - 2);
}
