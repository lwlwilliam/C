/* fgets1.c -- 使用 fgets() 和 fputs() */
/*
在输入超过了大小限制的时候，fgets() 只读入 STLEN - 1 个字符，
并在最后加上"\0"，储存在数组中。
*/
#include <stdio.h>
#define STLEN 14

int main()
{
    char words[STLEN];

    puts("Enter a string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter another string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");

    return 0;
}