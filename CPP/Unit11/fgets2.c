/* fgets2.c -- 使用 fgets() 和 fputs() */
#include <stdio.h>
#define STLEN 10

int main()
{
    char words[STLEN];

    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n') {
        fputs(words, stdout);
        /*
            有意思，虽然 STLEN 被设置为 10，但是该程序似乎在处理过长的输入时完全没问题。
            程序中的 fgets() 一次读入 STLEN - 1 个字符，例如输入"abcdefghijklmn"，
            一开始读入了"abcdefghi"，并储存为"abcdefghi\0"；接着 fputs() 打印该字符串，
            而且并未换行，进入下一轮迭代，fgets() 继续从剩余输入中读入数据"jklmn\n"，
            fgets() 将其储存为"jklmn\n\0"，fputs() 打印该字符串。由于字符串中的"\n"，
            光标被移至下一行开始处。
        */
    }
    puts("Done.");

    return 0;
}