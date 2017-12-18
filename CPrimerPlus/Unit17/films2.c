/* film2.c -- 使用结构链表 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film {
    char title[TSIZE];
    int rating;
    struct film *next;
};

char *s_gets(char *st, int n);

int main()
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];

    puts("Enter first movie title: ");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
        current = (struct film *) malloc(sizeof(struct film));  // 当前结构分配内存

        if (head == NULL)  // 处理第一个结构
            head = current;
        else  // 处理后续结构
            prev->next = current;  // 此时是新一轮环，将上一轮循环处理的结构的 next 指向当前结构

        current->next = NULL;  // 要指向的下一个结构未知
        strcpy(current->title, input);  // 当前结构 title
        puts("Enter your rating <1-10>: ");
        scanf("%d", &current->rating);  // 当前结构评分

        while (getchar() != '\n')
            continue;

        puts("Enter next movie title (empty line to stop): ");
        prev = current;  // 准备进入下一轮，把这一轮的结构赋给 prev 指针
    }

    /* 显示电影列表 */
    if (head == NULL)
        printf("No data entered.");
    else
        printf("Here is the movie list:\n");

    current = head;
    while (current != NULL) {
        printf("Movie: ％s Rating: %d\n", current->title, current->rating);
        current = current->next;
    }

    /* 完成任务，释放内存 */
    current = head;
    while (current != NULL) {
        current = head;
        head = current->next;
        free(current);
    }

    printf("Bye!\n");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');

        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
}