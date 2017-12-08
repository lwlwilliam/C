// forc99.c -- 新的 C99 块规则
/*
    第 1 个 for 循环头中声明的 n，其作用域作用至循环末尾，而且隐藏了原始的 n。
    但是，离开循环后，原始的 n 又起作用了。

    第 2 个 for 循环头中声明的 n 作为循环的索引，隐藏了原始的 n。然后，在循环体中又声明了一个 n，
    隐藏了索引 n。结束一轮迭代后，声明在循环体中的 n 消失，循环头使用索引 n 进行测试。当整个循环结束时，
    原始的 n 又起作用了。
*/
#include <stdio.h>
int main()
{
    int n = 8;

    printf("   Initially, n = %d at %p\n", n, &n);
    for (int n = 1; n < 3; n ++) {
        printf("      loop 1: n = %d at %p\n", n, &n);
    }
    printf("After loop 1, n = %d at %p\n", n, &n);
    for (int n = 1; n < 3; n ++) {
        printf("loop 2: index n = %d at %p\n", n, &n);
        int n = 6;
        printf("      loop 2: n = %d at %p\n", n, &n);
        n ++;
    }
    printf("After loop 2, n = %d at %p\n", n, &n);

    return 0;
}