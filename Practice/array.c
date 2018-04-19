/*
 * 把 item 插入到 LA 数组索引为 k 的位置上
 */
#include <stdio.h>

int main() {
	int LA[] = {1, 3, 5, 7, 8};

	// 要插入的 item 为 10，位置为 3，数组元素个数为 5
	int item = 10, k = 3, n = 5;
	int i = 0, j = n;

	printf("The original array elements are: \n");

	// 原始数组索引元素关系
	for (i = 0; i < n; i ++) {
		printf("LA[%d] = %d\n", i, LA[i]);
	}

	n = n + 1;

	// 把 k 位置及之后的元素依次住后挪一个位置
	while (j >= k) {
		LA[j+1] = LA[j];
		j = j - 1;
	}

	LA[k] = item;

	printf("The array elements after insertion:\n");

	for (i = 0; i < n; i ++) {
		printf("LA[%d] = %d\n", i, LA[i]);
	}

	// 报错 out of range，呃，疑惑啊
	printf("%d\t%d\n", LA[4], LA[5]);

	return 0;
}
