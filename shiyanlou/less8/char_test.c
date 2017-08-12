#include<stdio.h>

int main()
{
	char arr[10] = {'a', 'b', 'c', '\0', 'd', 'e'};
	int i;
	int b[] = {1, 2, 3};
	char c[] = {'a', 'b', 'c'};

	printf("%s\n", c);

	char d[] = {"I love you"};
	char e[] = "I love you";
	char f[] = {'I', ' ', 'l', 'o', 'v', 'e', ' ', 'y', 'o', 'u', '\0'};

	printf("%s\n%s\n%s\n", d, e, f);

	if (d == e) {
		printf("d == e\n");
	} else {
		printf("d != e\n");
	}

	if (d == f) {
		printf("d == f\n");
	} else {
		printf("d != f\n");
	}

	if (e == f) {
		printf("e == f\n");
	} else {
		printf("e != f\n");
	}

	for (i = 0; i < 10; i ++) {
		printf("%c\n", arr[i]);
	}

	printf("%s\n", arr);

	printf("###############################################\n");

	char str1 [10] = "Hello";
	// str1 = "Hello";
	// char str2 [10] = str1; // 企图用赋值语句将一个字符数组直接赋给另一个字符数组

	printf("%s\n", str1);


	return 0;
}
