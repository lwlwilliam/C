/* swap2.c -- 使用指针解决交换函数的问题 */
#include <stdio.h>
void interchange(int *u, int *v);

int main()
{
    int x = 5, y = 10;

    printf("Originally x = %d and y = %d.\n", x, y);
    interchange(&x, &y);  // 该函数传递的不是 x 和 y 的值，而是它们的地址。
    printf("Now x = %d and y = %d.\n", x, y);

    return 0;
}

void interchange(int *u, int *v)
{
    int temp;

    temp = *u;  // 不要写成 temp = u; 因为 temp = u; 表示赋给 temp 的是 x 的地址，而不是 x 的值。
    *u = *v;
    *v = temp;
}