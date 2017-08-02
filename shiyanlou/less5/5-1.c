#include<stdio.h>

int main()
{
	int a = 22;
	int b = 3;
	float c = 22.5;
	int d = 3;
	printf("%d\n", a / b);
	// printf("%d\n", c % d); // 编译时出现error表示编译未成功（出现warning表示警告，但是编译已经成功生成了可执行文件），并提示了错误内容，因此%运算符要求参加运算的对象为整数
	return 0;
}
