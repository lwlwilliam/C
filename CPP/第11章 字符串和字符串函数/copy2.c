/* copy2.c -- 使用 strcpy() */
/*
    注意，strcpy() 把源字符串中的空字符也拷贝在内。在该例中，空字符覆盖了 copy 数组中 that 的第 1 个 t。
    由于第 1 个参数是 copy + 7，所以 ps 指向 copy 中的第 8 个元素。puts(ps) 从该处开始打印字符串。
*/
#include <stdio.h>
#include <string.h>  // 提供 strcpy() 的函数原型
#define WORDS "beast"
#define SIZE 40

int main()
{
    const char *orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char *ps;

    puts(orig);
    puts(copy);
    ps = strcpy(copy + 7, orig);
    puts(copy);
    puts(ps);

    return 0;
}