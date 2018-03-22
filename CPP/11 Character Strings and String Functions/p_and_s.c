/* p_and_s.c -- 指针和字符串 */
#include <stdio.h>
int main()
{
    const char *mesg = "Don't be a fool!";
    const char *copy;

    copy = mesg;
    printf("%s\n", copy);
    printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
    printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);

    /*
        Don't be a fool!
        mesg = Don't be a fool!; &mesg = 0x7fff55d93ad0; value = 0x109e6cf3e
        copy = Don't be a fool!; &copy = 0x7fff55d93ac8; value = 0x109e6cf3e

        你可能认为该程序拷贝了字符串"Don't be a fool!"。
        但是注意最后一项，两个指针的值是相同的，说明它们都指向同一个位置。
        因此，程序并未拷贝字符串。
        copy = mesg; 把 mesg 的值赋给 copy，即让 copy 也指向 mesg 指向的字符串。
    */

    return 0;
}