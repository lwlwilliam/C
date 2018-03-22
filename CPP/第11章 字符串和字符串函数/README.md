# 字符串和字符串函数

## 表示字符串和字符串 I/O

`字符串`是以空字符(\0)结尾的 char 类型数组。

### 在程序中定义字符串

#### 字符串字面量（字符串常量）

用双引号括起来的内容称为**字符串字面量(string literal)**，也叫作**字符串常量(string constant)**。
双引号中的字符和编译器自动加入末尾的`\0`字符，都作为字符串储存在内存中。

从 ANSI 标准起，如果字符串字面量之间没有间隔，或者用空白字符分隔，C 会将其视为串联起来的字符串字面量。
例如：

```
char greeting[50] = "Hello, and "" how are"" you"
                    " today!";
```

与下面的代码等价：

```
char greeting[50] = "Hello, and how are you today!";
```

字符串常量属于**静态存储类别(static storage class)**，这说明如果在函数中使用字符串常量，
该字符串只会被储存一次，在整个程序的生命期内存在，即使函数被调用多次。
用双引号括起来的内容被视为指向该字符串储存位置的指针。这类似于把数组名作为指向该数组位置的指针。

#### 字符串数组和初始化

定义字符串数组时，必须让编译器知道需要多少空间。一种方法是用足够空间的数组储存字符串。

```
const char ml[40] = "Limit yourself to one line's worth.";
```

这种形式的初始化比标准的数组初始化形式简单得多：

```
const char ml[40] = {'L', 'i', 'm', 'i', 't', ' ', 'y', 'o', 'u', 'r', 's', 'e', 'l', 
                     'f', ' ', 't', 'o', ' ', 'o', 'n', 'e', ' ', 'l', 'i', 'n', 'e', 
                     '\'', 's', ' ', 'w', 'o', 'r', 't', 'h', '.', '\0'
                    };
```

注意最后的空字符。没有这个空字符，这就不是一个字符串，而是一个字符数组。

在指定数组大小时，要确保数组的元素个数至少比字符串长度多 1（为了容纳空字符）。
所有未被使用的元素都被自动初始化为 0（这里的 0 指的是 char 形式的空字符，不是数字字符 0）。
字符数组名和其他数组名一样，是该数组首元素的地址。因此，假设有下面的初始化：

```
char car[10] = "Tata";
```

那么，以下表达式都为真：

```
car == &car[0]

*car == 'T'

*(car + 1) == car[1] == 'a'
```

还可以使用指针表示法创建字符串。如：

```
const char *pt1 = "Something is pointing at me.";
```

该声明和下面的声明几乎相同：

```
const char ar1[] = "Something is pointing at me.";
```

以上两个声明表明，pt1 和 ar1 都是该字符串的地址。在这两种情况下，带双此号的字符串本身决定了预留经字符串的存储空间。
尽管如此，这两种形式并不完全相同。

#### 数组和指针

数组形式和指针形式有何不同？以上面的声明为例，数组形式(`ar1[]`)在计算机的内存中分配为一个内含 29 个元素的数组（每个
元素对应一个字符，还加上一个末尾的空字符`\0`），每个元素被初始化为字符串字面量对应的字符。通常，
字符串都作为可执行文件的一部分储存在数据段中，当把程序载入内存时，也载入了程序中的字符串。字符串储存在 **静态存储区(static memory)** 中。
但是，程序在开始运行时才会为该数组分配内存。此时，才将字符串拷贝到数组。注意，此时字符串有两个副本。
一个是在静态内存中的字符串字面量，另一个是储存在`ar1`数组中的字符串。

此后，编译器便把数组名`ar1`识别为该数组首元素地址(`&ar1[0]`)的别名。在数组形式中，`ar1`是**地址常量**。不能更改`ar1`，如果改变了`ar1`，
则意味着改变了数组的存储位置（即地址）。可以进行类似`ar1 + 1`这样的操作，标识数组的下一个元素，但是不允许进行`++ ar1`这样的操作。
递增运算只能用于变量名前（或概括地说，只能用于可修改的左值），不能用于常量。

指针形式(`*pt1`)也使得编译器为字符串在静态存储区预留 29 个元素的空间。另外，一旦开始执行程序，它会为指针变量`pt1`留出一个储存位置，
并把字符串的地址储存在指针变量中。该变量最初指向该字符串的首字符，但是它的值可以改变。因此，可以使用递增运算符。例如，`++ pt1`将指向第 2 个字符(o)。

字符串字面量被视为 const 数据。由于`pt1`指向这个 const 数据，所以应该把`pt1`声明为指向 const 数据的指针。这意味着不能用`pt1`改变它所指向的数据，
但是仍然可以改变`pt1`的值（即，`pt1`指向的位置）。

看以下例子，理解数组形式和指针形式的不同之处：

```
// addresses.c -- 字符串的地址
#define MSG "I'm special"
#include <stdio.h>

int main()
{
    char ar[] = MSG;
    const char *pt = MSG;
    const char *pr = ar;

    printf("address of \"I'm special\": %p\n", "I'm special");
    printf("              address ar: %p\n", ar);
    printf("              address pr: %p\n", pr);
    printf("              address pt: %p\n", pt);
    printf("          address of MSG: %p\n", MSG);
    printf("address of \"I'm special\": %p\n", "I'm special");
    
    /*
    结果如下：
    address of "I'm special": 0x10555bef8
                  address ar: 0x7fff5a6a4acc
                  address pr: 0x7fff5a6a4acc
                  address pt: 0x10555bef8
              address of MSG: 0x10555bef8
    address of "I'm special": 0x10555bef8
    */

    return 0;
}
```

以上程序的输出说明了什么？
1. pt 和 MSG 的地址相同，而 ar 的地址不同；
2. 虽然字符串字面量"I'm special"在程序的两个 printf() 函数中出现了两次，但是编译器只使用了一个存储位置，
   而且与 MSG 的地址相同。编译器可以把多次使用的相同字面量储存在一处或多处。另一个编译器可能在不同的位置储存 3 个 "I'm special"；
3. 静态数据使用的内存与 ar 使用的动态内存不同。不仅值不同，特定编译器甚至使用不同的位数表示两种内存；

#### 数组和指针的区别

假设有下面两个声明：

```
char heart[] = "I love Tillie!";
const char *head = "I love Millie!";
```

两者的主要区别是：数组名 heart 是常量，而指针名 head 是变量。
首先，两者都可以使用数组表示法：

```
for (i = 0; i < 6; i ++) {
    putchar(heart[i]);
}
putchar('\n');
for (i = 0; i < 6; i ++) {
    putchar(head[i]);
}
putchar('\n');
```

其次，两者都能进行指针加法操作：

```
for (i = 0; i < 6; i ++) {
    putchar(*(heart + i));
}
putchar('\n');
for (i = 0; i < 6; i ++) {
    putchar(*(head + i));
}
putchar('\n');
```

但是，只有指针表示法可以进行递增操作：

```
while (*(head) != '\0') {  // 在字符串末尾处停止
    putchar(*(head ++));   // 打印字符，指针指向下一个位置
}
```

#### 字符串数组

```
// arrchar.c -- 指针数组，字符串数组
#include <stdio.h>
#define SLEN 40
#define LIM 5

int main()
{
    const char *mytalents[LIM] = {
        "Adding numbers swiftly",
        "Multiplying accurately",
        "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"
    };
    char yourtalents[LIM][SLEN] = {
        "Walking in a straight line",
        "Sleeping",
        "Watching television",
        "Mailing letters",
        "Reading email"
    };
    int i;

    puts("let's compare talents.");
    printf("%-40s %-40s\n", "My Talents", "Your Talents");
    for (i = 0; i < LIM; i ++) {
        printf("%-40s %-40s\n", mytalents[i], yourtalents[i]);
    }
    printf("\nsizeof mytalents: %zd, sizeof youtalents: %zd\n", sizeof mytalents, sizeof yourtalents);

    return 0;
}
```

从某些方面来看，`mytalents`和`yourtalents`非常相似。
但是，它们也是区别。`mytalents`数组是一个内含 5 个指针的数组，在我们的系统中共占用 40 字节。
而`youtalents`是一个内含 5 个数组的数组，每个数组内含 40 个 char 类型的值，共占用 200 字节。
所以虽然`mytalents[0]`和`yourtalents[0]`都分别表示一个字符串，但`mytalents`和`yourtalents`
的类型并不相同。`mytalents`中的指针指向初始化时所用的字符串字面量的位置，这些字符串字面量被储存在静态内存中；
而`yourtalents`中的数组则储存着字符串字面量的副本，所以每个字符串都储存了两次。此外，为字符串数组分配内存的使用率较低。
`yourtalents`中的每具元素大小必须相同，而且必须是能储存最长字符串的大小。

可以把`yourtalents`想象成矩形二维数组，每行的长度都是 40 字节；把`mytalents`想象成不规则的数组，每行的长度不同。
实际上，`mytalents`数组的指针元素所指向的字符串不必储存在连续的内存中。


### 指针和字符串

```
/* p_and_s.c -- 指针和字符串 */
#include <stdio.h>
int main()
{
    const char *mesg = "Don't be a fool!";
    const char *copy;

    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);

    /*
        Don't be a fool!
        mesg = Don't be a fool!; &mesg = 0x7fff55d93ad0; value = 0x109e6cf3e
        copy = Don't be a fool!; &copy = 0x7fff55d93ac8; value = 0x109e6cf3e

        你可能认为该程序拷贝了字符串"Don't be a fool!"。
        但是注意最后一项，两个指针的值是相同的，说明它们都指向同一个位置。
        因此，程序并未拷贝字符串。
        copy = mesg; 把 mesg 的值赋给 copy，即让 copy 也指向 mesg 指向的字符串。
    */

    return 0;
}
```

## 字符串输入

如果想把一个字符串读入程序，首先必须预留储存该字符串的空间，然后用输入函数获取该字符串。

### 分配空间

要做的第 1 件事是分配空间，以储存稍后读入的字符串。
不要指望计算机在读取字符串时顺便计算它的长度，然后再分配空间（计算机不会这样做，
除非编写一个处理这些任务的函数）。

假设编写了如下代码：

```
char *name;
scanf("%s", name);
```

虽然可能会通过编译，但是在读入 name 时，name 可能会擦写掉程序中的数据或代码，从而导致程序异常中止。
因为 scanf() 要把信息拷贝至参数指定的地址上，而此时该参数是个未初始化的指针，name 可能会指向任何地方。

为字符串分配内存后，便可读入字符中。

### 不幸的 gets() 函数

gets() 函数读取整行输入，直至遇到换行符，然后丢弃换行符，储存其余字符，并在这些字符末尾添加一个空字符使其成为一个 C 字符串。
常和 puts() 函数配对使用。

gets() 函数无法检查数组是否装得下输入行，因为它只知道数组的开始处，并不知道数组中有多少个元素。在某些编译器中会警告。

如果输入的字符串过长，会导致**缓冲区溢出(buffer overflow)**，即多余的字符超出了指定的目标空间。
如果这些多余的字符只是占用了尚未使用的内存，就不会立即出现问题；如果它们擦写掉程序中的其他数据，会导致程序异常中止；
或者还有其他情况。

C 编程社区的许多人都建议在编程时摒弃 gets()。制定 C99 标准的委员会把这些建议放入了标准，承认了 gets() 的问题并建议不要再使用它。

C11 标准委员会直接从标准中废除了 gets() 函数。

### gets() 的替代品

#### fgets() 函数（和 fputs()）

fgets() 函数通过第 2 个参数限制读入的字符数来解决溢出的问题。该函数专门设计用于处理文件输入，所以一般情况下可能不太好用。

* fgets() 函数的第 2 个参数指明了读入字符的最大数量。如果该参数的值是 n，那么 fgets() 将读入 n - 1 个字符，或者读到遇到的第一个换行符为止；
* 如果 fgets() 读到一个换行符，会把它储存在字符串中；
* fgets() 函数的第 3 个参数指明要读入的文件。如果读入从键盘输入的数据，则以 stdin（标准输入）作为参数，该标识符定义在 stdio.h 中；

fgets() 函数返回指向 char 的指针。如果函数读到文件末尾，它将返回一个特殊的指针：`空指针(null pointer)`。
该指针保证不会指向有效的数据。

**空字符和空指针**：空字符（或'\0'）是用于标记 C 字符串末尾的字符，其对应字符编码是 0；
空指针（或 NULL）有一个值，该值不会与任何数据的有效地址对应，通常，函数使用它返回一个有效地址表示某些特殊情况发生，例如遇到文件末尾或未能按预期执行。
空字符是整数类型，而空指针是指针类型，两者有时容易混淆的原因：它们都可以用数值 0 来表示。但是，从概念上看，两者是不同类型的 0。
另外，空字符是一个字符，占 1 字节；而空指针是一个地址，通常占 4 字节。

#### gets_s() 函数

C11 新增的 gets_s() 函数（可选）和 fgets() 类似，用一个参数限制读入的字符数。

与 fgets() 区别如下：
* gets_s() 只从标准输入中读取数据，所以不需要第 3 个参数；
* gets_s() 读到换行符，会丢弃它而不是储存它；
* gets_s() 如果读到最大字符数都没有读到换行符，会执行以下几步：
  首先把目标数组中的首字符设置为空字符，读取并丢弃随后的输入直至读到换行符或文件结尾，然后返回空指针；
  接着，调用依赖实现的"处理函数"，可能会中止或退出程序；
  
#### s_gets() 函数

```
char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {  // 即，ret_val != NULL
        while (st[i] != '\n' && st[i] != '\0') {
            i ++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        } else {  // 如果字符串中出现空字符，就丢弃该输入行的其余字符，因为输入行中多出来的字符会被留在缓冲区中，成为下一次读取语句的输入。
            while (getchar() != '\n') {
                continue;
            }
        }
    }

    return ret_val;
}
```

### scanf() 函数

scanf() 以第 1 个非空白字符作为字符串的开始，以下一个空白字符作为字符串的结束（字符串不包括空白字符）。
scanf() 返回一个整数值，该值等于 scanf() 成功读取的项数或 EOF（读到文件结尾时返回 EOF）。

根据输入数据的性质，用 fgets() 读取从键盘输入的数据更合适。例如，scanf() 无法完整读取书名或歌曲名，
除非这些名称是一个单词。


## 字符串输出

C 有 3 个标准库函数用于打印字符串：put()、fputs() 和 printf()。

### puts() 函数

puts() 在显示字符串时会自动在其末尾添加一个换行符，在遇到空字符时就停止输出，所以确保有空字符。

### fputs() 函数

fputs() 函数是 puts() 针对文件定制的版本。它们的区别如下：

* fputs() 第 2 个参数指明要写入数据的文件。如果要打印在显示器上，可以用定义在 stdio.h 中的 stdout(标准输出) 作为该参数；
* 与 puts() 不同，fputs() 不会在输出的末尾添加换行符；

### printf() 函数

printf() 可以格式化不同的数据类型。


## 自定义输入/输出函数

不一定非要使用 C 库中的标准函数，完全可以在 getchar() 和 putchar() 的基础上自定义所需的函数。


## 字符串常数

C 库提供了多个处理字符串的函数，ANSI C 把这些函数的原型放在 string.h 头文件中。
其中最常用的函数有 strlen()、strcat()、strcmp()、strncmp()、strcpy() 和 strncpy()。
另外，还有 sprintf() 函数，其原型在 stdio.h 头文件中。

### strlen() 函数

strlen() 函数用于统计字符串的长度。

### strcat() 函数

strcat() 函数用于拼接字符串。该函数接受两个字符串作为参数。把第 2 个字符串的备份附加在第
1 个字符串末尾，并把拼接后形成的新字符串作为第 1 个字符串，第 2 个字符串不变。

### strncat() 函数

strcat() 函数无法检查第 1 个数组是否能容纳第 2 个字符串。如果分配给第 1 个数组的空间不够大，
多出来的字符溢出到相邻存储单元时就会出问题。当然可以用 strlen() 先查看第 1 个数组的长度。
注意，要给拼接后的字符串长度加 1 才够空间存放末尾的空字符。或者用 strncat()，该函数的第 3 个
参数指定了最大添加字符数。例如，strncat(bugs, addon, 13) 将把 addon 字符串的内容附加给 bugs，
在加到第 13 个字符或遇到空字符时停止。

### strcmp() 函数

该函数通过比较运算符来比较字符串，就像比较数字一样，如果两个字符串参数相同，该函数就返回 0，
否则返回非零值。

strcmp() 函数比较的是字符串，不是整个数组。例如数组 arr[40] 占用 40 字节，而只储存了 "test"
只占用了 5 字节（还有一个用来放空字符），strcmp() 函数只会比较 arr 中第 1 个空字符前面的部分。
所以，可以用 strcmp() 比较储存在不同大小数组中的字符串。

ASCII 标准规定，在字母表中，如果第 1 个字符串在第 2 个字符串前面，strcmp() 返回一个负数；
如果两个字符串相同，strcmp() 返回 0；如果第 1 个字符串在第 2 个字符串后面，strcmp() 返回正数。
然而，返回的具体值取决于实现。

注意，strcmp() 函数比较的是字符串，不是字符，所以其参数应该是字符串，而不是字符。

### strncmp() 函数

strcmp() 函数比较字符串中的字符，直到发现不同的字符为止，这一过程可能会持续到字符串末尾。
而 strncmp() 函数在比较两个字符串时，可以比较到字符不同的地方，也可以只比较第 3 个参数指定的字符数。
例如，要查找以"astro"开头的字符串，可以限定只查找这 5 个字符。

### strcpy() 和 strncpy() 函数

如果 pts1 和 pts2 都是指向字符串的指针，那么下面语句拷贝的是字符串的地址而不是字符串本身：`pts2 = pts1`。

如果希望拷贝整个字符串，要使用 strcpy() 函数。

strcpy() 第 2 个参数指向的字符串被拷贝至第 1 个参数指向的数组中。拷贝出来的字符串被称为**目标字符串**，
最初的字符串被称为**源字符串**。

程序员有责任确保目标数组有足够的空间容纳源字符串的副本。以下的代码有点问题：

```
char *str;
strcpy(str, "The C of Tranquility");  // 有问题
```

strcpy() 把 "The C of Tranquility"拷贝至 str 指向的地址上，但是 str 未被初始化，所以该字符串可能被拷贝到任意的地方！

#### strcpy() 的其它属性

strcpy() 还有两个有用的属性。第一，strcpy() 的返回类型是`char *`，该函数返回的是第 1 个参数的值，即一个字符的地址。
第二，第 1 个参数不必指向数组的开始。这个属性可用于拷贝数组的一部分。

#### 更谨慎的选择：strncpy()

strcpy() 和 strcat() 都有同样的问题，它们都不能检查目标空间是否能容纳源字答串的副本。拷贝字符串用 strncpy() 更安全，
该函数的第 3 个参数指明可拷贝的最大字符数。

`strncpy(target, source, n)`把 source 中的 n 个字符或空字符之前的字符（先满足哪个条件就拷贝到何处）拷贝至 target 中。
如果 source 中的字符数小于 n，则拷贝整个字符串，包括空字符。但是 strncpy() 拷贝字符串的长度不会超过 n，
如果拷贝到第 n 个字符时还未拷贝完整个源字符串，就不会拷贝空字符。所以，拷贝的副本中不一定有空字符。

### sprintf() 函数

sprintf() 函数声明在 stdio.h 中，而不是在 string.h 中。该函数和 printf() 类似，但是它是把数据写入字符串，
而不是打印在显示器上。因此，该函数可以把多个元素组合成一个字符串。

### 其它字符串函数

ANSI C 库有 20 多个用于处理字符串的函数，下面总结了一些常用的函数：

* `char *strcpy(char *restrict s1, const char * restrict s2);`
* `char *strncpy(char *restrict s1, const char *restrict s2, size_t n)`
* `char *strcat(char *restrict s1, const char *restrict s2)`
* `char *strncat(char *restrict s1, const char *restrict s2, size_t n)`
* `int strcmp(const char *s1, const char *s2)`
* `int strncmp(const char *s1, const char *s2, size_t n)`
* `char *strchr(const char *s, int c)`：如果 s 字符串中包含 c 字符，
  该函数返回指向 s 字符串首位置的指针（末尾的空字符也是字符串的一部分，所以在查找范围内）；如果在字符串 s 中未找到 c 字符，
  该函数则返回空指针。
* `char *strpbrk(const char *s1, const char *s2)`：如果 s1 字符串中包含 s2 字符串中的任意字符，
  该函数返回指向 s1 字符串首位置的指针；如果在 s1 字符串中未找到任何 s2 字符串中的字符，则返回空字符。
* `char *strrchr(const char *s, int c)`：该函数返回 s 字符串中 c 字符的最后一次出现的位置（末尾的空字符也是字符串的一部分，
  所以在查找范围内）。如果未找到 c 字符，则返回空指针。
* `char *strstr(const char *s1, const char *s2)`：该函数返回指向 s1 字符串中 s2 字符串出现的首位置。如果在 s1 中没有找到 s2，
  则返回空指针。
* `size_t strlen(const char *s)`

size_t 是 sizeof 运算符返回的类型。C 规定 sizeof 运算符返回一个整数类型，但是并未指定是哪种整数类型。string.h 头文件针对特定系统定义了 size_t。


## 字符串示例：字符串排序

### 排序指针而非字符串

### 选择排序算法

利用 for 循环依次把每个元素与首元素比较。 如果待比较的元素在当前首元素的前面，则交换两者。
循环结束时，首元素包含的指针指向机器排序序列最靠前的字符串。然后最外层的 for 循环重复这一过程，
这次从 input 的第 2 个元素开始。当内层循环执行完毕时，指针中的第 2 个元素指向排在第 2 的字符串，
依此类推。


## ctype.h 字符函数和字符串

ctype.h 中的函数通常作为宏(macro)来实现。这些 C 预处理器宏的作用很像函数，但是两者有一些重要的区别。


## 命令行参数

`命令行(command line)`是在命令行环境中，用户为运行程序输入命令的行。
`命令行参数(command-line argument)`是同一行的附加项。如下：

```
$ ls -l
```

C 程序可以读取并使用这些附加项。

C 编译器允许 main() 没有参数或者有两个参数（一些实现允许 main() 有更多参数，属于对标准的扩展）。
main() 有两个参数时，第 1 个参数是命令行中的字符串数量。过去，这个 int 类型的参数被称为
 argc（表示参数计数(argument count)）。系统用空格表示一个字符串的结束和下一个字符串的开始。
指向指针的指针称为 argv（表示参数值[argument value]）。如果系统允许（一些操作系统不允许这样），
就把程序本身的名称赋给 argv[0]。

```int main(int argc, char *argv[])```


## 把字符串转为数字

数字既能以字符串形式储存，也能以数值形式储存。把数字储存为字符串就是储存数字字符。
例如，数字 213 以 '2', '1', '3', '\0' 的形式被储存在字符串数组中。

C 要求用数值形式进行数值运算（如，加法和比较）。但是在屏幕上显示数字则要求字符串形式，因为屏幕显示的是字符。

