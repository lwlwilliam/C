#include<stdio.h>
#include<stdlib.h>

struct Test
{
	int a;
	char b;
} test;

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

int main()
{
	int a;
	char b;
	printf("%d\n", sizeof(test));
	printf("%d\t%d\n", sizeof(a), sizeof(b));
	printf("%d\n", sizeof(LNode));
	printf("%d\n", sizeof(LinkList));
	return 0;
}
