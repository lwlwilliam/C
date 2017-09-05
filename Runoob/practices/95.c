#include <stdio.h>
// 简单的结构体应用

struct programming
{
	float constant;
	char *pointer;
};

int main()
{
	struct programming variable;
	char string[] = "Github: https://github.com";
	
	variable.constant = 1.23;
	variable.pointer = string;
	
	printf("%f\n", variable.constant);
	printf("%s\n", variable.pointer);

	return 0;
}
