#include <stdio.h>

int main()
{
	int i = 17;
	char c = 'c'; // ascii值是99
	float sum;

	sum = i + c;
	printf("Value of sum : %f\n", sum);
	return 0;
}

// 在这里，c首先被转换为整数，但是由于最后的值是double型的，所以会应用常用的算术转换，编译器会把i和c转换为浮点型，并把它们相加得到一个浮点数。
