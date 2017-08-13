#include<stdio.h>

int main()
{
	char c;
	printf("Input an uppercase letter: \n");
	c = getchar();
	putchar(c+32); // 把大小写转为小写
	putchar('\n');
	return 0;
}
