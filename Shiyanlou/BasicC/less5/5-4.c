#include<stdio.h>
// 把大写字母转为小写
int main()
{
	char c1, c2;
	printf("Please enter a capital letter: ");
	scanf("%c", &c1);
	c2 = c1 + 32;
	printf("%c\n", c2);
	return 0;
}