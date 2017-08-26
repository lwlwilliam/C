#include <stdio.h>
#include <string.h>

union Data
{
	int i;
	float f;
	char str[20];
};

int main()
{
	union Data data;
	data.i = 10;
	data.f = 220.5;
	strcpy(data.str, "C Programming");

	printf("data.i : %d\n", data.i);
	printf("data.f : %f\n", data.f);
	printf("data.str : %s\n", data.str);
	/*
	 * 结果
	 * data.i : 1917853763
	 * data.f : 4122360580327794900000000000000.000000
	 * data.str : C Programming
	 * 可以看到共用体的i和f成员的值有损坏，因为最后赋给变量的值占用了内存位置，这也是str成员能够完全输出的原因。
	 */

	printf("----------------分隔线------------------\n");

	data.i = 10;
	printf("data.i : %d\n", data.i);

	data.f = 220.5;
	printf("data.f : %f\n", data.f);

	strcpy(data.str, "C Programming");
	printf("data.str : %s\n", data.str);
	/*
	 * 结果
	 * 这里所有的成员都能完好输出，因为同一时间只用到一个成员
	 */
		  
	return 0;
}
