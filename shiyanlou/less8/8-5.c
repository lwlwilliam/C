#include<stdio.h>
#include<string.h> // 在使用字符串处理函数时需要引入

int main()
{
	char str[] = "China\nGuangzhou";
	char str2[20];
	gets(str2);

	puts(str);
	printf("%s\n", str2);
	
	return 0;
}
