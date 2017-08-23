#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVEERFLOW -2

typedef int ElemType;
typedef int Status;

/*
 * 存储结构
 */
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

/*
 * 初始化线性表
 */
void InitList(LinkList *L)
{
	*L = (LinkList) malloc(sizeof(LNode));
	if (!L) {
		exit(OVERFLOW);
	}
	(*L)->next = NULL;
}

/*
 * 销毁线性表
 */
void DestroyList(LinkList *L)
{
	LinkList temp;
	while (*L) {
		temp = (*L)->next;
		free(*L);
		*L = temp;
	}
}

/*
 * 清空线性表
 */
void ClearList(LinkList L)
{
	LinkList p = L->next;
	L->next = NULL;
	DestroyList(&p);
}

/*
 * 判断是否为空
 */
Status is Empty(LinkList L)
{
	if (L->next) {
		return FALSE;
	} else {
		return TRUE;
	}
}
