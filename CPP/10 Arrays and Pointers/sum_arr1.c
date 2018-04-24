// sum_arr1.c -- 数组元素之和
// 如果编译器不支持 %zd，用 %u 或 %lu 替换它
#include <stdio.h>
#define SIZE 10
int sum(int ar[], int n);

int main()
{
    int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;

    answer = sum(marbles, SIZE);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %lu bytes.\n", sizeof marbles);

    /*
        The size of ar is 8 bytes.
        The total number of marbles is 190.
        The size of marbles is 40 bytes.

        marbles 的大小是 40 字节。这没问题，因为 marbles 内含 10 个 int 类型的值，
        每个值占 4 字节。但是，ar 才 8 字节。这是因为 ar 并不是数组本身，
        它是一个指向 marbles 数组首元素的指针。系统用 8 字节储存地址，所以指针变量大小是 8 字节
        ，其它系统中地址的大小可能不是 8 字节。简而言之，marbles 是一个数组，ar 是一个指向 marbles 数组首元素的指针，
        利用 C 中数组和指针的特殊关系，可以用数组表示法来表示指针 ar。
    */

    return 0;
}

int sum(int ar[], int n)
{
    int i;
    int total = 0;

    for (i = 0; i < n; i ++) {
        total += ar[i];  // ar[i] 和 *(ar + i) 相同
    }

    printf("The size of ar is %lu bytes.\n", sizeof ar);

    return total;
}
