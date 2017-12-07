/* mod_str.c -- 修改字符串 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81
void ToUpper(char *);
int PunctCount(const char *);

int main()
{
    char line[LIMIT];
    char *find;

    puts("Please enter a line:");
    fgets(line, LIMIT, stdin);
    find = strchr(line, '\n');  // 查找换行符
    if (find) {
        *find = '\0';
    }
    ToUpper(line);
    puts(line);
    printf("That line has %d punctuation characters.\n", PunctCount(line));

    return 0;
}

void ToUpper(char *str)
{
    // 循环处理 str 指向的字符串中的每个字符，直到遇到空字符。此时 *str 的值为 0（空字符的编码值为 0），
    // 即循环条件为假，循环结束。
    while (*str) {
        *str = toupper(*str);
        str ++;
    }
}

int PunctCount(const char *str)
{
    int ct = 0;
    while(*str) {
        if (ispunct(*str)) {
            ct ++;
        }
        str ++;
    }

    return ct;
}