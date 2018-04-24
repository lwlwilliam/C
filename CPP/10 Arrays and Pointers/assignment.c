/* 给数组的元素赋值 */
#include <stdio.h>
#define SIZE 50
int main()
{
	int counter, evens[SIZE], i;

	for (counter = 0; counter < SIZE; counter ++) {
		evens[counter] = 2 * counter;	
	}

	for (i = 0; i < SIZE; i ++) {
		printf("evens[%d] = %d\n", i, evens[i]);
	}

	return 0;
}

