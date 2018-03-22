# C 控制语句：分支和跳转

## if 语句

[colddays.c](colddays.c)

if 语句被称为**分支语句(branching statement)**或**选择语句(selection statement)**，因为它相当于一个交叉点，程序要在两条分支中选择一条执行。if 
语句的通用形式如下：

```
if (expression)
	statement
```

expression 是关系表达式，statement 可以是一条简单语句或复合语句。

## if else 语句

if else 在两条语句之间作选择。if else 语句的通用形式是：

```
if (expression)
	statement
else
	statement
```

如果要在 if 和 else 之间执行多条语句，**必须用花括号把这些语句括起来成为一个块**。下面的代码结构违反了 C 语法，因为在 if 和 else 之间只允许有
一条语句（简单语句或复合语句）。

```
if (x > 0)
	printf("Incrementing x:\n");
	x ++;
else
	printf("x <= 0 \n");
```

编译器把 printf() 语句视为 if 语句的一部分，而把`x++;`看作一条单独的语句，它不是 if 语句的一部分。然后，编译器发现 else 并没有所属的 if，这是
错误的。上面的代码应该这样写：

```
if (x > 0) {
	printf("Incrementing x:\n");
	x ++;
} else {
	printf("x <= 0 \n");
}
```

### 另一个示例：介绍 getchar() 和 putchar()

[cypher1.c](cypher1.c)

### ctype.h 系列的字符函数

[cypher2.c](cypher2.c)

### 多重选择 else if

[electric.c](electric.c)

**对于编译器的限制范围，C99 标准要求编译器最少支持 127 层嵌套**。

### else 和 if 配对

如果程序中有许多 if 和 else，编译器如何知道哪个 if 对应哪个 else？例如：

```
if (number > 6)
	if (number < 12)
		printf("You're close!\n");
else
	printf("Sorry, you lose a turn!\n");
```

何时打印`Sorry, you lose a turn!`？else 与第 1 个 if 还是第 2 个 if 匹配？答案是第 2 个。**如果没有花括号，else 与离它最近的 if 匹配**。编译器
是忽略缩进的。

### 多层嵌套的 if 语句

[divisors.c](divisor.c)

## 逻辑运算符

[chcount.c](chcount.c)

逻辑运算符：

| 逻辑运算符 | 含义 |
| :-- | :-- |
| **&&** | 与 |
| **&#124;&#124;** | 或 |
| **!** | 非 |

### 备选拼写：iso646.h 头文件

C 是在美国用标准美式键盘开发的语言。但是在世界各地，并非所有的键盘都和美式键盘一样的符号。因此，C99 标准新增了可代替逻辑运算符的拼写，它们被
定义在 ios646.h 头文件中。如果在程序中包含该头文件，便可用 and 代替 &&、or 代替 ||、not 代替 !。

### 优先级

! 运算符的优先级很高，比乘法运算符还高，与递增运算符的优先级相同，只比圆括号的优先级低。&& 运算符的优先级比 || 运算符高，但是两者的优先级都比
关系运算符低，比赋值运算符高。

### 求值顺序

除了两个运算符共享一个运算对象的情况外，C 通常不保证先对复杂表达式中哪部分求值。例如，下面的语句，可能先对表达式 5 + 3 求值，也可能先对表达式
9 + 6 求值：`apples = (5 + 3) * (9 + 6);`。

C 把先计算哪部分的决定权留给编译器的设计者，以便针对特定系统优化设计。但是，对于逻辑运算符是个例外，C 保证逻辑表达式的求值顺序是从左往右。
&& 和 || 运算符都是序列点，所以程序在从一个运算对象执行到下一个运算对象之前，所有的副作用都会生效。而且，C 保证一时发现某个元素让整个表达式
无效，便立即停止求值。所以才能写出这样结构的代码：`while ((c = getchar()) != ' ' && c != '\n')`。再考虑以下例子：`while (x ++ < 10 && x + y < 20)`。
实际上，&& 是一个序列点，这保证了在对 && 右侧的表达式求值之前，已经递增了 x。

### 范围

&& 运算符可用于测试范围。例如，要测试 score 是否在 90～100 的范围内，可以这样写：

```
if (range >= 90 && range <= 100)
	printf("Good show!\n");
```

## 一个统计单词的程序

编写一个统计单词数量的程序。该程序还可以计算字符和行数。先编写伪代码：

```
读取一个字符
当有更多输入时
	递增字符计数
	如果读完一行，递增行数计数
	如果读完一个单词，递增单词计数
	读取下一个字符
```

[wordcnt.c](wordcnt.c)

## 条件运算符

C 提供**条件表达式(conditional expression)**作为表达 if else 语句的一种便捷方式，该表达式使用`?:`条件运算符，称为三元运算符。该运算符分为两部分，需要 3 个运
算对象。条件运算符是 C 语言中唯一的三元运算符。

通用形式：`expression1 ? expression2 : expression3`。

[paint.c](paint.c)

条件运算符需要 3 个运算对象，每个运算对象都是一个表达式。

## 循环辅助：continue 和 break

continue 和 break 语句可以根据循环体中的测试结果来忽略一部分循环内容，甚至结束循环。

### continue 语句

3 种循环都可以使用 continue 语句。执行到该语句时，会跳过本次迭代的剩余部分，并开始下一轮迭代。

[skippart.c](skippart.c)

continue 还可用作占位符。例如，下面的循环读取并丢弃输入的数据，直至读到行末尾：

```
while (getchar() != '\n')
	;
```

当程序已经读到一行中的某些内容，要跳至下一行开始处时，这种用法很方便。问题是，一般很难注意到一个单独的分号。如果使用 continue，可读性会更高：

```
while (getchar() != '\n')
	continue;
```

### break 语句

程序执行到循环中的 break 语句时，会终止包含它的循环，并继续执行下一阶段。

[break.c](break.c)

## 多重选择：switch 和 break

[animals.c](animals.c)

### switch 语句

要对紧跟在 switch 后圆括号中的表达式求值。然后程序扫描**标签**（这里指，`case 'a':`、`case 'b':`等）列表，直到发现一个匹配的值为止。然后程序
跳转到那一行。如果没有匹配的标签怎么办？如果有`default:`标签行，就跳转至该行；否则，程序继续执行在 switch 后面的语句。

break 语句在其中的作用：让程序离开 switch 语句，跳至 switch 语句后面的下一条语句。如果没有 break 语句，就会从匹配标签开始执行到 switch 末尾。

break 语句可用于循环和 switch 语句中，但是 continue 只能用于循环中。尽管如此，如果 switch 语句在一个循环中，continue 可作为 switch 语句的一部
分。

**switch 在圆括号中的测试表达式的值应该是一个整数值（包括 char 类型）。case 标签必须是整数类型（包括 char 类型）的常量或整型常量表达式（即，
表达式中只包含整型常量）。**不能用变量作为 case 标签。

### 只读每行的首字符

[animals.c](animals.c)的另一个独特之处是它读取输入的方式。它采取了丢弃一行中其他字符的行为，这种行为经常出现在响应单字符的交互程序中。可以用
下面的代码实现这样的行为：

```
while (getchar() != '\n')
	continue;  /* 跳过输入行的其余部分 */
```

循环从输入中读取字符，包括按下 Enter 键产生的换行符。以上代码所做的只是读取并丢弃字符。由于最后丢弃的字符是换行符，所以下一个被读取的字符是下
一行的首字母。

### 多重标签

[vowels.c](vowels.c)

### switch 和 if else

如果根据浮点类型的变量或表达式来选择时，就无法使用 switch；如果根据变量在某范围内决定程序流的去向，使用 switch 就很麻烦。

## goto 语句

没有 goto 语句 C 程序也能运行良好。Kernighan 和 Ritchie 提到 goto 语句"易被滥用"，并建议"谨慎使用，或者根本不用"。

goto 语句有两部分：goto 和标签名。标签的全名遵循变量命名规则。如下：

```
goto part2;
```

要让这条语句正常工作，函数还必须包含另一条标为 part2 的语句，该语句以标签名后紧跟一个冒号开始：

```
part2: printf("Refined analysis:\n");
```

### 避免使用 goto

goto 的常见情况：

1.	处理包含多条语句的 if 语句：
	
	```
	if (size > 12)
		goto a;
	goto b;
	a: cost = cost * 1.05;
	flag = 2;
	b: bill = cost * flag;
	```

	等价于：

	```
	if (size > 12) {
		cost = cost * 1.05;
		flag = 2;
	}
	bill = cost * flag;
	```

2.	二选一：

	```
	if (ibex > 14)
		goto a;
	sheds = 2;
	goto b;
	a: sheds = 3;
	b: help = 2 * sheds;
	```

	等价于：

	```
	if (ibex > 14)
		sheds = 3;
	else
		sheds = 2;
	help = 2 * sheds;
	```

3.	创建不确定循环：

	```
	readin: scanf("%d", &score);
	if (score < 0)
		goto stage2;
	lots of statements
	goto readin;
	stage2: more stuff;
	```

	等价于：

	```
	scanf("%d", &score);
	while (score <= 0) {
		lots of statements
		scanf("%d", &score);
	}
	more stuff;
	```

4.	跳转至循环末尾，并开始下一轮迭代。C 使用 continue 语句代替；

5.	跳出循环。C 使用 break 语句。实际上，break 和 continue 是 goto 的特殊形式。使用 break 和 continue 的好处是：其名称已经表明它们的用法，而且
	这些语句不使用标签，所以不用担心把标签放错位置导致的危险；

6.	胡乱跳转至程序的不同部分。简而言之，不要这样做！

但是，C 程序员可以接受一种 goto 的用法——出现问题时从一组嵌套循环中跳出（一条 break 语句只能跳出当前循环）：

```
while (funct > 0) {
	for (i = 1; i <= 100; i ++) {
		for (j = 0; j <= 50; j ++) {
			其他语句
			if (问题)
				goto help;
			其他语句
		}
		其他语句
	}
	其他语句
}
其他语句
help: 语句
```

过度地使用 goto 语句，会让程序错综复杂。如果不熟悉 goto 语句，就不要使用它。如果习惯使用 goto 语句，试着改掉这个毛病。
