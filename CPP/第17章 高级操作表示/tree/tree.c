/* tree.c, 树的支持函数 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* 局部数据类型 */
typedef struct pair {
    Trnode *parent;
    Trnode *child;
} Pair;

/* 局部函数的原型 */
static Trnode *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(const Trnode *root, void(*pfun) (Item item));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);

/* 函数定义 */
void InitializeTree(Tree *ptree)
{
    ptree->root = NULL
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
    if (ptree->root == NULL) {
        return true;
    } else {
        return false;
    }
}

bool TreeIsFull(const Tree *ptree)
{
    if (ptree->size == MAXITEMS) {
        return true;
    } else {
        return false;
    }
}

int TreeItemCount(const Tree *ptree)
{
    return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
    Trnode *new_node;

    if (TreeIsFull(ptree)) {
        fprintf(stderr, "Tree is full\n");
        return false;
    }

    if (SeekItem(pi, ptree).child != NULL) {
        fprintf(stderr, "Attempted to add duplicate item\n");
        return false;
    }

    new_node = MakeNode(pi);    /* 指向新节点 */

    if (new_node == NULL) {
        fprintf(stderr, "Couldn't create node\n");
        return false;
    }

    /* 成功创建了一个新节点 */
    ptree->size ++;

    if (ptree->root == NULL) {
        ptree->root = new_node;
    } else {
        AddNode(new_node, ptree->root);     /* 在树中添加新节点 */
    }
    return true;
}

bool InTree(const Item *pi, const Tree *ptree)
{
    return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
    Pair look;

    look = SeekItem(pi, ptree);
    if (look.child == NULL) {
        return false;
    }

    if (look.parent == NULL) {
        DeleteNode(&ptree->root);
    } else if (look.parent->left == look.child) {
        DeleteNode(&look.parent->left);
    } else {
        DeleteNode(&look.parent->right);
    }

    ptree->size --;

    return true;
}















/* 创建新节点 */
static Trnode *MakeNode(const Item *pi)
{
    Trnode *new_node;
    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL) {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

/* 往 tree 中插入新节点 */
static void AddNode(Trnode *new_node, Trnode *root)
{
    if (ToLeft(&new_node->item, &root->item)) {
        if (root->left == NULL) {   /* 空子树 */
            root->left = new_node;
        } else {
            AddNode(new_node, root->left);
        }
    } else if (ToRight(&new_node->item, &root->item)) {
        if (root->right == NULL) {
            root->right = new_node;
        } else {
            AddNode(new_ndoe, root->right);
        }
    } else {
        fprintf(stderr, "location error in AddNode()\n");
        exit(1);
    }
}

/* 新 Item 是否应该位于目标 Item 的左侧 */
static bool ToLeft(const Item *i1, const Item *i2)
{
    int comp1;
    if ((comp1 = strcmp(i1->petname, i2->petname)) < 0) {
        return true;
    } else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0) {
        return true;
    } else {
        return false;
    }
}

/* 新 Item 是否应该位于目标 Item 的右侧 */
static bool ToRight(const Item *i1, const Item *i2)
{
    int comp1;

    if ((comp1 = strcmp(i1->petname, i2->petname)) > 0) {
        return true;
    } else if (comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0) {
        return true;
    } else {
        return false;
    }
}

/* 创建节点 */
static Trnode *MakeNode(const Item *pi)
{
    Trnode *new_node;

    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL) {
        new_node->item = *pi;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

/* 在 tree 中查找 Item，返回的结果是 Pair 类型，Pari 类型通过 parent 指针 和 child 指针定位该 Item 位置 */
static Pair SeekItem(const Item *pi, const Tree *ptree)
{
    Pair look;
    look.parent = NULL;
    look.child = ptree->root;

    if (look.child == NULL) {
        return look;
    }

    while (look.child != NULL) {
        if (ToLeft(pi, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->left;
        } else if (ToRight(pi, &(look.child->item))) {
            look.parent = look.child;
            look.child = look.child->right;
        } else {    /* 如果前两种情况都不满足，则必定是相待的情况 */
            break;  /* look.child 目标项的节点 */
        }
    }

    return look;
}

/* 删除节点，ptr 是指向目标节点的父节点指针成员的地址 */
static void DeleteNode(Trnode **ptr)
{
    Trnode *temp;

    if ((*ptr)->left == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    } else if ((*ptr)->right == NULL) {
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    } else {    /* 被删除的节点有两个子节点 */
        /* 找到重新连接右子树的位置 */
        for (temp = (*ptr)->left; temp->right != NULL; temp = right)
    }
}