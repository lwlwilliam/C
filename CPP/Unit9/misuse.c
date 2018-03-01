/* misuse.c -- 错误地使用函数 */
#include <stdio.h>

int imax();  /* 旧式函数声明 */

int main()
{
    int f = 1.0;
    printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3));
    printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.0, 5.0));
    printf("f = %d", f);

    return 0;
}

int imax(n, m)
int n, m;
{
    return (n > m ? n : m);
}