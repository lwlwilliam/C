### C内存管理

C语言为内存的分配和管理提供了几个函数。这些函数可以在<stdlib.h>头文件中找到。

| 序号 | 函数和描述                                                                                                                                                                         |
| :--  | :--                                                                                                                                                                                |
| 1    | `void *calloc(int num, int size);` 在内存中动态地分配`num*size`的连续空间，并将每一个字节都初始化为0。所以它的结果是分配了`num*size`个字节长度的内存空间，并且每个字节的值都是0。 |
| 2    | `void free(void *address);`该函数释放address所指向的内存块，释放的是动态分配的内存空间。                                                                                           |
| 3    | `void *malloc(int num);`在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。                                               |
| 4    | `ovid *relaloc(void *address, int newsize);`该函数重新分配内，把内存扩展到newsize。                                                                                                |



> 动态分配内存

编程时，如果预先知道数组的大小，那么定义数组时就比较容易。例如，一个存储人名的数组，它最多容纳100个字符，所以可以定义数组，如下：

```
char name[100];
```


> 重新调整内存的大小和释放内存

当程序退出时，操作系统会自动释放所有分配给程序的内存，但是建议在不需要内存时，都应该调用函数free()来释放内存。

或者，可以通过调用函数realloc()来增加或减少已分配内存块的大小。