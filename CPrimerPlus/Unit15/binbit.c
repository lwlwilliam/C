/* binbit.c -- 使用位操作显示二进制 */
#include <stdio.h>
#include <limits.h>  // 提供 CHAR_BIT 的定义，CHAR_BIT 表示每字节的位数

char *itobs(int, char *);
void show_bstr(const char *);

int main()
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];  // + 1 为了留出一个位置给末尾的空字符
    int number;
    char *test;  // 纯粹测试用变量

    puts("Enter integers and see them in binary.");
    puts("Non-numeric input terminates program.");
    while (scanf("%d", &number) == 1) {
        test = itobs(number, bin_str);
        printf("test = %s\n", test);

        printf("%d is ", number);
        show_bstr(bin_str);
        putchar('\n');
    }
    puts("Bye!");

    return 0;
}

// 将十进制数字转为二进制数字
char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);  // 字符串长度

    // 由高位到低位，分别进行按位与操作，并右移
    for (i = size - 1; i >= 0; i --, n >>= 1) {  // n >>= 1 使 n 中的所有位向右移动一个位置。
        ps[i] = (01 & n) + '0';  // 01 是一个八进制形式的掩码，该掩码除 0 号位是 1 之外，其他所有位都为 0。因此 01 & n 就是 n 最后一位的值，该值为 0 或 1。
                                 // 但是对数组而言，需要的是字符 '0' 或字符 '1'。该值加上 '0' 即可完成这种转换（假设按顺序编码的数字，如 ASCII）。存在倒数第 2 个元素，最后一个元素用来存放空字符。
    }
    ps[size] = '\0';

    return ps;
}

/* 4 位一组显示二进制字符串 */
void show_bstr(const char *str)
{
    int i = 0;

    while (str[i]) {
        putchar(str[i]);
        if (++ i % 4 == 0 && str[i]) {
            putchar(' ');
        }
    }
}