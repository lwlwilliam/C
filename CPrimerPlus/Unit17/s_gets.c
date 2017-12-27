#include <stdio.h>
#include <string.h>

// 从标准输入中获取定长字符
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');  // 判断定长字符串是否存在换行符
        if (find) {
            *find = '\0';  // 换行符替换为空字符
        } else {
            // 没有换行符，则把剩余部分去除
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}