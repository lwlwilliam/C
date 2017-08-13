#include<stdio.h>
#include<stdlib.h> // stdlib 即 standard library 标准库头文件

int main()
{
	FILE *fp;
	char ch, filename[10];
	scanf("%s", filename);
	if ((fp = fopen(filename, "w")) == NULL) { // 打开输出文件并使fp指向此文件
		printf("Unable to open this file.\n"); // 如果打开出错，就输出
		exit(0); // 终止程序
	}
	ch = getchar(); // 用来接收最后输入的回车符
	printf("please enter a string in the disk (Ends with a#) : ");
	ch = getchar(); // 接收从键盘输入的第一个字符
	while (ch != '#') { // 当输入 # 时结束循环
		fputc(ch, fp);
		putchar(ch);
		ch = getchar();
	}
	fclose(fp);
	putchar(10); // 好吧，这貌似是换行符
	// putchar(126);
	return 0;
}

/*
 * 程序分析：
 * 1. exit存在于标准C的库函数中，作用是使程序终止，用此函数时在程序的开头应包含stdlib.h头文件。
 * 2. 执行过程如下：先从键盘读入一个字符，检查它是否是"#"，如果是，表示字符串结束，不执行循环体。如果不是，则执行循环体，将该字符输出到fputc.txt。然后在屏幕上显示出该字符，接着再从键盘读入一个字符。如此反复，直到出现"#"字符为止。这时程序已经将"This is just a fputc program test."写入到以fputc.txt命名的文件中。
 */
