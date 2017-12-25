/**
    使用强制类型转换来访问和打印不同程序对象的字节表示。
    用 typedef 将数据类型 byte_pointer 定义为一个指向类型为 "unsigned char" 的对象的指针。
    这样一个字节指针引用一个字节序列，其中每个字节都被认为是一个非负数。
    第一个例程 show_bytes 的输入是一个字节序列的地址，它用一个字节指针以及一个字节数来表示。
    该字节数指定为数据类型 size_t，表示数据结构大小的道选数据类型。show_bytes 打印出每个以十六进制表示的字节。
    C 格式化指令"%.2x"表明整数必须用至少两个数字的十六进制格式输出。
*/
#include <stdio.h>

typedef unsigned char *byte_pointer;
void show_int(int);
void show_float(float);
void show_pointer(void *);

int main()
{
    int a = 12345;
    float b = 12345.0;
    int *c = &a;

    show_int(a);
    show_float(b);
    show_pointer(c);

    return 0;
}

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    size_t j;

    for (i = 0; i < len; i ++) {
        printf(" %.2x", start[i]);
    }

    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}
