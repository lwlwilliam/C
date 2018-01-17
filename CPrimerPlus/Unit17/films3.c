/* films3.c -- 使用抽象数据类型(ADT)风格的链表 */
/* 与 list.c 一起编译 */
#include <stdio.h>
#include <stdlib.h>  // 提供 exit() 的原型
#include "list.h"    // 定义 List、Item
void showmovies(Item item);
char *s_gets(char *st, int n);

int main()
{
    List movies;
    Item temp;

    /* 初始化 */
    InitializeList(&movie);
    if (ListIsFull(&moview)) {
        fprintf(stderr, "No memory available! Bye!\n");
        exit(1);
    }

    /* 获取脾户输入并储存 */
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
    if (ListIsEmpty(&moview)) {
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