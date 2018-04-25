# 字符输入/输出和输入验证

最初，输入/输出函数不是 C 定义的一部分，C 把开发这些函数的任务留给编译器的实现者来完成。在实际应用中，UNIX 系统中的 C 实现为这些函数提供了一
个模型。ANSI C 库吸取成功的经验，把大量的 UNIX/C 函数囊括其中。由于必须保证这些标准函数在不同的计算机环境中能正常工作，所以它们很少使用某些特
殊系统才有的特性。因此，许多 C 供应商会利用硬件的特性，额外提供一些 I/O 函数。其他函数或函数系列需要特殊的操作系统支持，如 Windows 或 Mac OS 
的特殊图形界面。这些有针对性、非标准的函数让程序员能更有效地使用特定计算机编写程序。

## 单字符 I/O：getchar() 和 putchar()

getchar() 和 putchar() 每次只处理一个字符。这是绝大多数文本（即，普通文字）处理程序所用的核心方法。

[echo.c](echo.c)

其实，getchar() 和 putchar() 都不是真正的函数，它们被定义为供预处理使用的宏。

## 缓冲区

编译运行[echo.c](echo.c)程序后，与用户的交互如下：

```
Hello, there. I would[enter]
Hello, there. I would
like a #3 bag of potatoes.[enter]
like a
```

而在老式系统运行该程序，可能交互如下：

```
HHeelllloo,, tthheerree.. II wwoouulldd[enter]

lliikkee aa #
```

老式系统这种属于**无缓冲(或直接)**输入，即正在等待的程序可立即使用输入的字符。对于该例，大部分系统在用户按下 Enter 键之前不会重复打印刚输入的
字符，这种输入形式属于**缓冲**输入。用户输入的字符被收集并储存在一个被称为**缓冲区(buffer)**的临时存储区，按下 Enter 键后，程序才可使用用户输入
的字符。

为什么要有缓冲区？首先，把若干字符作为一个块进行传输比逐个发送这些字符节约时间。其次，如果用户打错字符，可以直接通过键盘修正错误。当最后按
下 Enter 键时，传输的是正确的输入。

虽然缓冲输入好处很多，但是某些交互式程序也需要无缓冲输入。例如，在游戏中，你希望按下一个键就执行相应的指令。

缓冲分为两类：**完全缓冲 I/O**和**行缓冲 I/O**。完全缓冲输入批的是当缓冲区被填满时才刷新缓冲区（内容被发送至目的地），通常出现在文件输入中。
缓冲区大小取决于系统，常见大小是 512 字节和 4096 字节。行缓冲 I/O 指的是在出现换行符时刷新缓冲区。键盘输入通常是行缓冲输入，所以在按下 Enter 键
后才刷新缓冲区。

ANSI C 和后续的 C 标准都规定输入是缓冲的，不过最初 K&R 把这个决定权交给了编译器的编写者。ANSI C 决定把缓冲输入作为标准的原因是：一些计算机不
允许无缓冲输入。

**回显输入**意味着用户输入的字符直接显示在屏幕上，**无回显输入**意味着击键后对应的字符不显示。

## 结束键盘输入

### 文件、流和键盘输入

**文件(file)**是存储器中储存信息的区域。通常，文件都保存在某种永久存储器中（如，硬盘、U 盘或 DVD 等）。

C 是一门强大、灵活的语言，有许多用于打开、读取、写入和关闭文件的库函数。从较低层面上，C 可以使用主机操作系统的基本文件工具直接处理文件，这些
直接调用操作系统的函数被称为**底层 I/O(low-level I/O)**。由于计算机系统各不相同，所以不可能为普通的底层 I/O 函数创建标准库。然而从较高层面上，
C 还可以通过**标准 I/O 包(standard I/O package)**来处理文件。这涉及创建用于处理文件的标准模型和一套歀 I/O 函数。在这一层面上，具体的 C 实现负
责处理不同系统的差异，以便用户使用统一的界面。

从概念上看，C 程序处理的是流而不是直接处理文件。**流(stream)**是一个实际输入或输出映射的理想化数据流。这意味着不同属性和不同种类的输入，由属性
更统一的流来表示。于是，打开文件的过程就是把流与文件相关联，而且读写都通过流来完成。

### 文件结尾

检测文件结尾的一种方法是，在文件末尾放一个特殊的字符标记文件结尾。操作系统可以使用内嵌的 Ctrl+Z 字符来标记文件结尾。这曾是操作系统使用的唯一
标记，不过现在有一些其他的选择，例如记录文件的大小。所以现代的文本文件不一定有嵌入的 Ctrl+Z，但是如果有，将被视为一个文件结尾标记。

另一种方法是储存文件大小的信息。如果文件在 3000 字节，程序在读到 3000 字节时便达到文件的末尾。

无论操作系统实际使用何处方法检测文件结尾，在 C 语言中，用 getchar() 读取文件检测到文件结尾时将返回一个特殊的值，即**EOF(end of file)**。
scanf() 函数检测到文件结尾时也返回 EOF。通常，EOF 定义在 stdio.h 文件中：`define EOF (-1)`。为什么是 -1？因数 getchar() 函数的返回值通常都介
于 0～127，这些值对应标准字符集。但是，如果系统能识别扩展字符集，该函数的返回值可能在 0～255 之间。无论哪种情况，-1 都不对应任何字符，所以，
该值可用于标记文件结尾。某些系统也许把 EOF 定义为 -1 以外的值，但是定义的值一定与输入字符所产生的返回值不同。如果包含 stdio.h 文件，并使用 EOF 
符号，就不必担心 EOF 值不同的问题。这里关键要理解 EOF 是一个值，标志着检测到文件结尾，并不是在文件中找得到的符号。

如果正在读取的是键盘输入而不是文件，绝大部分系统（不是全部）都有办法通过键盘模拟文件结尾条件。

[echo_eof.c](echo_eof.c)

注意以下几点：

*	不用定义 EOF，因数 stdio.h 中已经定义了；

*	不用担心 EOF 的实际值，因为 EOF 在 stdio.h 中用 `#define` 预处理指令定义，可直接使用，不必再编写代码假定 EOF 为某值；

*	**变量 ch 的类型从 char 变为 int，因为 char 类型的变量只能表示 0～255 的无符号整数，但是 EOF 的值是 -1。还好，getchar() 函数实际返回值的类型
	是 int，所以它可以读取 EOF 字符。如果实现使用有符号的 char 类型，也可以把 ch 声明为 char 类型，但最好还是用更通用的形式**；

*	由于 getchar() 的返回类型是 int，如果把 getchar() 的返回值赋给 char 类型的变量，一些编译器会警告可能丢失数据；

*	ch 是整数不会影响 putchar()，该函数仍然会打印出等价的字符；

*	使用该程序进行键盘输入，要设法输入 EOF 字符。在大多数 Unix 和 Linux 系统中，在一行开始处按下 Ctrl+D 会传输文件结尾信号；

既然[echo_eof.c](echo_eof.c)程序能把用户输入的内容拷贝到屏幕上，那么它还可以做什么？假设以某种方式把一个文件传送给它，然后它把文件中的内容打印
在屏幕上，当到达文件结尾发现 EOF 信号时停止。或者假设以某种方式把程序的输出定向到一个文件，然后通过键盘输入数据，用[echo_eof.c](echo_eof.c)来
储存在文件中输入的内容。假设同时使用这两种方法：把输入从一个文件定向到[echo_eof.c](echo_eof.c)中，并把输出发送至另一个文件，然后便可以使用
[echo_eof.c](echo_eof.c)来拷贝文件。这个小程序有查看文件内容、创建一个新文件、拷贝文件的潜力。关键是控制输入流和输出流。

## 重定向和文件

默认情况下，C 程序使用标准 I/O 包查找标准输入作为输入源，也就是 stdin 流，它是把数据读入计算机的常用方式。

程序可以通过两种方式使用文件。第 1 种方法是，显式使用特定函数打开文件、关闭文件、读取文件、写入文件，诸如此类。第 2 种方法是，设计能与键盘和
屏幕互动的程序，通过不同的渠道**重定向**输入到文件和从文件输出。换言之，把 stdin 流重新赋给文件。

重定向的一个主要问题与操作系统有关，与 C 无关。

### Unix、Linux 和 DOS 重定向

重定向输入让程序使用文件而不是键盘来输入，重定向输出让程序输出至文件而不是屏幕。

#### 重定向输入

**文本文件(text file)**是内含文本的文件，其中储存的数据是我们可识别的字符。内含机器语言指令的文件（如储存可执行程序的文件）不是文本文件。

编译[echo_eof.c](echo_eof.c)程序为 echo_eof 可执行程序。运行该程序：`./echo_eof`。该程序获取用户从键盘输入的输入。现在要处理
[redirect_in](redirect_in)文本文件。

执行以下命令：

```
$ ./echo_eof < redirect_in
redirect_in
abc
def
ghi
```

`<`符号是 Unix 和 DOS/Windows 的重定向运算符。该运算符使[redirect_in](redirect_in)文件与 stdin 流相关联，把文件中的内容导入 echo_eof 程序。程序
读取[redirect_in](redirect_in)的内容并逐字打印在屏幕上，直至读到文件结尾。因为 C 把文件和 I/O 设备放在一个层面，所以文件就是现在的 I/O 设备。

#### 重定向输出

假设要用上面生成的 echo_eof 程序把键盘输入的内容发送到名为[redirect_out](redirect_out)的文件中。执行以下命令：

```
$ ./echo_eof > redirect
redirect_out
abc
def
ghi
[Ctrl+D]
```

`>`符号是第 2 个重定向运算符。该命令创建了一个名为[redirect_out](redirect_out)的新文件，然后把 echo_eof 的输出（即输入字符的副本）重定向至
该文件中。重定向把 stdout 从显示设备（即显示器）赋给[redirect_out](redirect_out)文件。如果已经有一个名为[redirect_out](redirect_out)的文件，
通常会擦除该文件的内容，然后替换新的内容。所有出现在屏幕的字母都是刚刚输入的，其副本储存在文件中。记住在每行的末尾单击 Enter 键，这样才能把
缓冲区的内容发送给程序。

#### 组合重定向

假设要制作一份[redirect_out](redirect_out)文件的副本，并命名为[redirect_out_copy](redirect_out_copy)。只需输入以下命令即可：

```
$ ./echo_eof < redirect_out > redirect_out_copy
```

或者

```
$ ./echo_eof > redirect_out_copy < redirect_out
```

注意，同一命令中，输入和输出文件名不能相同。
原因是`>`在输入之前已导致原文件长度被截断为 0。

使用重定向运算符时，要遵循以下原则：

* 重定向运算符连接一个`可执行`程序和一个数据文件，不能用于连接一个数据文件和另一个数据文件，也不能用于连接一个程序和另一个程序；

* 使用重定向运算符不能读取多个文件的输入，也不能把输出定向至多个文件；

* 通常，文件名和运算符之间的空格不是必须的，除非是偶尔在 Unix shell、Linux shell 或 Windows 命令行提示模式中使用的有特殊含义的字符；

#### 注释

如果用不了重定向，可以用程序直接打开文件。以下演示一个注释较少的示例。待读取的文件应该与可执行文件位于同一目录。

[file_eof.c](file_eof.c)

## 创建更友好的用户界面

C 提供了大量工具让输入更顺畅，处理过程更顺利。不过，学习这些工具会导致新的问题。创建更友好的界面，让交互数据输入更方便，减少错误输入的影响。

### 使用缓冲输入

缓冲输入用起来比较方便，因为在把输入发送给程序之前，用户可以编辑输入。但是，在使用输入的字符时，它也会给程序员带来麻烦。前面示例中看到的问题
是，缓冲输入要求用户按下 Enter 键发送输入。这一动作也传送了换行符，程序必须妥善处理这个麻烦的换行符。以一个猜谜程序为例。用户选择一个数字，
程序猜用户选中的数字是多少。该程序使用的方法单调乏味，先不要在意算法，我们关注的重点是输入和输出。以下是猜谜程序的最初版本，后面会改进，[guess.c](guess.c)。

编译运行该例子：

```
$ ./guess
Pick an integer from 1 to 100. I will try to guess it.
Respond with a y if my guess is right and with
an n if it is wrong.
Uh...is your number 1?
n
Well, then, is it 2?
Well, then, is it 3?
y
I knew I could do it!
```

撇开该程序糟糕的算法不谈。每次输入 n 时，程序打印了两条消息。这是由于程序读取 n 作为用户否定了数字 1，然后还读了一个换行符作为用户否定了数字 2。

一种解决方案是，使用 while 循环丢弃输入行最后剩余的内容，包括换行符。这种方法的优点是，能把 no 和 no way
这样的响应视为简单的 n。

```
while (getchar() != 'y') {  /* 获取响应，与 y 做对比 */
    printf("Well, then, is it %d?\n", ++ guess);
    while (getchar() != '\n') {
        continue;  /* 跳过剩余的输入行 */
    }
}
```

这的确解决了换行符的问题。但是，该程序还是会把 f 视为 n。我们用 if 语句筛选其他响应。
首先，添加一个 char 类型的变量储存响应：

```
char response;
while ((response = getchar()) != 'y') {  /* 获取响应 */
    if (response != 'n') {
        printf("Sorry, I understand only y or n.\n");
    }

	printf("Well, then, is it %d?\n", ++ guess);

    while (getchar() != '\n') {
        continue;  /* 跳过剩余的输入行 */
    }
}
```

改进后版本[guess_improve.c](guess_improve.c)。

### 混合数值和字符输入

假设程序要求用 getchar() 处理字符输入，用 scanf() 处理数值输入，这两个函数都能很好地完成任务，但是不能把它们混用。因为 getchar() 读取
每个字符，包括空格、制表符和换行符；而 scanf() 在读取数字时则会跳过空格、制表符和换行符。

以下程序[showchar1.c](showchar1.c)可以解释这种情况导致的问题。该程序读入一个字符和两个数字，然后根据输入的两个数字指定的行数和列数打印
该字符。**该程序有较大的 I/O 问题**。

注意，该程序以 int 类型读取字符（这样可以检测 EOF），但是却以 char 类型把字符传递给 display() 函数。因为 char 比 int 小，一些编译器会
给出类型转换的警告。可以忽略警告，或者用强制类型转换消除警告：`display(char(ch), rows, cols)`;

运行示例：

```
$ ./showchar1
Enter a character and two integers:
c 2 3
ccc
ccc
Enter another character and two integers;
Enter a newline to quit.
Bye
```

发现程序只运行一次就退出了，又是换行符在捣乱，因为在 3 后面有换行号。scanf() 函数把换行符留在输入队列中，和 scanf() 不同，getchar() 不
会跳过换行符，所以在进入下一轮迭代时，还没来得及输入字符，就读取了换行符。

要解决这个问题，程序要跳过一轮输入结束与下一轮输入开始之间的所有换行符或空格。另外，如果该程序不在 getchar() 测试时，而在 scanf() 阶段
终止程序会更好。修改版[showchar2.c](showchar2.c)

while 循环实现了丢弃 scanf() 输入后面所有字符（包括换行符）的功能，为循环的下一轮读取做好了准备。

## 输入验证

[checking.c](checking.c)

### 分析程序

程序遵循模块化的编程思想，使用独立函数（模块）来验证输入和管理显示。程序越大，使用模块化编程就越重要。

main() 函数管理程序流，为其他函数委派任务。它使用 get_long() 获取值、while 循环处理值、badlimits() 函数检查值是否有效、
sum_squres() 函数处理实际的计算。

### 输入流和数字

在编写处理错误输入的代码时，应该很清楚 C 是如何处理输入的。考虑下面的输入：`is 28 12.4`。
在我们眼中，这就像是一个由字符、整数和浮点数组成的字符串。但是对 C 程序而言，这是一个字节流。
第 1 个字节是字母 i 的字符编码，第 2 个字节是字母 s 的字符编码，第 3 个字节是空格字符的字符编码，
第 4 个字节是数字 2 的字符编码，等等。所以以上的 checking.c 中 get_long() 处理这一行输入，
第 1 个字符是非数字，那么整行输入都会被丢弃。


## 菜单浏览

许多计算机程序都把菜单作为用户界面的一部分。菜单给用户提供方便的同时，却给程序员带来了一些麻烦。

菜单给用户提供了一份响应程序的选项。假设有下面一个例子：

```
Enter the letter of your choice:
a. advice		b. bell
c. count		q. quit
```

理想状态是，用户输入程序所列选项之一，然后程序根据用户所选项完成任务。
为了这一过程能顺利进行，因此：
第 1 个目标是：当用户遵循指令时程序顺利运行；
第 2 个目标是：当用户没有遵循指令时，程序也能顺利运行。

现在的应用程序通常使用图形界面，可以点击按钮、查看对话框、触摸图标，而不是示例中的命令行模式。
但是，两者的处理过程大致相同：给用户提供选项、检查并执行用户的响应、保护程序不受误操作的影响。
除了界面不同，它们底层的程序结构也几乎相同。但是，使用图形界面更容易通过限制选项控制输入。

### 任务

我们来更具体地分析一个菜单程序需要执行哪些任务。它要获取用户的响应，根据响应选择要执行的动作。
另外，程序应该提供返回菜单的选项。C 的 switch 语句是根据选项决定行为的好工具，用户的每个选择都可以对应一个特定的 case 标签。
使用 while 语句可以实现重复访问菜单的功能。因此，写出以下伪代码：

```
获取选项
当选项不是'q'时
	转至相应的选项并执行
	获取下一个选项
```

### 使执行更顺利

当决定实现这个程序时，就要开始考虑如何让程序顺利运行（顺利运行指的是，处理正确输入和错误输入时都能顺利运行）。
例如，你能做的是让“获取选项”部分的代码筛选掉不合适的响应，只把正确的响应传入 switch。
这表明需要为输入过程提供一个只返回正确响应的函数。结合 while 循环和 switch 语句，程序结构如下：

```
#
```

定义 get_choice() 函数只能返回'a'、'b'、'c'和'q'。
get_choice() 的用法和 getchar() 相同，两个函数都是获取一个值，并与终止值（该例中是'q'）作比较。
default 语句可以方便调试。
如果 get_choice() 函数没能把返回值限制为菜单指定的几个选项值，default 语句有助于发现问题所在。

下面伪代码是设计 get_choice() 函数的一种方案

```
显示选项
获取用户的响应
当响应不合适时
	提示用户再次输入
	获取用户的响应
```

以下是一个简单而笨拙的实现：

```
/* get_choice() */
```