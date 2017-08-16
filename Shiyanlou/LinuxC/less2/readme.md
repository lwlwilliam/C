### gcc支持编译的一些源文件后缀名

| 后缀        | 源文件                   |
| :--         | :--                      |
| .c          | C语言源文件              |
| .C .cc .cxx | C++源文件                |
| .m          | Object-C源文件           |
| .i          | 经过预处理后的C源文件    |
| .ii         | 经过预处理后的C++源文件  |
| .s .S       | 汇编语言源文件           |
| .h          | 预处理文件（头文件）     |
| .o          | 目标文件                 |
| .a          | 存档文件                 |

### gcc 编译程序的流程

源文件   --->   预处理   --->   编译   --->   汇编   --->   链接   --->   可执行文件
(filename.c)  (预处理器)      (编译器)      (汇编器)      (连接器)       (excutefile)

### 用gcc编译一个经典C程序

```
// filename: hello.c
#include<stdio.h>
int main(int argc, char **argv)
{
	printf("Hello world!");
}

/* $gcc hello.c -o hello
 * 如果没有error，说明编译成功，将会在当前目录生成一个可执行文件 hello
 * 继续输入： ./hello 就会运行该程序，在bash上打印出 Hello world!
 */
```

### gcc到底背着我们做了什么

首先gcc会调用预处理程序cpp，由它负责展开在源程序中定义的宏（上例：#include），向其中插入#include语句所包含的内容（原地展开stdio.h包含的代码）。

```
$gcc -E hello.c -o hello.i
```

hello.i是一个经过预处理器处理之后的C源文件。gcc的-E参数可以让gcc有预处理后结束停止编译过程。

第二步，将hello.i编译为目标代码，gcc默认将.i文件看成是预处理后的C语言源代码，因此它会直接跳过预处理，开始编译过程。

```
$gcc -c hello.i -o hello.o
```

经过第二步处理，hello.o已经是二进制文件了。

**请记住，gcc预处理源文件的时候（第一步），不会进行语法错误的检查。语法检查会在第二步进行，比如花括号不匹配、行末尾没有分号、关键字错误...**

第三步，gcc连接器将目标文件链接为一个可执行文件，一个大致的编译流程结束。

```
$gcc hello.o -o hello
```

### gcc编译模块化的程序

现在很多软件都是采用的模块化开发，通常一个程序都是有很多个源文件组成，相应的就形成了多个编译单元。gcc能够很好的处理这些编译单元，最终形成一个可执行程序。

```
// hello.h：这是头文件，将会在hello_main.c中调用
extern void print();

// hello_printf.c
#include<stdio.h>
void print()
{
	printf("Hello world!");
}

// hello_main.c
#include "hello.h"
void print();
int main(int argc, char **argv)
{
	print();
}
```

以上文件用`gcc hello_print.c hello_main.c -o hello`进行编译，可以看成是三条命令的合成：
```
$gcc -c hello_print.c -o hello_print.o
$gcc -c hello_main.c -o hello_main.o
$gcc hello_print.o hello_main.o -o hello
```
