// pnt_add.c -- 指针地址
#include <stdio.h>
#define SIZE 4
int main()
{
    short dates[SIZE];
    short *pti;
    short index;
    double bills[SIZE];
    double *ptf;

    pti = dates;  // 把数组地址赋给指针
    ptf = bills;

    printf("%23s %15s\n", "short", "double");
    for (index = 0; index < SIZE; index ++) {
        printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
        /*
                              short          double
            pointers + 0: 0x7fff5f540ad0 0x7fff5f540ab0
            pointers + 1: 0x7fff5f540ad2 0x7fff5f540ab8
            pointers + 2: 0x7fff5f540ad4 0x7fff5f540ac0
            pointers + 3: 0x7fff5f540ad6 0x7fff5f540ac8

            可以注意到，指针加 1，地址并不是增加 1。
            在 C 中，指针加 1 指的是增加一个存储单元。
            对数组而言，这意味着加 1 后的地址是下一个元素的地址，而不是下一个字节的地址。
            这是必须声明指针所指向对象类型的原因之一。
            只知道地址不够，因为计算机要知道储存对象需要多少字节（即使指针指向的是标题变量，
            也要知道变量的类型，否则 *pt 就无法正确地取回地址上的值）。
        */
    }

    return 0;
}