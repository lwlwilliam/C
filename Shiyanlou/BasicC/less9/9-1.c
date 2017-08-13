#include<stdio.h>

int main()
{
	void printstar(); // 声明printstar函数
	void printmsg(); // 声明printmsg函数
	printstar();
	printmsg();
	printstar();
	return 0;
}

void printstar()
{
	printf("*************\n");
}

void printmsg()
{
	printf("how do you do\n");
}

/*
 * 程序分析：printstar()和printmsg()是自定义函数，在定义时指定函数的类型为void。
 * 在程序中，定义printstar和printmsg函数位置在main函数后，这时候，应该在main函数之前或main函数中的开头部分，对以上两个函数进行“声明”。函数声明的作用是把有关函数的信息（函数名、函数类型、函数参数的个数与类型）通知编译系统，以便于在编译系统对程序进行编译时，在进行到main函数调用printstar和printmsg时知道它们是函数而不是变量或其他对象。
 */
