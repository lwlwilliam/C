/* nogo.c -- 该程序是否能正常运行？ */
/*
    由于 ANSWER 和 try 都是指针，所以 try != ANSWER 检查的不是两个字符串是否相等，
    而是这两个字符串的地址是否相同。因为 ANSWER 和 try 住在存在不同的位置，所以这两个地址不可能相同，
    因此，无论用户输入什么，程序都提示输入不正确。
 */
#include <stdio.h>
#define ANSWER "Grant"
#define SIZE 40
char *s_gets(char *st, int n);

int main()
{
    char try[SIZE];

    puts("Who is buried in Grant's tomb?");
    s_gets(try, SIZE);
    while (try != ANSWER) {
        puts("No, that's wrong. Try again.");
        s_gets(try, SIZE);
    }
    puts("That's right!");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0') {
            i ++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        } else {
            while (getchar() != '\n') {
                continue;
            }
        }
    }

    return ret_val;
}