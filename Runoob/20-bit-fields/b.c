#include <stdio.h>
#include <string.h>

struct
{
	unsigned int age : 3;
} Age;

int main()
{
	Age.age = 4;
	printf("Sizeof(Age) : %d\n", sizeof(Age));
	printf("Age.age : %d\n", Age.age);

	Age.age = 7;
	printf("Age.age : %d\n", Age.age);

	Age.age = 8; // 编译时会警告，越过指定位数
	printf("Age.age : %d\n", Age.age);

	return 0;
}
