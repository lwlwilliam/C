/* echo_eof.c -- 重复输入，直到文件结尾 */
#include <stdio.h>
int main()
{
	int ch;

	while ((ch = getchar()) != EOF) {
		putchar(ch);
	}
	
	return 0;
}
