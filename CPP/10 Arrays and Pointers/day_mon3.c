/* day_mon3.c -- uses pointer notation */
/* 这样编写程序是否有优势？不一定。编译器编译这两种写法生成的代码相同。指针表示法和数组表示法是两种等效的方法。可以用指针表示数组，也可以用数组表示指针。 */
#include <stdio.h>
#define MONTHS 12

int main()
{
    int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;

    for (index = 0; index < MONTHS; index ++) {
        printf("Month %2d has %d days.\n", index + 1, *(days + index));  // 与 days[index] 相同
    }

    return 0;
}
