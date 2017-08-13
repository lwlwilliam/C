#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	// 存储输入的摄氏温度
	int input = 0;
	float output;

	// 判断是否输入1个参数
	if (argc != 2) {
		return 1;
	}

	// 注意 argv[0]是执行的程序，argv[1]是第1个参数
	input = atoi(argv[1]);
	output = 32 + input * 1.8;	

	printf("%.1f\n", output);
	return 0;
}
