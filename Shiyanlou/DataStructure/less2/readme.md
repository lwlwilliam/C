### 线性结构-线性表

数据结构中的逻辑结构分为**线性结构**和**非线性结构**。

线性结构是n个数据元素的有序（次序）集合，它有下列几个特征：
	1. 集合中必存在唯一的一个“第一个元素”；
	2. 集合中必存在唯一的一个“最后的元素”；
	3. 除最后元素之外，其它数据元素均有唯一的“后继”；
	4. 除第一元素之外，其它数据元素均有唯一的“前驱”；

线性结构中的线性表，是最常用且最简单的一种数据结构。线性表是一个含有n≥0个结点的有限序列，对于其中的结点，有且仅有一个开始结点没有前驱但有一个后继结点，有且仅有一个终端结点没有后继但有一个前驱结点，其它的结点都有且仅有一个前驱和一个后继结点。一般地，一个线性表可以表示成一个线性序列：k1，k2，…，kn，其中k1是开始结点，kn是终端结点。

一般线性表包含下列基本操作：初始化、销毁、重置为空表、判断是否为空、获取长度、根据位置获取对应元素、查找元素、获取指定元素的前驱和后继元素、插入元素、删除元素、遍历元素。


> 线性表的顺序表示和实现

线性表的顺序表示指的是用物理上的一段连续的地址来存储数据元素，如下图所示。如果第一个元素在内存上的地址为a1，每个元素占用的空间是l，那第n个元素的地址就是a1+(n-1)*l。

| 内存中存储地址 | 位置 |
| :--:           | :--: |
| a1             | 1    |
| a1 + l         | 2    |
| a1 + 2*l       | 3    |
| .              | .    |
| .              | .    |
| .              | .    |
| a1 + (n-1)*l   | n    |

只要确定了第一个元素的地址，那么我们可以对线性表中的任一元素随机存取，由于编程语言中的数组也有随机存取的特点，下面就用数组来描述线性表的顺序存储结构。

```
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INIT_SIZE 10 // 初始化表长
#define INCREMENT_SIZE 5 // 分配增量

typedef int Status;
typedef int Elemtype;

/**
 * 存储结构
 */

typedef struct
{
	Elemtype *elem; // 存储空间基址
	int length; // 当前长度
	int size; // 当前分配的表长大小
}SqList;

/**
 * 初始化一个空的线性表
 */
Status InitList(SqList *L)
{
	L->elem = (Elemtype *) malloc(INIT_SIZE * sizeof(Elemtype));
	if (!L->elem) {
		return ERROR;
	}
	L->length = 0;
	L->size = INIT_SIZE;
	return OK;
}

/**
 * 销毁线性表
 */
Status DestroyList(SqList *L)
{
	free(L->elem);
	L->length = 0;
	L->size = 0;
	return OK;
}

/**
 * 清空线性表
 */
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

/**
 * 判断线性线是否为空
 */
Status isEmpty(const SqList L)
{
	if (0 == L.length) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
 * 获取长度
 */
Status getLength(const SqList L)
{
	return L.length;
}

/**
 * 根据位置获取元素
 */
Status GetElem(const SqList, int i, Elemtype *e)
{
	if (i < 1 || i > L.length) {
		return ERROR;
	}
	*e = L.elem[i-1];
	return OK;
}

/**
 * 比较两个元素是否相等
 */
Status compare(Elemtype e1, Elemtype e2)
{
	if (e1 == e2) {
		return 0;
	} else if (e1 < e2) {
		return -1;
	} else {
		return 1;
	}
}

/**
 * 查找元素
 */
Status FindElem(const SqList L, Elemtype e, Status (*compare)(Elemtype, Elemtype))
{
	int i;
	for (i = 0; i < L.length; i ++) {
		if (!(*compare)(L.elem[i], e)) {
			return i + 1;
		}
	}

	if (i >= L.length) {
		return ERROR;
	}
}

/**
 * 查找前驱元素
 */
Status PreElem(const SqList L, Elemtype cur_e, Elemtype *pre_e)
{
	int i;
	for (i = 0; i < L.length; i ++) {
		if (cur_e == L.elem[i]) {
			if (i != 0) {
				*pre_e = L.elem[i-1];
			} else {
				return ERROR;
			}
		}
	}

	if (i >= L.length) {
		return ERROR;
	}
}

/**
 * 查找后继元素
 */
Status NextElem(const SqList L, Elemtype cur_e, Elemtype *next_e)
{
	int i;
	for (i = 0; i < L.length; i ++) {
		if (cur_e == L.length; i ++) {
			if (i < L.length - 1) {
				*next_e = L.elem[i+1];
				return OK
			} else {
				return ERROR;
			}
		}
	}

	if (i >= L.length) {
		return ERROR;
	}
}

/**
 * 插入元素
 */
Status InsertElem(SqList *L, int i, Elemtype e)
{
	Elemtype *new;
	if (i < 1 || i > L->length + 1) {
		return ERROR;
	}
	if (L->length >= L->size) {
		new = (Elemtype*) realloc(L->elem, (L->size + INCREMENT_SIZE) * sizeof(Elemtype));
		if (!new) {
			return ERROR;
		}
		L->elem = new;
		L->size += INCREMENT_SIZE;
	}
	Elemtype *p = &L->elem[i-1];
	Elemtype *q = &L->elem[L-length-1];
	for (; q >= p; q--) {
		*(q+1) = *q;
	}
	*p = e;
	++L->length;
	return OK;
}

/**
 * 删除元素并返回其值
 */
Status DeleteElem(SqList *L, int i, Elemtype *e)
{
	if (i < 1 || i > L->length) {
		return ERROR;
	}
	Elemtype *p = &L->elem[i-1];
	*e = *p;
	for (; p < &L->elem[L->length]; p ++) {
		*(p) = *(p+1);
	}
	--L->length;
	return OK;
}

/**
 * 访问元素
 */
void visit(Elemtype e)
{
	printf("%d", e);
}

/**
 * 遍历线性表
 */
Status TraverseList(const SqList, void(*visit)(Elemtype)
{
	int i;
	for (i = 0; i < L.lenght; i ++) {
		visit(L.elem[i]);
	}
	return OK;
}

/**
 *	主函数测试
 */
int main()
{
	SqList L;
	if (InitList(&L)) {
		Elemtype e;
		printf("init_success\n");
		int i;
		for (i = 0; i < 10; i ++) {
			InsertElem(&L, i + 1, i);
		}
		printf("length is %d\n", getLength(L));
		if (GetElem(L, 1 &e)) {
			printf("The first element is %d\n", e);
		} else {
			printf("element is not exist\n");
		}
		if (isEmpty(L)) {
			printf("list is empty\n");
		} else {
			printf("list is not empty\n");
		}
		printf("The 5 at %d\n", FindElem(L, 5, *compare));
		PreElem(L, 6, &e);
		printf("The 6's previous element is %d\n", e);
		NextElem(L, 6, &e);
		printf("The 6's next element is %d\n", e);
		DeleteElem(&L, 1, &e);
		printf("delete first element is %d\n", e);
		printf("list: ");
		TraverseList(L, visit);
		if (DestroyList(&L)) {
			printf("\ndestroy_success\n");
		}
	}
}


```
