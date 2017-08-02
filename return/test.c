#include<stdio.h>

int main(int argv, char *argc[])
{
	printf("Hello world!\n");
	// return的值不是随便写的，而是跟系统有关，在linux系统下，执行后返回0表示执行成功
	// 可以通过后面命令测试返回码的影响：gcc test.c -o test.out && ./test.out && echo 'success'
	return 0;
}
