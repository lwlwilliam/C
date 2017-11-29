> 缓冲区

```
#include <stdio.h>
int main()
{
	char ch;
	
	while ((ch = getchar()) != '#') {
		putchar(ch);
	}

	return 0;
}
```

编译运行以上程序后，与用户的交互如下：

**Hello, there. I would[enter]**

Hello, there. I would

**like a #3 bag of potatoes.[enter]**

like a

而在老式系统运行该程序，可能交互如下：

HHeelllloo,, tthheerree.. II wwoouulldd[enter]


lliikkee aa #

老式系统这种属于**无缓冲**（或直接）输入，即正在等待的程序可立即使用输入的字符。
对于该例，大部分系统在用户按下 Enter 键之前不会重复打印刚输入的字符，这种输入形式属于**缓冲**输入。
用户输入的字符被收集并储存在一个被称为 **缓冲区(buffer)** 的临时存储区，按下 Enter 键后，程序才可使用用户输入的字符。
