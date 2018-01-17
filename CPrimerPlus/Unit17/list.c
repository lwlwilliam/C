/* ilst.c -- 支持链表操作的函数 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* 局部函数原型 */
static void CopyToNode(Item item, Node *pnode);

/* 接口函数 */
/* 把链表设置为空 */
void InitializeList(List *plist)
{
    *plist = NULL;
}

/* 如果链表为空，返回 true */
bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL) {
        return true;
    } else {
        return false;
    }
}

/* 如果链表已满，返回 true */
bool ListIsFull(const List *plist)
{
    Node *pt;
    bool full;

    pt = (Node *)malloc(sizeof(Node));
    if (pt == NULL) {
        full = true;
    } else {
        full = false;
    }
    free(pt);

    return full;
}
