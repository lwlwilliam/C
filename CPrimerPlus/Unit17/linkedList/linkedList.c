/* linkedList.c, 支持链表操作的函数 */
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/* 局部函数 */
static void CopyToNode(Item item, Node *pnode);

/* 接口函数 */

/* 初始化链表 */
void InitializeList(List *plist)
{
    *plist = NULL;
}

/* 确定链表是否为空 */
bool ListIsEmpty(const List *plist)
{
    if (*plist == NULL) {
        return true;
    } else {
        return false;
    }
}

/* 确定链表是否已满 */
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

/* 确定链表中的项数 */
unsigned int ListItemCount(const List *plist)
{
    unsigned int count = 0;
    Node *pnode = *plist;  /* 设置链表的开始 */

    while (pnode != NULL) {
        ++ count;
        pnode = pnode->next;
    }

    return count;
}

/* 在链表的末尾添加项 */
bool AddItem(Item item, List *plist)
{
    Node *pnew;
    Node *scan = *plist;

    pnew = (Node *) malloc(sizeof(Node));
    if (pnew == NULL) {
        return false;  /* 失败时退出函数 */
    }

    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (scan == NULL) {
        *plist = pnew;
    } else {
        while (scan->next != NULL) {
            scan = scan->next;
        }
        scan->next = pnew;
    }

    return true;
}

/* 访问每个节点并执行 pfun 指向的函数 */
void Traverse(const List *plist, void(*pfun)(Item item))
{
    Node *pnode = *plist;  /* 设置链表的开始 */

    while (pnode != NULL) {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

/* 释放已分配的内存 */
void EmptyTheList(List *plist)
{
    Node *psave;

    while (*plist != NULL) {
        psave = (*plist)->next;  /* 保存下一个节点的地址 */
        free(*plist);            /* 释放当前节点 */
        *plist = psave;          /* 前进至下一个节点 */
    }
}

/* 局部函数定义 */
/* 把一个项拷贝到节点中 */
static void CopyToNode(Item item, Node *pnode)
{
    pnode->item = item;
}
