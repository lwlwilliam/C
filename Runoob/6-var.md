### C变量

> C中的变量定义

变量定义就是告诉编译器在何处创建变量的存储，以及如何创建变量的存储。变量定义指定一个数据类型，并包含了该类型的一个或多个变量的列表，如下所示：

```
type variable_list;
```

在这里，**type**必须是一个有效的C数据类型，可以是char、w_char、int、float、double、bool或任何用户自定义的对象，**variable_list**可以由一个或多个标识符名称组成，多个标识符之间用逗号分隔。

下面是几个实例：

```
extern int d = 3, f = 5; // d和f的声明，这就是单纯的声明
int d = 3, f = 5; // 定义并初始化d和f
byte z = 22; // 定义并初始化z
char x = 'x'; // 变量x的值为'x'
```

不带初始化的定义：带有静态存储持续时间的变量会被隐式初始化为NULL（所有字节的值都是0），其他所有变量的初始值是未定义的。

> C中的变量声明

变量声明向编译器保证变量以指定的类型和名称存在，这样编译器在不需要知道变量完整细节的情况下也能继续进一步的编译。变量声晨只在编译时有它的意义，在程序连接时编译器需要实际的变量声明。

变量的声明有两种情况：
1. 一种是需要建立存储空间的。例如：int a 在声明的时候就已经建立了存储空间；
2. 另一种是不需要建立存储空间的，通过使用extern关键字声明变量名而不定义它。例如：extern int a 其中变量a可以在别的文件中定义的。

** 除非有extern关键字，否则都是变量的定义。 **

```
extern int i; // 声明，不是定义
int i; // 声明，也是定义
```

> C中的左值（Lvalues）和右值（Rvalues）

C中有两种类型的表达式：
1. 左值（lvalue）：指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
2. 右值（rvalue）：术语右值（rvalue）指的是存储在内存中某些地址的数值。右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。

变量是左值，因此可以出现在赋值号的左边。数值型的字面值是右值，因此不能被赋值，不能出现在赋值号的左边。下面是一个有效的语句：

```
int g = 20;
```

但是下面这个就不是一个有效的语句，会生成编译时错误：

```
10 = 20;
```