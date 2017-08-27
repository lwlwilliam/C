#include <stdio.h>

int main()
{
	char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

	char str[] = {'W', 'o', 'r', 'l', 'd', '\0'}; // 有个疑惑，不加'\0'的话输出World后还会加上Hello

	printf("Greeting message: %s\n", greeting);
	printf("%s\n", str);

	return 0;
}
