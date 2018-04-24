
/* 一些无效的数组赋值 */
#include <stdio.h>
#define SIZE 5
int main()
{
	int oxen[SIZE] = {5, 3, 2, 8};  // 初始化没问题
	int yaks[SIZE];

	yaks = oxen;  // 不允许
	yaks[SIZE] = oxen[SIZE];  // 数组下标越界
	yaks[SIZE] = {5, 3, 2, 8};  // 不起作用

	return 0;
}
