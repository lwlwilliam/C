// arrchar.c -- 指针数组，字符串数组
#include <stdio.h>
#define SLEN 40
#define LIM 5

int main()
{
    const char *mytalents[LIM] = {
        "Adding numbers swiftly",
        "Multiplying accurately",
        "Stashing data",
        "Following instructions to the letter",
        "Understanding the C language"
    };
    char yourtalents[LIM][SLEN] = {
        "Walking in a straight line",
        "Sleeping",
        "Watching television",
        "Mailing letters",
        "Reading email"
    };
    int i;

    puts("let's compare talents.");
    printf("%-40s %-40s\n", "My Talents", "Your Talents");
    for (i = 0; i < LIM; i ++) {
        printf("%-40s %-40s\n", mytalents[i], yourtalents[i]);
    }
    printf("\nsizeof mytalents: %zd, sizeof youtalents: %zd\n", sizeof mytalents, sizeof yourtalents);

    return 0;
}