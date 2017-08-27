#include <stdio.h>

int main()
{
	char c;
	printf("输入一个字符：");

	// 读取用户输入
	scanf("%c", &c);

	printf("%c的ASCII为 %d\n", c, c);
	return 0;
}
