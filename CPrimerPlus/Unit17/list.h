/* list.h -- 简单链表类型的头文件 */
#ifndef LIST_H
#define LIST_H
#include <stdbool.h>  // C99 特性

// 特定程序的声明
#define TSIZE 45  // 储存电影名的数组大小

struct film
{
	char title[TSIZE];
	int rating;
};

// 一般类型定义
typedef struct film Item;

typedef struct node
{
	Item item;
	struct node *next;
} Node;

typedef Node *List;

// 函数原型

/* 操作：      初始化一个链表
 * 前提条件：  plist 指向一个链表
 * 后置条件：  链表初始化为空
 */
void InitializeList(List *plist);

/* 操作：      确定链表是否为空定义，plist 指向一个已初始化的链表
 * 后置条件：  如果链表为空，该函数返回 true；否则返回 false
 */
bool ListIsEmpty(const List *plist);

/* 操作：      确定链表是否已满，plist 指向一个已初始化的链表
 * 后置条件：  如果链表为空，该函数返回 true；否则返回 false
 */
bool ListIsFull(const List *plist);

/* 操作：      确定链表中的项数，plist 指向一个已初始化的链表
 * 后置条件：  该函数返回链表中的项数
 */
unsigned int ListItemCount(const List *plist);

/* 操作：      在链表的末尾添加项
 * 前提条件：  item 是一个待添加至链表的项，plist 指向一个已初始化的链表
 * 后置条件：  如果可以，该函数在链表末尾添加一个项，且返回 true；否则返回 false
 */
bool AddItem(Item item, List *plist);

