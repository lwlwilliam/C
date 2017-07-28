#include<stdio.h>

#include "max.h"
#include "min.h"

int main()
{
	int a, b, maxnum, minnum;
	a = 3;
	b = 5;
	maxnum = max(a, b);
	minnum = min(a, b);
	printf("max value is %d\nmin value is %d\n", maxnum, minnum);
	return 0;
}
