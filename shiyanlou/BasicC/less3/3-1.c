#include<stdio.h>

int main()
{
	int a, b, c; // 定义a、b、c为整形变量
	printf("Please enter a value: ");
	scanf("%d", &a); // 获取变量a的地址
	printf("Please enter b value: ");
	scanf("%d", &b);
	c = a + b;
	printf("%d\n", c);
	return 0;
}
