#include<stdio.h>
#include<float.h>

// #include<float.h>头文件定义了表示浮点数的符号

int main()
{
	printf("The size of the smallest positive non-zero value of type float is %.3e\n", FLT_MIN); // float类型最小的极限值
	printf("The size of the largest value of type float is %.3e\n", FLT_MAX); // float类型最大极限值
	return 0;
}

