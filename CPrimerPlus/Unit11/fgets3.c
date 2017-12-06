/* fgets3.c -- 使用 fgets() */
#include <stdio.h>
#define STLEN 10

int main()
{
    char words[STLEN];
    int i;

    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n') {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0') {  // 遍历字符串，直至遇到换行符或空字符。
            i ++;
        }

        // 如果先遇到换行符，将其替换成空字符；
        if (words[i] == '\n') {
            words[i] = '\0';
        } else {  // 如果先遇到空字符，便丢弃输入行的剩余字符
            while (getchar() != '\n') {
                continue;
            }
        }
        puts(words);
    }

    puts("done");

    return 0;
}