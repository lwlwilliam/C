#include<stdio.h>

int main()
{
	int a = 100, b = 10;
	int *pointer_1, *pointer_2; // 定义指向整型数据的指针变量
	pointer_1 = &a; // 把变量a的地址赋给指针变量pointre_1
	pointer_2 = &b;
	printf("a = %d, b = %d\n", a, b);
	printf("%ld, %ld\n", pointer_1, pointer_2); // 输出a和b在内存中的地址
	printf("*pointer_1 = %d, *pointer_2 = %d\n", *pointer_1, *pointer_2);

	return 0;
}

/*
 * 如果代码是的指针打印出为负数，则要将打印的类型%d调整为%ld才可以正常输出。
 * 调整为%p去匹配指针型最侍。
 */
