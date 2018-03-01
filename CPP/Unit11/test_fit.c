/* test_fit.c -- 使用缩短字符串长度的函数 */
#include <stdio.h>
#include <string.h>  /* 内含字符串函数原型 */
void fit(char *, unsigned int);

int main()
{
	char mesg[] = "Things should be as simple as possible,"
				  " but not simple.";
	puts(mesg);
	fit(mesg, 38);
	puts(mesg);
	puts("Let's look at some more of the string.");
	puts(mesg + 39);

	return 0;
}

void fit(char *string, unsigned int size)
{
	if (strlen(string) > size) {
		string[size] = '\0';
	}
}
