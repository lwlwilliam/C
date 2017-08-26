### C共用体

共用体是一种特殊的数据类型，允许在相同的内存位置存储不同的数据类型。可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值。共用体提供了一种使用相同的内存位置的有效方式。

> 定义共用体

为了定义共用体，必须使用union语句，方式与定义结构类似。union语句定义了一个新的数据类型，带有多个成员。格式如下：

```
union [union tag]
{
	member definition;
	member definition;
	...
	member definition;
} [one or more union variables];
```

union tag是可选的，每个member definition是标准的变量定义，比如int i;或者float f;或者其他有效的变量定义。在共用体定义的末尾，最后一个分号之前，可以指定一个或多个共用体变量，这是可选的。下面是一个Data共用体类型，有三个成员i、f和str：

```
union Data
{
	int i;
	float f;
	char str[20];
} data;
```

现在Data类型的变量可以存储一个整数、一个浮点数，或者一个字符串。这意味着一个变量（相同的内存位置）可以存储多种类型的数据。可以根据需要在一个共用体内使和任何内置的或者用户自定义的数据类型。

共用体占用的内存应足够存储共用体中最大的成员。例如，在上面的实例中，Data将占用20个字节的内存空间，因为在各个成员中，字符串所占用的空间是最大的。


> 访问共用体成员

为了访问共用体的成员，我们使用成员访问运算符(.)。成员访问运算符是共用体变量名和我们要访问的共用体成员之间的一个句号。