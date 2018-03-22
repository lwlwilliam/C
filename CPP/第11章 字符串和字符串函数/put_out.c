/* put_out.c -- 使用 puts() */
#include <stdio.h>
#define DEF "I am a #defined string."
int main()
{
    char str1[80] = "An array was initialized to me.";
    const char *str2 = "A pointer was initialized to me.";

    puts("I'm an arguments to puts().");
    puts(DEF);
    puts(str1);
    puts(str2);
    puts(&str1[5]);
    puts(str2 + 4);

    return 0;
}