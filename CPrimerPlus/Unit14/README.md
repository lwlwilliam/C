### 结构和其他数据形式

设计程序时，最重要的步骤之一是选择表示数据的方法。在许多情况下，简单变量甚至是数组还不够。
为此，C 提供了 **结构变量(structure variable)** 提高表示数据的能力，以此可以创造新的形式。

> 示例问题：创建图书目录

代码：book.c

程序清单 book.c 中创建的结构有 3 部分，每个部分都称为 **成员(member)** 或 **字段(field)**。
一部分储存书名，一部分储存作者名，一部分储存价格。下面是必须掌握的 3 个技巧：

* 为结构建立一个格式或样式
* 声明一个适合该样式的变量
* 访问结构变量的各个部分

> 建立结构声明

**结构声明(structure declaration)** 描述了一个结构的组织布局。声明类似下面这样：

```
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
```

该声明描述了一个由两个字符数组和一个 float 类型变量组成的结构。该声明并未创建实际的数据对象，
只描述了该对象由什么组成。（有时，结构声明也称为模板。）

细节：关键字 struct，它表明在其后的是一个结构，后面是一个可选的 **标记**（该例中是 book），
稍后程序中可以使用该标记引用该结构。所以，在后面的程序中可以这样声明：`struct book library;`。

这把 library 声明为一个使用 book 结构布局的结构变量。

在结构声明中，用一对花括号括起来的是结构成员列表。每个成员都用自己的声明来描述。
成员可以是任意一种 C 的数据类型，其至可以是其他结构！右花括号后面的分号是声明所必需的，
表示结构布局定义结束。

结构的标记名是可选的。但是以程序示例中的方式建立结构时（在一处定义结构布局，在另一处
定义实际的结构变量），必须使用标记。


> 定义结构变量

**结构** 有两层含义。一层含义是“结构布局”，结构布局告诉编译器如何表示数据，但是它并未让
编译器为数据 **分配** 空间。下一步是创建一个 **结构变量**，即是结构的另一层含义。
在程序中创建结构变量的一行是：`struct book library`。

在结构变量的声明中，`struct book`所起的作用相当于一般声明中的 int 或 float。例如，
中以定义两个`struct book`类型的变量：`struct book doyle, panshin, *ptbook;`。
从本质上看，book 结构声明创建了一个名为`struct book`的新类型。

就计算机而言，下面的声明：

```
struct book library;

// 相当于以下声明的简化

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
} library;  /* 声明的右花括号后跟变量名 */
```

换言之，声明结构的过程和定义结构变量的过程可以组合成一个步骤。如下所示，组合后的结构声明和
结构变量定义不需要使用结构标记：

```
struct { /* 无结构标记 */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
} library;
```

然而，如果打算多次使用结构模板，就要使用带标记的形式。

>> 初始化结构

初始化一个结构变量与初始化数组的语法类似：

```
struct book library = {
	"The Pious Pirate and the Devious Damsel",
	"Renee Vivotte",
	1.95
};
```

>> 访问结构成员

使用结构成员运算符——点(.)访问结构中的成员。例如，library.value 即访问 library 的 value 部分。
本质上，.title、.author 和 .value 的作用相当于book 结构的下标。

>> 结构的初始化器

C99 和 C11 为结构提供了指定初始化器(designated initializer)，其语法与数组的指定初始化器类似。
但是，结构的指定初始化器使用点运算符和成员名标识特定的元素。例如，只初始化 book 结构的 value 成员，
可以这样做：`struct book surprise = { .value = 10.99 };`。可以按照任意顺利使用指定初始化器：

```
struct book gift = {
	.value = 25.99,
	.author = "James Broadfool",
	.title = "Rue for the Toad"
};
```


> 结构数组

代码：manybook.c

**结构和内存**：manybook.c 程序创建了一个内含 100 个结构变量的数组。由于该数组是自动存储类别的对象，
其中的信息被储存在栈(stack)中。如此大的数组需要很大一块内存，这可能会导致一些问题，如果在运行时出现错误，
可能抱怨栈太小或栈溢出，编译器可能使用了一个默认大小的栈，这个栈对于该例而言太小。要修正这个问题，
可以使用编译器选项设置栈大小，或者创建静态或外部数组（这样，编译器就不会把数组放在栈中），又或者减小
数组大小。

>> 声明结构数组

demo: `struct book library[MAXBKS];`

以上代码把 library 声明为一个内含 MAXBKS 个元素的数组。数组的每个元素都是一个 book 类型的数组。

>> 标识结构数组的成员

为了标识结构数组中的成员，可以采用访问单独结构的规则：在结构名后面加一个点运算符，再在点运算符后面写上成员名。
如下所示：

```
library[0].value  // 第 1 个数组元素与 value 相关联
library[4].title  // 第 5 个数组元素与 title 相关联
```

总结一下：

```
library              // 一个 book 结构的数组
library[2]           // 一个数组元素，该元素是 book 结构
library[2].title     // 一个 char 数组（library[2] 的 title 成员）
library[2].title[4]  // 数组中 library[2] 元素的 title 成员的一个字符
```

>> 程序讨论

一个 while 循环读取多个项。该循环的条件测试是：

```
while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
```

表达式`s_gets(library[count].title, MAXTITL)`读取一个字符串作为书名，如果 s_gets() 尝试读取文件结尾后面，
该表达式返回 NULL。表达式`library[count].title[0] != '\0'`判断字符串中的首字符是否空字符（即，该字符串是否空字符串）。
如果在一行开始处用户按下 Enter 键，相当于输入了一个空字符串，循环将结束。程序还检查了图书的数量，以免超出数组大小。
然后，该程序有如下代码：`while (getchar() != '\n') { continue; }`。这段代码弥补了 scanf() 遇到空格和换行符就结束
读取的问题。例如用户可能输入如下信息：`12.50[Enter]`，其传送的字符序列如下：`12.50\n`，scanf() 接受 `12.50`，
但是把`\n`留在输入序列中。如果没有上面的两行清理输入行代码，就会把留在输入序列中的换行符当作空行读入，程序以为用户发送
了停止输入的信息。


> 嵌套结构

有时，在一个结构中包含另一个结构（即嵌套结构）很方便。

代码：friend.c

访问嵌套结构的成员，需要使用两次点运算符。

> 指向结构的指针

就像指向数组的指针比数组本身更容易操控（如，排序问题）一样，指向结构的指针通常比结构本身更容易操控。
在一些早期的 C 实现中，结构不能作为参数传递给函数，但是可以传递指向结构的指针。
即使能传递一个结构，传递指针通常更有效率。
一些用于表示数据的结构中包含指向其他结构的指针。

代码：friends.c

>> 声明和初始化结构指针

声明结构指针：`struct guy *him;`，语法和其他指针声明一样。指针 him 现在可以指向任意现有的 guy 类
型的结构。例如，如果 barney 是一个 guy 类型的结构，可以这样写：`him = &barney;`。和数组不同的是，
结构名并不是结构的地址，因此要在结构名前面加上 & 运算符。

>> 用指针访问成员

1. 使用`->`运算符：
   如果`him == &barney`，那么`him->income`即是`barney.income`，
   如果`him == &fellow[0]`，那么`him->income`即是`fellow[0].income`，
   换句话说，`->`运算符后面的结构指针和`.`运算符后面的结构名工作方式相同。
2. 以这样的顺序指定结构成员的值：
   如果`him == &fellow[0]`，那么`*him == fellow[0]`，因此，可以做以下替代：
   `fellow[0].income == (*him).income`，
   必须要使用圆括号，因为`.`运算符比`*`运算符的优先级高。
  
总之，如果 him 是指向 guy 类型结构 barney 的指针，下面的关系恒成立：
`barney.income == (*him).income == him->income  // 假设 him == &barney`


> 向函数传递结构的信息

由于一个结构比一个单独的值复杂，以前的 C 实现不允许把结构作为参数传递给函数。当前的实现已经移除了这个限制，
ANSI C 允许把结构作为参数使用。

1. 可以传递结构本身；
2. 可以传递指向结构的指针；
3. 如果只关心结构中的某一部分，也可以传递结构的成员；

>> 传递结构成员

只要结构成员是一个具有单个值的数据类型（即，int 及其相关类型、char、float、double 或指针），便可把它作为
参数传递给接受该特定类型的函数。

代码：funds1.c

>> 传递结构的地址

代码：funds2.c

该程序把地址 &stan 作为参数传递给 sum()，使得指针指向结构 stan。然后通过`->`运算符获取`stan.bankfund`和
`stan.savefund`的值。由于该函数不能改变指针所指向值的内容，所以把 money 声明为一个指向 const 的指针。

>> 传递结构

代码：funds3.c

在调用 sum() 时，编译器根据 funds 模板创建了一个名为 moolah 的自动结构变量。然后，该结构的各成员被初始化为 
stan 结构变量相应成员的值的副本。因此，程序使用原来结构的副本进行计算。而传递指针的程序 funds2.c 使用的是原
始的结构进行计算。

>> 其他结构特性

现在的 C 允许把一个结构赋值给另一个结构，但是数组不能这样做。也就是说，如果 n_data 和 o_data 是相同类型的结构，
可以这样做：`o_data = n_data; // 把一个结构赋值给另一个结构`。这条语句把 n_data 的每个成员的值都赋给 o_data 
的相应成员。即使成员是数组，也能完成赋值。另外，还可以把一个结构初始化为相同类型的另一个结构：

```
struct names right_field = {"Ruthie", "George"};
struct names captain = right_field;  // 把一个结构初始化为另一个结构
```

现在的 C（包括 ANSI C），函数不仅能把结构本身作为参数传递，还能把结构作为返回值返回。结构指针也允许这种双向通信，
因此可以选择任一种方法来解决编程问题。通过以下一组示例来演示这两种方法。

代码：names1.c 和 names2.c

>> 结构和结构指针的选择

把指针作为参数有两个优点：无论是以前还是现在的 C 实现都能使用这种方法，而且执行起来很快，只需要传递一个地址。
缺点是无法保护数据。被调用函数中的某些操作可能会意外影响原来结构中的数据。不过，ANSI C 新增的 const 限定符
解决了这个问题。

把结构作为参数传递的优点是，函数处理的是原始数据的副本，这保护了原始数据。另外，代码风格也更清楚。
缺点是较老版本的实现可能无法处理这样的代码，而且传递结构浪费时间和存储空间。尤其是把大型结构传递给函数，
而它只使用结构中的一两个成员时特别浪费。

通常，为了追求效率会使用结构指针作为函数参数，如需防止原始数据被意外修改，使用 const 限定符。按值传递结构是处理
小型结构最常用的方法。

>> 结构中的字符数组和字符指针

```
#define LEN 20
struct names {
    char first[LEN];
    char last[LEN];
};

strct pnames {
    char *first;
    char *last;
};
```

以上两种结构声明都可以，但是如果不理解这样做的含义，可能会有麻烦。考虑下面的代码：

```
struct names veep = {"Talia", "Summers"};
struct pnames treas = {"Brad", "Fallingjaw"};
printf("%s and %s\n", veep.first, treas.first);
```

以上代码没问题，也能正常运行，但是思考一下字符串被储存在何处。对于`struct names`类型的
结构变量 veep，以上字符串都储存在结构内部，结构总共要分配 40 字节储存姓名。然而，对于
`struct pnames`类型的结构变量 treas，以上字符串储存在编译器储存常量的地方。结构本身只
储存了两个地址，在我们的系统中共占 16 字节。尤其是，`struct pnames`结构 **不用为字符
串分配任何存储空间**。它使用的是储存在别处的字符串（如，字符串常量或数组中的字符串）。
简而言之，在 pnames 结构变量中的指针应该只用来在程序中管理那些已分配和在别处分配的字符串。

考虑下面的代码：

```
struct names accountant;
struct pnames attorney;
puts("Enter the last name of your accountant: ");
scanf("%s", accountant.last);
puts("Enter the last name of your attorney: ");
scanf("%s", attorney.last);  // 这里有一个潜在的危险
```

就语法而言，这段代码没问题。但是，用户的输入储存到哪里去了？对于 accountant，储存在 
accountant 结构变量的 last 成员中；对于 attorney，scanf() 把字符串放到 attorney.last 
表示的地址上。由于这是未经初始化的变量，地址可以是任意值，因此程序可以把名放在任何地方。
如果走运，程序没有问题，至少暂时不会出问题，否则这一操作会导致程序崩溃。实际上，如果程序能
正常运行并不是好事，因为这意味着一个未被察觉的危险潜伏在程序中。

>> 结构、指针和 malloc()

如果使用 malloc() 分配内存并使用指针储存该地址，那么在结构中使用指针处理字符串就比较合理。
这种方法的优点是，可以请求 malloc() 为字符串分配合适的存储空间。

代码：names3.c

>> 复合字面量和结构(C99)

C99 的复合字面量特性可用于结构和数组，如果只需要一个临时结构值，复合字面量很好用。
语法：类型名放在圆括号中，后面紧跟一个用花括号括起来的初始化列表。demo:

```
(struct book) {"The Idiot", "Fyodor Dostoyevsky", 6.99}
```

还可以把复合字面量作为函数的参数。

>> 伸缩型数组成员(C99)

C99 新增了一个特性：**伸缩型数组成员(flexible array member)**，利用这项特性声明的结构，
其最后一个数组成员具有一些特性：

1. 该数组不会立即存在；
2. 使用这个伸缩型数组成员可以编写合适的代码，就好像它确实存在并具有所需数目的元素一样；

声明一个伸缩型数组成员有如下规则：

* 伸缩型数组成员必须是结构的最后一个成员；
* 结构中必须至少有一个成员；
* 伸缩数组的声明类似于普通数组，只是它的方括号中是空的；

DEMO:

```
struct flex {
    int count;
    double average;
    double scores[];  // 伸缩型数组成员
};
```

声明一个`struct flex`类型的结构变量时，不能和 scores 做任何事，因为没有给这个数组预留存储空间。
实际上，C99 的意图并不是让你声明`struct flex`类型的变量，而是希望你声明一个指向`struct flex`
类型的指针，然后用 malloc() 分配足够的空间，以储存`struct flex`类型结构的常规内容和伸缩型数组成员
所需的额外空间。例如，假设用 scores 表示一个内含 5 个 double 类型值的数组，可以这样做：

```
struct flex *pf;  // 声明一个指针
// 请求为一个结构和一个数组分配存储空间
pf = malloc(sizeof(struct flex) + 5 * sizeof(double));
```

现在有足够的存储空间储存 count、average 和一个内含 5 个 double 类型值的数组。可以用指针 pf 访问这些成员：

```
pf->count = 5;
pf->score[2] = 18.5;
```

代码：flexmemb.c

带伸缩型数组成员的结构确实有一些特殊的处理要求。
第一，不能用结构进行赋值或拷贝；
第二，不要以按值方式把这种结构传递给结构；
第三，不要使用带伸缩型数组成员的结构作为数组成员或另一个结构的成员；

>> 匿名结构(C11)

匿名结构是一个没有名称的结构成员。

创建嵌套结构：

```
struct names
{
    char first[20];
    char last[20];
};

struct person
{
    int id;
    struct names name;  // 嵌套结构成员
};

struct person ted = {8483, {"Ted", "Grass"}};
puts(ted.name.first);
```

在 C11 中，可以用嵌套的匿名成员结构定义 person：

```
struct person
{
    int id;
    struct {char first[20]; char last[20];};  // 匿名结构
};

// 初始化 ted 的方式相同
struct person ted = {8483, {"Ted", "Grass"}};
// 但是访问 ted 时简化了步骤
puts(ted.first);
```

匿名特性在嵌套联合中更加有用。

>> 使用结构数组的函数

代码：funds4.c


> 把结构内容保存到文件中

**由于结构可以储存不同类型的信息，所以它是构建数据库的重要工具**。例如，可以用一个结构储存雇员或汽车
零件的相关信息。最终，我们要把这些信息储存在文件中，并且能再次检索。数据库文件可以包含任意数量的此类
数据对象。储存在一个结构中的整套信息被称为 **记录(record)**，单独的项被称为 **字段(field)**。

或许储存记录最没效率的方法是用 fprintf()。例如有以下 book 结构：

```
#define MAXTITL 40
#define MAXAUTL 40
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
```

如果 pbooks 标识一个文件流，那么以下语句可把信息储存在`struct book`类型的结构变量 primer 中：

```
fprintf(pbooks, "%s %s %.2f\n", primer.title, primer.author, primer.value);
```

对于一些结构（如，有 30 个成员的结构），这个方法用起来很不方便。另外，在检索时还存在问题，因为
程序要知道一个字段结束和另一个字段开始的位置。虽然用固定字段宽度的格式可以解决这个问题（例如，
"%39s%39s%8.2f"），但这个方法仍然很笨拙。

更好的方案是使用 fread() 和 fwrite() 函数读写结构大小的单元。这两个函数使用与程序相同的二进制表示法。

```
fwrite(&primer, sizeof(struct book), 1, pbooks);
```

定位到 primer 结构变量开始的位置，并把结构中的所有字节都拷贝到与 pbooks 相关的文件中。
sizeof(struct book) 告诉函数待拷贝的一块数据的大小，1 表明一次拷贝一块数据。带相同参数的 fread()
从文件中拷贝一块结构大小的数据到 &primer 指向的位置。简而言之，这两个函数一次读写整个记录，而不是
一个字段。

以二进制表示法储存数据的缺点是，不同的系统可能使用不同的二进制表示法，所以数据可能不具可移植性。
甚至同一个系统，不同编译器设置也可能导致不同的二进制布局。

>> 保存结构的程序示例

代码：booksave.c

>> 程序要点

首先，以"a+b"模式打开文件，可以末尾添加内容，b 表明程序将使用二进制文件格式。之所以选择二进制模式是因为
fread() 和 fwrite() 要使用二进制文件。

rewind() 确保文件指针位于文件开始处，为读文件做好准备。

第 1 个 while 循环每次读取一个结构到结构数组中。变量 filecount 统计已读结构的数量。

第 2 个 while 接受用户输入。

for 循环打印文件和用户输入的数据，新写入内容到文件末尾。

这种方法浪费存储空间，因为还保存了结构中未使用的部分。该结构大小是`2 * 40 * sizeof(char) + sizeof(float)`，
实际上不是每个输入项都需要这么多空间。但是，让每个输入块的大小相同在检索数据时很方便。


> 链式结构

结构的多种用途之一：创建新的数据形式，包括队列、二叉树、堆、哈希表和图表。许多这样的形式都由 **链式结构(linked structure)** 
组成。通常，每个结构都包含一两个数据项和一两个指向其他类型结构的指针。这些指针把一个结构和另一个结构链接起来，并提供
一种路径能遍历整个彼此链接的结构。


> 联合简介

**联合(union)** 是一种数据类型，它能在同一个内存空间中储存不同的数据类型（不是同时储存）。其典型用法是，设计一种表以储存既无规律、
事先也不知道顺序的混合类型。使用联合类型的数组，其中的联合都大小相等，每个联合可以储存各种数据类型。

创建联合和创建结构的方式相同：

```
union hold {
    int digit;
    doublel bigfl;
    char letter;
};
```

根据以上形式声明的结构可以储存一个 int 类型、一个 double 类型和 char 类型的值。然而，声明的联合只能储存一个 int 类型的值或
一个 double 类型和 char 类型的值。然而，声明的联合只能储存一个 int 类型的值或一个 double 的值或 char 类型的值。

下面定义了 3 个与 hold 类型相关的变量：

```
union hold fit;        // hold 类型的联合变量
union hold save[10];   // 内含 10 个联合变量的数组
union hold *pu;        // 指向 hold 类型联合变量的指针
```

联合只能储存一个值。有 3 种初始化的方法：
1. 把一个联合初始化为另一个同类型的联合；
2. 初始化联合的第 1 个元素；
3. 根据 C99 标准，使用指定初始化器；

```
union hold valA;
valA.letter = 'R';
union hold valB = valA;              // 用另一个联合来初始化
union hold valC = {88};              // 初始化联合的 digit 成员
union hold valD = {.bigfl = 118.2};  // 指定初始化器
```

>> 使用联合

感觉某些弱类型语言的变量应该用的就是联合，随时切换类型都可以，待以后研究语言内核再来深究

```
fit.digit = 23;     // 把 23 储存在 fit，占 2 字节
fig.bigfl = 2.0;    // 清除 23，储存 2.0，占 8 字节
fig.letter = 'h';   // 清除 2.0，储存 h，占 1 字节
```

点运算表示正在使用哪种数据类型。编写代码时要注意当前储存在联合中的数据类型。
和用指针访问结构使用`->`运算符一样，用指针访问联合时也要使用`->`运算符：

```
pu = &fit;
x = pu->digit;  // 相当于 x = fig.digit
```

>> 匿名联合(C11)

匿名联合和匿名结构的工作原理相同。


> 枚举类型

可以用 **枚举类型(enumerated type)** 声明符号名称来表示整型常量。使用 enum 关键字，可以创建
一个新"类型"并指定它可具有的值（实际上，enum 常量是 int 类型，因此，只要能使用 int 类型的地方
就可以使用枚举类型）。枚举类型的目的是提高程序的可读性。语法与结构相同。声明：

```
enum spectrum {red, orange, yellow, green, blue, violet};
enum spectrum color;
```

第 1 个声明创建了 spetrum 作为标记名，允许把 enum spetrum 作为一个类型名使用。第 2 个声明使
color 作为该类型的变量。第 1 个声明中花括号内的标识符枚举了 spectrum 变量可能有的值。因此，
color 可能的值是 red、orange、yellow 等。这些符号常量被称为 **枚举符(enumerator)**。用法如下：

```
int c;
color = blue;
if (color == yellow) {
    ...;
}

for (color = red; color <= violet; color ++) {
    ...;
}
```

>> enum 常量

blue 和 red 到底是什么？从技术层面看，它们是 int 类型的常量。例如，假定有前面的枚举声明，可以这样写：

```
printf("red = %d, orange = %d\n", red, orange);
// red = 0, orange = 1
```

red 成为一个有名称的常量，代表整数 0，以此类推，其它亦如此。

>> 默认值

默认情况下，枚举列表中的常量都被赋予0、1、2等。因此，以下的声明中 nina 的值是3：

```
enum kids {nippy, slats, skippy, nina, liz};
```

>> 赋值

在枚举声明中，可以为枚举常量指定整数值：

```
enum levels {low = 100, medium = 500, high = 2000};
```

如果只给一个枚举常量赋值，没对后面的常量赋值，后面的常量会被赋予后续的值。例如：

```
enum feline {cat, lynx = 10, puma, tiger};
```

cat 的值是 0（默认），lynx、puma 和 tiger 的值分别是 10、11、12。

>> enum 的用法

枚举类型的目的是为了提高程序的可读性和可维护性。如果要处理颜然，使用 red 和 blue 比使用 0 和 1 更直观。
注意，枚举类型只能在内部使用。如果要输入 color 中 orange 的值，要输入 1，而不是单词 orange。

代码：enum.c