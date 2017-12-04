/* swap1.c -- 第 1 个版本的交换函数 */
/* 该版本交换失败！！！ */
#include <stdio.h>
void interchange(int u, int v);

int main()
{
    int x = 5, y = 10;

    printf("Originally x = %d and y = %d.\n", x, y);
    interchange(x, y);
    printf("Now x = %d and y = %d.\n", x, y);

    return 0;
}

void interchange(int u, int v)
{
    int temp;
    u = v;
    v = temp;
}