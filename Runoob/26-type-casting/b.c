#include <stdio.h>

int main()
{
	int i = 17;
	char c = 'c'; // ascii的值是99
	int sum;

	sum = i + c;
	printf("Value of sum : %d\n", sum);
	return 0;
}

// 在这里，sum的值是116，因为编译器进行了整数提升，在执行实际加法运算时，把'c'的值转换为对应的ascii值。
