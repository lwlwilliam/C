/**
 * 借一法啊。。。这么简单的写法我居然想不到
 * 计算两个时间差
 */
#include <stdio.h>

int main() {
    int hour1, minute1;
    int hour2, minute2;

    scanf("%d %d", &hour1, &minute1);
    scanf("%d %d", &hour2, &minute2);

    int ih = hour2 - hour1;
    int im = minute2 - minute1;

    if (im < 0) {
        im = 60 + im;
        ih --;
    }

    printf("%d %d\n", ih, im);

    return 0;
}
