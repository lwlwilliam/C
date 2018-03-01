/* tree.h, 二叉查找树 */
/* 树中不允许有重复的项 */
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

/* 根据具体情况重新定义 Item */
#define SLEN 20
typedef struct item
{
    petname[SLEN];
    petkind[SLEN];
} Item;

#define MAXITEMS 10

typedef struct trnode
{
    Item item;
    struct trnode *left;    /* 指向左分支的指针 */
    struct trnode *right;   /* 指向右分支的指针 */
} Trnode;

typedef struct tree
{
    Trndoe *root;   /* 指向根节点的指针 */
    int size;
} Tree;

/* 函数原型 */

/*
操作： 把树初始化为空
前提条件：ptree 指向一个树
后置条件：树被初始化为空
*/
void InitializeTree(Tree *ptree);
