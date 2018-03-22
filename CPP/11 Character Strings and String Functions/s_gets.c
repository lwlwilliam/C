char *s_gets(char *st, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {  // 即，ret_val != NULL
        while (st[i] != '\n' && st[i] != '\0') {
            i ++;
        }
        if (st[i] == '\n') {
            st[i] = '\0';
        } else {  // 如果字符串中出现空字符，就丢弃该输入行的其余字符，因为输入行中多出来的字符会被留在缓冲区中，成为下一次读取语句的输入。
            while (getchar() != '\n') {
                continue;
            }
        }
    }

    return ret_val;
}