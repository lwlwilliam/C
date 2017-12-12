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

换言之，声明结构的过程和定义结构变量的过程可以组合成一个步骤。如下所示，
组合后的结构声明和结构变量定义不需要使用结构标记：

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

使用结构成员运算符——点(.)访问结构中的成员。例如，library.value 即访问
library 的 value 部分。本质上，.title、.author 和 .value 的作用相当于
book 结构的下标。

>> 结构的初始化器

C99 和 C11 为结构提供了指定初始化器(designated initializer)，其语法与
数组的指定初始化器类似。但是，结构的指定初始化器使用点运算符和成员名
标识特定的元素。例如，只初始化 book 结构的 value 成员，可以这样做：
`struct book surprise = { .value = 10.99 };`。可以按照任意顺利使用指定
初始化器：

```
struct book gift = {
	.value = 25.99,
	.author = "James Broadfool",
	.title = "Rue for the Toad"
};
```


> 结构数组

**结构和内存**：
