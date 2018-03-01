/* 要与 linkedList.c 一起编译 */
#include <stdio.h>
#include <stdlib.h>  /* 提供 exit() 的原型 */
#include "linkedList.h"    /* 定义 List、Item */
void showmovies(Item item);
char *s_gets(char *st, int n);

int main()
{
    List movies;
    Item temp;

    /* 初始化 */
    InitializeList(&movies);
    if (ListIsFull(&movies)) {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }

    /* 获取用户输入并储存 */
    puts("Enter first movie title: ");
    while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
        puts("Enter your rating <0-10>: ");
        scanf("%d", &temp.rating);
        while (getchar() != '\n') {
            continue;
        }
        if (AddItem(temp, &moview) == false) {
            fprintf(stderr, "Problem allocating memory\n");
            break;
        }
        if (ListIsFull(&movies)) {
            puts("The list is now full.");
            break;
        }
        puts("Enter next movie title (empty line to stop): ");
    }

    /* 显示 */
    if (ListIsEmpty(&movies)) {
        printf("No data entered.");
    } else {
        printf("Here is the movie list:\n");
        Traverse(&moview, showmovies);
    }
    printf("You entered %d movies.\n", ListItemCount(&movies));

    /* 清理 */
    EmptyTheList(&movies);
    printf("Bye!\n");

    return 0;
}

void showmovies(Item item)
{
    printf("Movie: %s Rating: %d\n", item.title, item.rating);
}

/* 获取指定字节输入 */
char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin)
    if (ret_val) {
        find = strchr(st, '\n');  // 查找换行符
        if (find) {               // 如果地址不是 NULL
            *find = '\0';         // 在此处放置一个空字符
        } else {
            while (getchar() != '\n') {
                continue;         // 处理输入行的剩余内容
            }
        }
    }
    return ret_val;
}
