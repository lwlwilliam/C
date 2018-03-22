/* queue.c, Queue 类型的实现 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* 局部函数 */
static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);

/* 初始化队列 */
void InitializeQueue(Queue *pq)
{
    pq->front = pq->rear = NULL;
    pq->items = 0;
}

/* 检查队列是否已满 */
bool QueueIsFull(const Queue *pq)
{
    return pq->items == MAXQUEUE;
}

/* 检查队列是否为空 */
bool QueueIsEmpty(const Queue *pq)
{
    return pq->items == 0;
}

/* 确定队列中的项数 */
int QueueItemCount(const Queue *pq)
{
    return pq->items;
}

/* 在队列末尾添加项 */
bool EnQueue(Item item, Queue *pq)
{
    Node *pnew;

    if (QueueIsFull(pq)) {
        return false;
    }
    pnew = (Node *)malloc(sizeof(Node));
    if (pnew == NULL) {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(1);
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (QueueIsEmpty(pq)) {
        pq->front = pnew;        /* 项位于队列的首端 */
    } else {
        pq->rear->next = pnew;   /* 链表到队列的尾端 */
    }
    pq->rear = pnew;             /* 记录队列尾端的位置 */
    pq->items ++;                /* 队列基数加 1 */

    return true;
}

/* 从队列的开头删除项 */
bool DeQueue(Item *pitem, Queue *pq)
{
    Node *pt;

    if (QueueIsEmpty(pq)) {
        return false;
    }
    CopyToItem(pq->front, pitem);
    pt = pq->front;
    pq->front = pq->front->next;
    free(pt);
    pq->items --;
    if (pq->items == 0) {
        pq->rear = NULL;
    }

    return true;
}

/* 清空队列 */
void EmptyTheQueue(Queue *pq)
{
    Item dummy;

    while (!QueueIsEmpty(pq)) {
        DeQueue(&dummy, pq);
    }
}

/* 局部函数 */
static void CopyToNode(Item item, Node *pn)
{
    pn->item = item;
}

static void CopyToItem(Node *pn, Item *pi)
{
    *pi = pn->item;
}
