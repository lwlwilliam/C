// 利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。

#include <stdio.h>

int main()
{
	int i = 5;
	void palin(int n);
	printf("请输入5个字符\40:\40");
	palin(i);
	printf("\n");
}

void palin(int n)
{
	char next;
	if (n <= 1) {
		next = getchar();
		printf("相反顺序输出结果\40:\40");
		putchar(next);
	} else {
		next = getchar();
		palin(n - 1);
		putchar(next);
	}
}
